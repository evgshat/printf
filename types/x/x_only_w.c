#include "../../ft_printf.h"

static int	x_w_over(t_flags flags, int size, unsigned long long chislo)
{
	int	sum_x;

	sum_x = 0;
	sum_x += over_width_zero(flags.val_w, size);
	from_d_to_x(chislo);
	return (sum_x);
}

static int	x_w_over_two(t_flags flags, int size, unsigned long long chislo)
{
	int	sum_x;

	sum_x = 0;
	if (flags.fl_m == 0 && flags.fl_z == 0)
	{
		sum_x += over_width(flags.val_w, size);
		from_d_to_x(chislo);
	}
	if (flags.fl_m != 0 && flags.fl_z != 0)
	{
		from_d_to_x(chislo);
		sum_x += over_width(flags.val_w, size);
	}
	return (sum_x);
}

int	x_only_w(t_flags flags, unsigned long long chislo, int size)
{
	int	sum_x;

	sum_x = 0;
	if (flags.fl_w != 0 && flags.fl_p == 0)
	{
		if (size >= flags.val_w)
			from_d_to_x(chislo);
		if (size < flags.val_w)
		{
			if (flags.fl_z != 0 && flags.fl_m == 0)
				sum_x += x_w_over(flags, size, chislo);
			if (flags.fl_m != 0 && flags.fl_z == 0)
			{
				from_d_to_x(chislo);
				sum_x += over_width(flags.val_w, size);
			}
			sum_x += x_w_over_two(flags, size, chislo);
		}
	}
	return (sum_x);
}
