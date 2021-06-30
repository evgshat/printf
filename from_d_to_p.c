#include "ft_printf.h"

int	from_d_to_p(int chislo)
{
	int	sum_d_to_p;

	sum_d_to_p = 2;
	write (1, "0", 1);
	write (1, "x", 1);
	sum_d_to_p = sum_d_to_p + from_d_to_x(chislo);
	return (sum_d_to_p);
}