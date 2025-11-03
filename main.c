#include "ft_printf.h"

int	main(void)
{
	int i = 0;
	int	test = -5;

	int y = printf("\n");
	printf("%u\n", test);

	int x = ft_printf("%u\n", test);
	printf("%u\n", test);
	// printf("\n\nprintf :\n");
	// printf("%c", test);
	// printf("\n\n");

	return (1);
}