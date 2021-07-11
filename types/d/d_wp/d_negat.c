#include "../../../ft_printf.h"

static int	d_negat_over_w_p(t_flags flags, int size, char *s_res)
{
	int	sum_d;

	sum_d = 0;
	flags.fl_z = 0;
	if (flags.val_w > flags.val_p)
	{
		if (flags.fl_m == 0)
		{
			sum_d += over_width(flags.val_w, (flags.val_p + 1));
			sum_d += write_d_ch('-');
			sum_d += over_percision(flags.val_p, size);
			sum_d += write_d_s_res(s_res, size);
		}
		if (flags.fl_m != 0)
		{
			sum_d += write_d_ch('-');
			sum_d += over_percision(flags.val_p, size);
			sum_d += write_d_s_res(s_res, size);
			sum_d += over_width(flags.val_w, (flags.val_p + 1));
		}
	}
	return (sum_d);
}

static int	d_negat_over_w(t_flags flags, int size, char *s_res)
{
	int	sum_d;

	sum_d = 0;
	flags.fl_z = 0;
	if (flags.val_w > flags.val_p)
	{
		if (flags.fl_m == 0)
		{
			sum_d += over_width(flags.val_w, (size + 1));
			sum_d += write_d_ch('-');
			sum_d += write_d_s_res(s_res, size);
		}
		if (flags.fl_m != 0)
		{
			sum_d += write_d_ch('-');
			sum_d += write_d_s_res(s_res, size);
			sum_d += over_width(flags.val_w, (size + 1));
		}
	}
	return (sum_d);
}

int	d_negat(t_flags flags, int size, char *s_res)
{
	int	sum_d;

	sum_d = 0;
	s_res++;
	if (flags.val_w <= (size - 1) && flags.val_p <= (size - 1))
	{
		sum_d += write_d_ch('-');
		sum_d += write_d_s_res(s_res, (size - 1));
	}
	if (flags.fl_w < (size - 1) && flags.fl_p > (size - 1))
	{
		sum_d += over_percision(flags.val_p, (size - 1));
		sum_d += write_d_s_res(s_res, (size - 1));
	}
	if (flags.val_w > (size - 1) && flags.val_p < (size - 1))
		sum_d += d_negat_over_w(flags, (size - 1), s_res);
	if (flags.val_w > (size - 1) && flags.val_p > (size - 1))
		sum_d += d_negat_over_w_p(flags, (size - 1), s_res);
	if (flags.val_w < (size - 1) && flags.val_p > (size - 1))
	{
		sum_d += write_d_ch('-');
		sum_d += over_percision(flags.val_p, (size - 1));
		sum_d += write_d_s_res(s_res, (size - 1));
	}
	return (sum_d);
}
