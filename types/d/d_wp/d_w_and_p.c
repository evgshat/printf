#include "../../../ft_printf.h"

int	d_w_and_p(t_flags flags, int size, char *s_res)
{
	int	sum_d;

	sum_d = 0;
	if (flags.fl_w != 0 && flags.fl_p != 0)
	{
		if (*s_res != '-')
			sum_d += d_posit(flags, size, s_res);
		if (*s_res == '-')
			sum_d += d_negat(flags, size, s_res);
	}
	return (sum_d);
}
