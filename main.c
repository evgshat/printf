#include "ft_printf.h"

int	main(void)
{
	int	i;

	i = 0;
	i = ft_printf("%3i, %3d", 8, -12);
	printf("\n%d", i);
}
// ("%3i, %3d, %3d", 8, -12, 123);
// i = ft_printf("%3i, %3d, %3d, %3d, %3d, %3d, %3d, %3d", 8, -12, 123456789,   0, -12345678,  97, -2147483648, 2147483647);