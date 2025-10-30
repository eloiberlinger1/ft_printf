#include "ft_printf.h"

int	main(void)
{
	int i = 0;
	char test = '0';

	printf("\nft_printf :\n");
	ft_printf("%c", test);

	printf("\n\nprintf :\n");
	printf("%c", test);
	printf("\n\n");

	return (1);
}