#include "../../ft_printf.h"

static int	minus(t_flags flags, int size, unsigned long long chislo)
{
	int	sum_x;

	sum_x = 0;
	if (flags.val_p == 0 && chislo == 0)
	{
		sum_x += over_width(flags.val_w, 0);
		sum_x--;
	}
	else
	{
		from_d_to_x(chislo);
		sum_x += over_width(flags.val_w, size);
	}
	return (sum_x);
}

static int	not_minus(t_flags flags, int size, unsigned long long chislo)
{
	int	sum_x;

	sum_x = 0;
	if (flags.val_p == 0 && chislo == 0)
	{
		sum_x += over_width(flags.val_w, 0);
		sum_x--;
	}
	else
	{
		sum_x += over_width(flags.val_w, size);
		from_d_to_x(chislo);
	}
	return (sum_x);
}

int	x_posit_over_w(t_flags flags, int size, unsigned long long chislo)
{
	int	sum_x;

	sum_x = 0;
	flags.fl_z = 0;
	if (flags.val_w > flags.val_p)
	{
		if (flags.fl_m == 0)
			sum_x += not_minus(flags, size, chislo);
		if (flags.fl_m != 0)
			sum_x += minus(flags, size, chislo);
	}
	return (sum_x);
}
