#include "../../ft_printf.h"

static int	p_over_w(t_flags flags, int size, int chislo)
{
	int	sum_x;

	sum_x = 0;
	flags.fl_z = 0;
	if (flags.val_w > flags.val_p)
	{
		if (flags.fl_m == 0)
		{
			over_width(flags.val_w, size);
			sum_x = from_d_to_p(chislo);
		}
		if (flags.fl_m != 0)
		{
			sum_x = from_d_to_p(chislo);
			over_width(flags.val_w, size);
		}
	}
	return (sum_x);
}

static int	p_over_w_p(t_flags flags, int size, int chislo)
{
	int	sum_x;

	sum_x = 0;
	flags.fl_z = 0;
	if (flags.val_w > flags.val_p)
	{
		if (flags.fl_m == 0)
		{
			over_width(flags.val_w, flags.val_p);
			over_percision(flags.val_p, size);
			sum_x = from_d_to_p(chislo);
		}
		if (flags.fl_m != 0)
		{
			over_percision(flags.val_p, size);
			sum_x = from_d_to_p(chislo);
			over_width(flags.val_w, flags.val_p);
		}
	}
	return (sum_x);
}

int	p_wp(t_flags flags, int size, int chislo)
{
	int	sum_x;

	sum_x = 0;
	if (flags.val_w <= size && flags.val_p <= size)
		sum_x = from_d_to_p(chislo);
	if (flags.fl_w < size && flags.fl_p > size)
	{
		over_percision(flags.val_p, size);
		sum_x = from_d_to_p(chislo);
	}
	if (flags.val_w > size && flags.val_p < size)
		p_over_w(flags, size, chislo);
	if (flags.val_w > size && flags.val_p > size)
		p_over_w_p(flags, size, chislo);
	if (flags.val_w < size && flags.val_p > size)
	{
		over_percision(flags.val_p, size);
		sum_x = from_d_to_p(chislo);
	}
	return (sum_x);
}
