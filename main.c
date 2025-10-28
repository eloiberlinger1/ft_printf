#include "ft_printf.h"

int	main(void)
{
	void *test;
	int test1;
	char *str = NULL;
    int i = 0;

    while(i++ != 500)
        test++;

	printf("\nft_printf :\n");
	ft_printf(str, NULL);
	ft_printf("qqqqqqq%pqqqqqqqq", test);

	printf("\n\nprintf :\n");
	printf(str, NULL);
	printf("qqqqqqq%pqqqqqqqq", test);
	printf("\n\n");

	return (1);
}
