
#include "libft.h"

void    ft_lstdelbyval(t_list **lst, void *data, int (*cmp)(), void (*del)())
{
    t_list *prev;
    t_list *current;

    current = *lst;
    prev = NULL;
    while (current)
    {
        if (!cmp(current->content, data))
        {
            if (prev)
                prev->next = current->next;
            else
                *lst = current->next;
            ft_lstdelone(&current, del);
            return ;
        }
        prev = current;
        current = current->next;
    }
}
