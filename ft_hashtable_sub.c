#include "libft.h"

/*
** REMOVE ONE ENTRY
*/

void    ft_hashtable_sub(t_hashtable *table, const char *index)
{
    size_t      key;
    t_list      *current;
    t_list      *last;
    t_hashnode  *node;

    key = ft_hashtable_hash(index) % table->size;
    current = table->content[key];
    last = NULL;
    while (current)
    {
        node = current->content;
        if (!ft_strcmp(node->key, index))
        {
            free(node->key);
            free(node);
            if (last)
                last->next = current->next;
            else
                table->content[key] = current->next;
            free(current);
        }
        last = current;
        current = current->next;
    }
}
