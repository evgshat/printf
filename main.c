#include "ft_printf.h"

int	main(void)
{
	int	my;
	int	original;

	my = ft_printf("%0i, %0d, %0d, %0d, %0d, %0d, %0d, %0d", 8, -12, 123456789, 0, -12345678, 97, -2147483648, 2147483647); //4398434952
	write (1, "\n", 1);
	original = printf("%0i, %0d, %0d, %0d, %0d, %0d, %0d, %0d", 8, -12, 123456789, 0, -12345678, 97, -2147483648, 2147483647);
	printf("\nmy = %d", my);
	printf("\noriginal = %d", original);
}
// ("%3i, %3d, %3d", 8, -12, 123);
// i = ft_printf("%3i, %3d, %3d, %3d, %3d, %3d, %3d, %3d", 8, -12, 123456789,   0, -12345678,  97, -2147483648, 2147483647);