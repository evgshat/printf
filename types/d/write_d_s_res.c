#include "../../ft_printf.h"

int	write_d_s_res(char *s_res, int size)
{
	int	sum_d;

	sum_d = 0;
	write (1, s_res, size);
	sum_d = sum(size);
	return (sum_d);
}