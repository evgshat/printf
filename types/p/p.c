#include "../../ft_printf.h"

// static int	p_chislo_null(t_flags flags, int size, int chislo)
// {

// }

static int	p_only_p(t_flags flags, int size, int chislo)
{
	int	sum_x;

	sum_x = 0;
	if (size >= flags.val_p)
		sum_x = from_d_to_p(chislo);
	if (size < flags.val_p)
	{
		over_percision(flags.val_p, size);
		sum_x = from_d_to_p(chislo);
	}
	return (sum_x);
}

static int	p_only_w(t_flags flags, int size, int chislo)
{
	int	sum_x;

	sum_x = 0;
	if (size >= flags.val_w)
		sum_x = from_d_to_p(chislo);
	if (size < flags.val_w)
	{
		if (flags.fl_z != 0 && flags.fl_m == 0)
		{
			over_width_zero(flags.val_w, size);
			sum_x = from_d_to_p(chislo);
		}
		if (flags.fl_m != 0 && flags.fl_z == 0)
		{
			sum_x = from_d_to_p(chislo);
			over_width(flags.val_w, size);
		}
		if (flags.fl_m == 0 && flags.fl_z == 0)
		{
			over_width(flags.val_w, size);
			sum_x = from_d_to_p(chislo);
		}
		if (flags.fl_m != 0 && flags.fl_z != 0)
		{
			over_width(flags.val_w, size);
			sum_x = from_d_to_p(chislo);
		}
	}
	return (sum_x);
}


static void	p_fp_is_vp_zero(t_flags flags, int size) // есть точно такая же функция в d.c - вынести (d_fp_is_vp_zero)
{
	if (flags.val_w > size)
	{
		flags.fl_z = 0;
		if (flags.val_w > flags.val_p)
		{
			if (flags.fl_m == 0)
				over_width(flags.val_w, (size - 1));
			if (flags.fl_m != 0)
				over_width(flags.val_w, (size - 1));
		}
	}
}

int	p(t_flags flags, va_list args)
{
	unsigned long long		chislo;
	int						size;
	int						sum_x;

	sum_x = 0;
	chislo = va_arg(args, unsigned int);
	size = size_of_p(chislo);
	// if (chislo == NULL)
	// 	p_chislo_null(flags, size);
	if (flags.fl_w == 0 && flags.fl_p == 0)
		sum_x = from_d_to_p(chislo);
	if (flags.fl_p == 1 && flags.val_p == 0)
	{
		p_fp_is_vp_zero(flags, size);
		return (1);
	}
	if (flags.fl_w == 0 && flags.fl_p != 0)
		p_only_p(flags, size, chislo);
	if (flags.fl_w != 0 && flags.fl_p == 0)
		p_only_w(flags, size, chislo);
	if (flags.fl_w != 0 && flags.fl_p != 0)
		p_wp(flags, size, chislo);
	return (sum_x);
}