#include "libft.h"

/*
** RETURN ELEMENT AT INDEX N, OR TABLE DEFAULT IF NOTHING IS FOUND
*/

void    *ft_hashtable_search(t_hashtable *table, const char *index)
{
    size_t  key;
    t_list  *current;

    key = ft_hashtable_hash(index) % table->size;
    current = table->content[key];
    while (current)
    {
        if (!ft_strcmp(((t_hashnode*)current->content)->key, index))
            return (((t_hashnode*)current->content)->content);
        current = current->next;
    }
    return (table->def);
}
