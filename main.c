#include "ft_printf.h"

int	main(void)
{
	int	my;
	// int	original;

	my = ft_printf("%32s", NULL);
	write (1, "\n", 1);
	// original = printf("%32s", NULL);
	printf("\nmy = %d", my);
	// printf("\noriginal = %d", original);
}
// ("%3i, %3d, %3d", 8, -12, 123);
// i = ft_printf("%3i, %3d, %3d, %3d, %3d, %3d, %3d, %3d", 8, -12, 123456789,   0, -12345678,  97, -2147483648, 2147483647);