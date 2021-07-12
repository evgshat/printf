#include "../../ft_printf.h"

int	from_d_to_p(unsigned long long chislo)
{
	int	sum_d_to_p;

	sum_d_to_p = 2;
	write (1, "0x", 2);
	from_d_to_x(chislo);
	return (sum_d_to_p);
}
