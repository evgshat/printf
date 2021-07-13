#include "../../ft_printf.h"

static int	big_x_posit_over_w_p(t_flags flags, int size,
	unsigned long long chislo)
{
	int	sum_x;

	sum_x = 0;
	flags.fl_z = 0;
	if (flags.val_w >= flags.val_p)
	{
		if (flags.fl_m == 0)
		{
			sum_x += over_width(flags.val_w, flags.val_p);
			sum_x += over_percision(flags.val_p, size);
			from_d_to_big_x(chislo);
		}
		if (flags.fl_m != 0)
		{
			sum_x += over_percision(flags.val_p, size);
			from_d_to_big_x(chislo);
			sum_x += over_width(flags.val_w, flags.val_p);
		}
	}
	return (sum_x);
}

static int	big_x_posit_over_p(t_flags flags, int size,
	unsigned long long chislo)
{
	int	sum_x;

	sum_x = 0;
	flags.fl_z = 0;
	if (flags.val_w < flags.val_p)
	{
		sum_x += over_percision(flags.val_p, size);
		from_d_to_big_x(chislo);
	}
	return (sum_x);
}

int	big_x_posit(t_flags flags, int size, unsigned long long chislo)
{
	int	sum_x;

	sum_x = 0;
	if (flags.val_w < size && flags.val_p <= size)
		from_d_to_big_x(chislo);
	if (flags.val_w < size && flags.val_p > size)
	{
		sum_x += over_percision(flags.val_p, size);
		from_d_to_big_x(chislo);
	}
	if (flags.val_w >= size && flags.val_p < size)
		sum_x += big_x_posit_over_w(flags, size, chislo);
	if (flags.val_w >= size && flags.val_p >= size)
	{
		if (flags.val_p == 0)
			sum_x += over_width(flags.val_w, flags.val_p);
		else
		{
			sum_x += big_x_posit_over_w_p(flags, size, chislo);
			sum_x += big_x_posit_over_p(flags, size, chislo);
		}
	}
	return (sum_x);
}
