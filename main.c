#include "ft_printf.h"

int	main(void)
{
	int	my;
	int	or;

	my = ft_printf("%9.10u", UINT_MAX);
	write (1, "\n", 1);
	or = printf("%9.10u", UINT_MAX);
	printf("\nmy = %d", my);
	printf("\nor = %d", or);
}
