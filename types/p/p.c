#include "../../ft_printf.h"

static int	p_only_p(t_flags flags, int size, unsigned long long chislo)
{
	int	sum_p;

	sum_p = 0;
	if (size >= flags.val_p)
		sum_p += from_d_to_p(chislo);
	if (size < flags.val_p)
	{
		sum_p += over_percision(flags.val_p, size);
		sum_p += from_d_to_p(chislo);
	}
	return (sum_p);
}

static int	p_only_w_two(t_flags flags, int size, unsigned long long chislo)
{
	int	sum_p;

	sum_p = 0;
	if (flags.fl_m == 0 && flags.fl_z == 0)
	{
		sum_p += over_width(flags.val_w, size);
		sum_p += from_d_to_p(chislo);
	}
	if (flags.fl_m != 0 && flags.fl_z != 0)
	{
		sum_p += over_width(flags.val_w, size);
		sum_p += from_d_to_p(chislo);
	}
	return (sum_p);
}

static int	p_only_w(t_flags flags, int size, unsigned long long chislo)
{
	int	sum_p;

	sum_p = 0;
	if (size >= flags.val_w)
		sum_p += from_d_to_p(chislo);
	if (size < flags.val_w)
	{
		if (flags.fl_z != 0 && flags.fl_m == 0)
		{
			sum_p += over_width_zero(flags.val_w, size);
			sum_p += from_d_to_p(chislo);
		}
		if (flags.fl_m != 0 && flags.fl_z == 0)
		{
			sum_p += from_d_to_p(chislo);
			sum_p += over_width(flags.val_w, size);
		}
		sum_p += p_only_w_two(flags, size, chislo);
	}
	return (sum_p);
}

static int	p_fp_is_vp_zero(t_flags flags, int size)
{
	int	sum_p;

	sum_p = 0;
	if (flags.val_w > size)
	{
		flags.fl_z = 0;
		if (flags.val_w > flags.val_p)
		{
			if (flags.fl_m == 0)
				sum_p += over_width(flags.val_w, (size - 1));
			if (flags.fl_m != 0)
				sum_p += over_width(flags.val_w, (size - 1));
		}
	}
	return (sum_p);
}

int	p(t_flags flags, va_list args)
{
	unsigned long long		chislo;
	int						size;
	int						sum_p;

	sum_p = 0;
	chislo = va_arg(args, unsigned long long);
	size = size_of_p(chislo);
	sum_p += size - 2;
	if (flags.fl_w == 0 && flags.fl_p == 0)
		sum_p += from_d_to_p(chislo);
	if (flags.fl_p == 1 && flags.val_p == 0)
	{
		sum_p += p_fp_is_vp_zero(flags, size);
		return (1);
	}
	if (flags.fl_w == 0 && flags.fl_p != 0)
		sum_p += p_only_p(flags, size, chislo);
	if (flags.fl_w != 0 && flags.fl_p == 0)
		sum_p += p_only_w(flags, size, chislo);
	if (flags.fl_w != 0 && flags.fl_p != 0)
		sum_p += p_wp(flags, size, chislo);
	return (sum_p);
}
