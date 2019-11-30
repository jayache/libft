#include "libft.h"
#include <stdio.h>

void print_lst(t_list *lst)
{
    while (lst)
    {
        printf("[%s]", (char*)lst->content);
        if (lst->next)
            printf("->");
        lst = lst->next;
    }
    printf("\n");
}

void free_info(void *ptr, size_t size)
{
    free(ptr);
    size = 0;
    return ;
    printf("%ld", size);
}

void    test_ft_lst_new()
{
    t_list *lst;
    
    printf("Test ft_lst_new:\n");
    lst = ft_lstnew("Hello World", sizeof("Hello World"));
    lst->next = ft_lstnew(ft_strdup("Ho, hi !"), sizeof("Ho, hi !"));
    print_lst(lst);
}

void    test_ft_lst_del_one()
{
    t_list *lst;

    printf("Test ft_lst_del_one\n");
    lst = ft_lstnew("Hello World", sizeof("Hello World"));
    lst->next = ft_lstnew(ft_strdup("Ho, hi !"), sizeof("Ho, hi !"));
    ft_lstdelone(&lst->next, free_info);
    print_lst(lst);
    ft_lstdelone(&lst, free_info);
    print_lst(lst);
}

void    test_ft_lst_append()
{
    t_list *lst; 
    
    printf("Test ft_lst_append\n");
    lst = NULL;
    ft_lst_append(&lst, ft_lstnew("One", 4));
    ft_lst_append(&lst, ft_lstnew("Two", 4));
    ft_lst_append(&lst, ft_lstnew("Three", 6));
    ft_lst_append(&lst, ft_lstnew("Four", 5));
    print_lst(lst);
}

void    test_ft_lst_add()
{
    t_list *lst; 
    
    printf("Test ft_lst_add\n");
    lst = NULL;
    ft_lstadd(&lst, ft_lstnew("One", 4));
    ft_lstadd(&lst, ft_lstnew("Two", 4));
    ft_lstadd(&lst, ft_lstnew("Three", 6));
    ft_lstadd(&lst, ft_lstnew("Four", 5));
    print_lst(lst);
}

void    test_ft_lst_sorted_insert()
{
    t_list *lst; 
    
    printf("Test ft_lst_sorted_insert\n");
    lst = NULL;
    ft_lst_sorted_insert(&lst, ft_lstnew("A", 2), strcmp);
    print_lst(lst);
    ft_lst_sorted_insert(&lst, ft_lstnew("B", 2), strcmp);
    print_lst(lst);
    ft_lst_sorted_insert(&lst, ft_lstnew("Z", 2), strcmp);
    print_lst(lst);
    ft_lst_sorted_insert(&lst, ft_lstnew("E", 2), strcmp);
    print_lst(lst);
}

void    test_ft_lst_new_no_copy()
{
    t_list *lst; 
    
    printf("Test ft_lst_new_no_copy:\n");
    lst = ft_lstnew_no_copy("Hello World", sizeof("Hello World"));
    lst->next = ft_lstnew_no_copy(ft_strdup("Ho, hi !"), sizeof("Ho, hi !"));
    print_lst(lst);

}

int main()
{
    test_ft_lst_new();
    test_ft_lst_del_one();
    test_ft_lst_append();
    test_ft_lst_add();
    test_ft_lst_sorted_insert();
    test_ft_lst_new_no_copy();
}
