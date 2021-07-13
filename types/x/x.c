#include "../../ft_printf.h"

static int	x_only_p(t_flags flags, unsigned long long chislo, int size)
{
	int	sum_x;

	sum_x = 0;
	if (flags.fl_w == 0 && flags.fl_p != 0)
	{
		if (size >= flags.val_p)
			from_d_to_x(chislo);
		if (size < flags.val_p)
		{
			sum_x += over_percision(flags.val_p, size);
			from_d_to_x(chislo);
		}
	}
	return (sum_x);
}

static int	x_fp_is_vp_zero(t_flags flags, int size)
{
	int	sum_x;

	sum_x = 0;
	if (flags.val_w > size)
	{
		flags.fl_z = 0;
		if (flags.val_w > flags.val_p)
		{
			if (flags.fl_m == 0)
				sum_x += over_width(flags.val_w, (size - 1));
			if (flags.fl_m != 0)
				sum_x += over_width(flags.val_w, (size - 1));
		}
	}
	return (sum_x);
}

static int	x_w_and_p(t_flags flags, int size, unsigned long long chislo)
{
	int	sum_x;

	sum_x = 0;
	if (flags.fl_w != 0 && flags.fl_p != 0)
		sum_x += x_posit(flags, size, chislo);
	return (sum_x);
}

int	x(t_flags flags, va_list args)
{
	unsigned long long		chislo;
	int						size;
	int						sum_x;

	sum_x = 0;
	chislo = va_arg(args, unsigned int);
	size = size_of_x(chislo);
	sum_x += size;
	if (flags.fl_w == 0 && flags.fl_p == 0)
		from_d_to_x(chislo);
	if (flags.fl_p == 1 && flags.val_p == 0 && flags.fl_w == 0 && chislo == 0)
	{
		sum_x += x_fp_is_vp_zero(flags, size);
		return (0);
	}
	sum_x += x_only_p(flags, chislo, size);
	sum_x += x_only_w(flags, chislo, size);
	sum_x += x_w_and_p(flags, size, chislo);
	return (sum_x);
}
