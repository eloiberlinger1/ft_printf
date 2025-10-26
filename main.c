#include "ft_printf.h"

int main()
{
    printf("\nft_printf :\n");
    ft_printf("0000%i0000", -5185165);
    printf("\n\nprintf :\n");
    printf("0000%i0000", -5185165);
    printf("\n\n");

    return 1;
}