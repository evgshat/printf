#include "../../ft_printf.h"

static int	big_x_only_p(t_flags flags, int size, int chislo)
{
	int	sum_big_x;

	sum_big_x = 0;
	if (size >= flags.val_p)
		sum_big_x += from_d_to_big_x(chislo);
	if (size < flags.val_p)
	{
		sum_big_x += over_percision(flags.val_p, size);
		sum_big_x += from_d_to_big_x(chislo);
	}
	return (sum_big_x);
}

static int	big_x_only_w(t_flags flags, int size, int chislo)
{
	int	sum_big_x;

	sum_big_x = 0;
	if (size >= flags.val_w)
		sum_big_x += from_d_to_big_x(chislo);
	if (size < flags.val_w)
	{
		if (flags.fl_z != 0 && flags.fl_m == 0)
		{
			sum_big_x += over_width_zero(flags.val_w, size);
			sum_big_x += from_d_to_big_x(chislo);
		}
		if (flags.fl_m != 0 && flags.fl_z == 0)
		{
			sum_big_x += from_d_to_big_x(chislo);
			sum_big_x += over_width(flags.val_w, size);
		}
		if (flags.fl_m == 0 && flags.fl_z == 0)
		{
			sum_big_x += over_width(flags.val_w, size);
			sum_big_x += from_d_to_big_x(chislo);
		}
		if (flags.fl_m != 0 && flags.fl_z != 0)
		{
			sum_big_x += over_width(flags.val_w, size);
			sum_big_x += from_d_to_big_x(chislo);
		}
	}
	return (sum_big_x);
}

static int	big_x_fp_is_vp_zero(t_flags flags, int size) // есть точно такая же функция в d.c - вынести (d_fp_is_vp_zero)
{
	int	sum_big_x;

	sum_big_x = 0;
	if (flags.val_w > size)
	{
		flags.fl_z = 0;
		if (flags.val_w > flags.val_p)
		{
			if (flags.fl_m == 0)
				sum_big_x += over_width(flags.val_w, (size - 1));
			if (flags.fl_m != 0)
				sum_big_x += over_width(flags.val_w, (size - 1));
		}
	}
	return (sum_big_x);
}

int	big_x(t_flags flags, va_list args)
{
	unsigned long long		chislo;
	int						size;
	int						sum_big_x;

	sum_big_x = 0;
	chislo = va_arg(args, unsigned int);
	size = size_of_x(chislo);

	if (flags.fl_w == 0 && flags.fl_p == 0)
		sum_big_x += from_d_to_big_x(chislo);
	if (flags.fl_p == 1 && flags.val_p == 0)
	{
		sum_big_x += big_x_fp_is_vp_zero(flags, size);
		return (1);
	}
	if (flags.fl_w == 0 && flags.fl_p != 0)
		sum_big_x += big_x_only_p(flags, size, chislo);
	if (flags.fl_w != 0 && flags.fl_p == 0)
		sum_big_x += big_x_only_w(flags, size, chislo);
	if (flags.fl_w != 0 && flags.fl_p != 0)
		sum_big_x += big_x_wp(flags, size, chislo);
	return (sum_big_x);
}
