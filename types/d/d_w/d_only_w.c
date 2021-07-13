#include "../../../ft_printf.h"

static int	d_w_over(t_flags flags, int size, char *s_res)
{
	int	sum_d;

	sum_d = 0;
	if (*s_res == '-')
	{
		sum_d += write_d_ch(*s_res);
		s_res++;
		sum_d += over_width_zero(flags.val_w, size);
		sum_d += write_d_s_res(s_res, (size - 1));
	}
	else
	{
		sum_d += over_width_zero(flags.val_w, size);
		sum_d += write_d_s_res(s_res, size);
	}
	return (sum_d);
}

static int	d_w_over_two(t_flags flags, int size, char *s_res)
{
	int	sum_d;

	sum_d = 0;
	if (flags.fl_m != 0 && flags.fl_z == 0)
	{
		sum_d += write_d_s_res(s_res, size);
		sum_d += over_width(flags.val_w, size);
	}
	if (flags.fl_m == 0 && flags.fl_z == 0)
	{
		sum_d += over_width(flags.val_w, size);
		sum_d += write_d_s_res(s_res, size);
	}
	if (flags.fl_m != 0 && flags.fl_z != 0)
	{
		sum_d += write_d_s_res(s_res, size);
		sum_d += over_width(flags.val_w, size);
	}
	return (sum_d);
}

int	d_only_w(t_flags flags, char *s_res, int size)
{
	int	sum_d;

	sum_d = 0;
	if (flags.fl_w != 0 && flags.fl_p == 0)
	{
		if (size >= flags.val_w)
			sum_d += write_d_s_res(s_res, size);
		if (size < flags.val_w)
		{
			if (flags.fl_z != 0 && flags.fl_m == 0)
				sum_d += d_w_over(flags, size, s_res);
			sum_d += d_w_over_two(flags, size, s_res);
		}
	}
	return (sum_d);
}
