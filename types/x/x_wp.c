#include "../../ft_printf.h"

static int	x_over_w(t_flags flags, int size, int chislo)
{
	int	sum_x;

	sum_x = 0;
	flags.fl_z = 0;
	if (flags.val_w > flags.val_p)
	{
		if (flags.fl_m == 0)
		{
			sum_x += over_width(flags.val_w, size);
			from_d_to_x(chislo);
			sum_x += size;
		}
		if (flags.fl_m != 0)
		{
			from_d_to_x(chislo);
			sum_x += size;
			sum_x += over_width(flags.val_w, size);
		}
	}
	return (sum_x);
}

static int	x_over_w_p(t_flags flags, int size, int chislo)
{
	int	sum_x;

	sum_x = 0;
	flags.fl_z = 0;
	if (flags.val_w > flags.val_p)
	{
		if (flags.fl_m == 0)
		{
			sum_x += over_width(flags.val_w, flags.val_p);
			sum_x += over_percision(flags.val_p, size);
			from_d_to_x(chislo);
			sum_x += size;
		}
		if (flags.fl_m != 0)
		{
			sum_x += over_percision(flags.val_p, size);
			from_d_to_x(chislo);
			sum_x += size;
			sum_x += over_width(flags.val_w, flags.val_p);
		}
	}
	return (sum_x);
}

static int	x_over_p(t_flags flags, int size, int chislo)
{
	int	sum_x;

	sum_x = 0;
	flags.fl_z = 0;
	if (flags.val_w < flags.val_p)
	{
		sum_x += over_percision(flags.val_p, size);
		from_d_to_x(chislo);
		sum_x += size;
	}
	return (sum_x);
}

int	x_wp(t_flags flags, int size, int chislo)
{
	int	sum_x;

	sum_x = 0;
	if (flags.val_w <= size && flags.val_p <= size)
	{
		from_d_to_x(chislo);
		sum_x += size;
	}
	if (flags.fl_w < size && flags.fl_p > size)
	{
		sum_x += over_percision(flags.val_p, size);
		from_d_to_x(chislo);
		sum_x += size;
	}
	if (flags.val_w > size && flags.val_p < size)
		sum_x += x_over_w(flags, size, chislo);
	if (flags.val_w > size && flags.val_p > size)
	{
		sum_x += x_over_w_p(flags, size, chislo);
		sum_x += x_over_p(flags, size, chislo);
	}
	if (flags.val_w < size && flags.val_p > size)
	{
		sum_x += over_percision(flags.val_p, size);
		from_d_to_x(chislo);
		sum_x += size;
	}
	return (sum_x);
}
