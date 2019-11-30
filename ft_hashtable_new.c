#include "libft.h"

t_hashtable *ft_hashtable_new(size_t size)
{
    t_hashtable *table;

    table = (t_hashtable*)malloc(sizeof(t_hashtable));
    table->size = size;
    table->content = (t_list**)ft_memalloc(size * sizeof(t_list*));
    return (table);
}
