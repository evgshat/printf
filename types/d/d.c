#include "../../ft_printf.h"

static int	d_w_zero_p_zero(t_flags flags, char *s_res, int size)
{
	int	sum_d;

	sum_d = 0;
	if (flags.fl_w == 0 && flags.fl_p == 0)
		sum_d = write_d_s_res(s_res, size);
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
			write (1, "-", 1);
			s_res++;
			size--;
		}
		if (size >= flags.val_p)
		{
			write (1, s_res, size);
			sum_d = sum(size);
		}
		if (size < flags.val_p)
		{
			over_percision(flags.val_p, size);
			write (1, s_res, size);
			sum_d = sum(size);
		}
	}
	return (sum_d);
}

static void	d_fp_is_vp_zero(t_flags flags, int size)
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

int	d(t_flags flags, va_list args)
{
	int		size;
	char	*s_res;
	int		sum_d;

	size = 0;
	sum_d = 0;
	s_res = res_for_d(args, &size);
	sum_d += d_w_zero_p_zero(flags, s_res, size);
	if (flags.fl_p == 1 && flags.val_p == 0)
	{
		d_fp_is_vp_zero(flags, size);
		return (1);
	}
	sum_d = d_only_p(flags, s_res, size);
	sum_d = d_only_w(flags, s_res, size);
	sum_d = d_w_and_p(flags, size, s_res);
	return (sum_d);
}
