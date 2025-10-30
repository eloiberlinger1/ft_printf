#include "ft_printf.h"

int	main(void)
{
	int i = 0;
	char test = '0';

	int y = printf("asdasdasd\n");
	printf("%d\n", y);

	int x = ft_printf("%c", test);
	printf("%d\n", x);
	// printf("\n\nprintf :\n");
	// printf("%c", test);
	// printf("\n\n");

	return (1);
}