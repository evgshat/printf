#include "../../ft_printf.h"

static int	d_w_zero_p_zero(t_flags flags, char *s_res, int size)
{
	int	sum_d;

	sum_d = 0;
	if (flags.fl_w == 0 && flags.fl_p == 0)
		sum_d += write_d_s_res(s_res, size);
	return (sum_d);
}

static int	d_only_p(t_flags flags, char *s_res, int size)
{
	int	sum_d;

	sum_d = 0;
	if (flags.fl_w == 0 && flags.fl_p != 0)
	{
		if (*s_res == '-')
		{
			sum_d += write_d_ch(*s_res);
			s_res++;
			size--;
		}
		if (size >= flags.val_p)
			sum_d += write_d_s_res(s_res, size);
		if (size < flags.val_p)
		{
			sum_d += over_percision(flags.val_p, size);
			sum_d += write_d_s_res(s_res, size);
		}
	}
	return (sum_d);
}

static int	d_fp_is_vp_zero(t_flags flags, int size)
{
	int	sum_d;

	sum_d = 0;
	if (flags.val_w > size)
	{
		flags.fl_z = 0;
		if (flags.val_w > flags.val_p)
		{
			if (flags.fl_m == 0)
				sum_d += over_width(flags.val_w, (size - 1));
			if (flags.fl_m != 0)
				sum_d += over_width(flags.val_w, (size - 1));
		}
	}
	return (sum_d);
}

int	d(t_flags flags, va_list args)
{
	int		size;
	char	*s_res;
	int		sum_d;

	size = 0;
	sum_d = 0;
	s_res = res_for_d(args, &size);
	sum_d += d_w_zero_p_zero(flags, s_res, size);
	if (flags.fl_p == 1 && flags.val_p == 0 && flags.fl_w == 0)
	{
		sum_d += d_fp_is_vp_zero(flags, size);
		free(s_res);
		return (0);
	}
	sum_d += d_only_p(flags, s_res, size);
	sum_d += d_only_w(flags, s_res, size);
	sum_d += d_w_and_p(flags, size, s_res);
	free(s_res);
	return (sum_d);
}
