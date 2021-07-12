#include "ft_printf.h"

int	main(void)
{
	int	my;
	int	or;

	my = ft_printf("%09.0d", UINT_MAX + 1);
	write (1, "\n", 1);
	or = printf("%09.0d", UINT_MAX + 1);
	printf("\nmy = %d", my);
	printf("\nor = %d", or);
}
