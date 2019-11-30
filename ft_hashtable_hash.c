
#include "libft.h"

/*
** GENERATE A KEY FROM A STRING
*/

size_t  ft_hashtable_hash(const char *key)
{
    size_t  asciisum;
    int     i;

    i = 0;
    asciisum = 0;
    while (key[i])
    {
        asciisum += (key[i] * i);
        ++i;
    }
    return (asciisum %= 599);
}
