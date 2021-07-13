#include "../../ft_printf.h"

static int	x_over_w(t_flags flags, int size, int chislo)
{
	int	sum_big_x;

	sum_big_x = 0;
	flags.fl_z = 0;
	if (flags.val_w > flags.val_p)
	{
		if (flags.fl_m == 0)
		{
			sum_big_x += over_width(flags.val_w, size);
			sum_big_x += from_d_to_x(chislo);
		}
		if (flags.fl_m != 0)
		{
			sum_big_x += from_d_to_x(chislo);
			sum_big_x += over_width(flags.val_w, size);
		}
	}
	return (sum_big_x);
}

static int	x_over_w_p(t_flags flags, int size, int chislo)
{
	int	sum_big_x;

	sum_big_x = 0;
	flags.fl_z = 0;
	if (flags.val_w > flags.val_p)
	{
		if (flags.fl_m == 0)
		{
			sum_big_x += over_width(flags.val_w, flags.val_p);
			sum_big_x += over_percision(flags.val_p, size);
			sum_big_x += from_d_to_x(chislo);
		}
		if (flags.fl_m != 0)
		{
			sum_big_x += over_percision(flags.val_p, size);
			sum_big_x += from_d_to_x(chislo);
			sum_big_x += over_width(flags.val_w, flags.val_p);
		}
	}
	return (sum_big_x);
}

int	x_wp(t_flags flags, int size, int chislo)
{
	int	sum_big_x;

	sum_big_x = 0;
	if (flags.val_w <= size && flags.val_p <= size)
		sum_big_x += from_d_to_x(chislo);
	if (flags.fl_w < size && flags.fl_p > size)
	{
		sum_big_x += over_percision(flags.val_p, size);
		sum_big_x += from_d_to_x(chislo);
	}
	if (flags.val_w > size && flags.val_p < size)
		sum_big_x += x_over_w(flags, size, chislo);
	if (flags.val_w > size && flags.val_p > size)
		sum_big_x += x_over_w_p(flags, size, chislo);
	if (flags.val_w < size && flags.val_p > size)
	{
		sum_big_x += over_percision(flags.val_p, size);
		sum_big_x += from_d_to_x(chislo);
	}
	return (sum_big_x);
}
