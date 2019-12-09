#include "libft.h"

size_t  ft_hashtable_size(t_hashtable *table)
{
   size_t   i;
   size_t   size;

   i = 0;
   size = 0;
   while (i < table->size)
   {
        size += ft_lst_size(table->content[i]);
        ++i;
   }
    return (size);
}
