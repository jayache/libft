#include "libft.h"

/*
** USED FOR HASHTABLE
*/

t_hashnode  *ft_hashnode_new(char *index, void *val)
{
    t_hashnode  *node;

    node = (t_hashnode*)malloc(sizeof(t_hashnode));
    node->key = index;
    node->content = val;
    return (node);
}
