#include "ft_printf.h"

int	main(void)
{
	int	my;
	int	or;

	my = ft_printf("ccccc");
	or = printf("\nccccc");
	printf("\nmy = %d", my);
	printf("\nor = %d", or);
}
