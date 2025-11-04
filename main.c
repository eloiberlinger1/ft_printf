#include "ft_printf.h"
#include <stdio.h> // for comparison
int main(void)
{
    int             my_count;
    int             printf_count;
    char            c;
    char            *str;
    int             num;
    unsigned int    unsigned_num;
    void            *ptr;
    c = 'T';
    str = "It's not a bug, it's a feature";
    num = -3456;
    unsigned_num = -99898;
    ptr = &num;
    my_count = ft_printf("ssdfsdf%\t", num);
    printf_count = printf("ssdfsdf%\t", num);
    printf("my: %d | pr: %d\n\n", my_count, printf_count);

    // printf("returnvalue ft_printf: %d | printf: %d\n\n", my_count, printf_count);
    // printf("%%s\n");
    // my_count = ft_printf("ft_printf: [%s]\n", str);
    // printf_count = printf("printf   : [%s]\n", str);
    // printf("returnvalue ft_printf: %d | printf: %d\n\n", my_count, printf_count);
    // printf("%%d %%i\n");
    // my_count = ft_printf("ft_printf: [%d] [%i]\n", num, num);
    // printf_count = printf("printf   : [%d] [%i]\n", num, num);
    // printf("returnvalue ft_printf: %d | printf: %d\n\n", my_count, printf_count);
    // printf("%%u\n");
    // my_count = ft_printf("ft_printf: [%u]\n", unsigned_num);
    // printf_count = printf("printf   : [%u]\n", unsigned_num);
    // printf("returnvalue ft_printf: %d | printf: %d\n\n", my_count, printf_count);
    // printf("%%x / %%X\n");
    // my_count = ft_printf("ft_printf: [%x] [%X]\n", unsigned_num, unsigned_num);
    // printf_count = printf("printf   : [%x] [%X]\n", unsigned_num, unsigned_num);
    // printf("returnvalue ft_printf: %d | printf: %d\n\n", my_count, printf_count);
    // printf("%%p\n");
    // my_count = ft_printf("ft_printf: [%p]\n", ptr);
    // printf_count = printf("printf   : [%p]\n", ptr);
    // printf("returnvalue ft_printf: %d | printf: %d\n\n", my_count, printf_count);
    // printf("%%\n");
    // my_count = ft_printf("ft_printf: [%%]\n");
    // printf_count = printf("printf   : [%%]\n");
    // printf("returnvalue ft_printf: %d | printf: %d\n\n", my_count, printf_count);
    // printf("mixed\n");
    // my_count = ft_printf("ft_printf: [%% %s%d%s soup]\n", "hi", 123, "onion");
    // printf_count = printf("printf   : [%% %s%d%s soup]\n", "hi", 123, "onion");
    // printf("returnvalue ft_printf: %d | printf: %d\n\n", my_count, printf_count);
    return (0);
}