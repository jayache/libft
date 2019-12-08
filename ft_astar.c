#include "libft.h"

static void free_p(void *p, size_t size)
{
    free(p);
    if (p)
        if (size)
            return ;
}

static void **reconstruct_path(t_hashtable *camefrom, t_algo_input *algo,
        void *goal)
{
    void    **path;
    size_t  path_length;
    void    *current;
    size_t  i;
    void    *last;

    path_length = 1;
    current = goal;
    while ((current = ft_hashtable_search(camefrom, algo->serialize(current))))
        path_length++;
    path = (void**)ft_memalloc((path_length + 1) * sizeof(void*));
    i = 1;
    current = goal;
    path[0] = goal;
    last = goal;
    while ((current = ft_hashtable_search(camefrom, algo->serialize(current))))
    {
        path[i] = current;
        ft_hashtable_sub(camefrom, algo->serialize(last));
        ++i;
        last = current;
    }
    return (path);
}

static void *astar_loop(t_hashtable *gscore, t_hashtable *fscore,
        t_hashtable *camefrom, t_list **openset, t_algo_input *algo)
{
    size_t  i;
    void    *current;
    void    **neighbors;
    t_list  *save;
    size_t  tg;

    i = 0;
    current = (*openset)->content;
    if (!algo->goal_p && algo->goal_f(current))
        return (current);
    else if (algo->goal_p && !algo->cmp(current, algo->goal_p))
        return (current);
    neighbors = algo->neighbors(current);
    while (neighbors[i])
    {
        tg = (size_t)ft_hashtable_search(gscore, algo->serialize(current)) + 1;
        if (tg < (size_t)ft_hashtable_search(gscore, algo->serialize(neighbors[i])))
        {
            ft_hashtable_add(camefrom, algo->serialize(neighbors[i]),
                    ft_strdup(current));
            ft_hashtable_add(gscore, algo->serialize(neighbors[i]), (void*)tg);
            ft_hashtable_add(fscore, algo->serialize(neighbors[i]),
                    (void*)(tg + algo->heuristic(neighbors[i])));
            if (!ft_lst_exist(*openset, neighbors[i], algo->cmp))
                ft_lst_append(openset, ft_lstnew_no_copy(ft_strdup(neighbors[i]), sizeof(void*)));
        }
        free(neighbors[i]);
        ++i;
    }
    free(neighbors);
    save = (*openset)->next;
    ft_lstdelone(openset, free_p);
    *openset = save;
    return (0);
}


void        **ft_astar(void *start, t_algo_input *algo)
{
    t_hashtable *camefrom;
    t_hashtable *gscore;
    t_hashtable *fscore;
    t_list      *openset;
    void        **path;

    openset = ft_lstnew_no_copy(start, sizeof(start));
    camefrom = ft_hashtable_new(10000);
    gscore = ft_hashtable_new(10000);
    gscore->def = (void*)-1;
    fscore = ft_hashtable_new(10000);
    fscore->def = (void*)-1;
    camefrom->def = 0;
    ft_hashtable_add(gscore, algo->serialize(start),
            (void*)algo->heuristic(start));
    while (openset)
    {
        if ((path = astar_loop(gscore, fscore, camefrom, &openset, algo)))
        {
            path = reconstruct_path(camefrom, algo, path);
            ft_hashtable_clean(camefrom);
            ft_hashtable_free(gscore);
            ft_hashtable_free(fscore);
            ft_lstdel(&(openset->next), free_p);
            free(openset);
            return (path);
        }
    }
    return (0);
}
