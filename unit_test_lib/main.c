#include "test.h"

int assert_equals(const char *str, const char *str2)
{
    return (!strcmp(str, str2));
}

void print_result(int result)
{
    if (result)
        printf("[OK!]");
    else
        printf("[!KO]");
}

int main(int ac, char **av)
{
    
}
