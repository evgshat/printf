#include "../../../ft_printf.h"

static int	d_posit_over_w_m(t_flags flags, int size, char *s_res)
{
	int	sum_d;

	sum_d = 0;
	if (flags.val_p == 0 && *s_res == '0')
		sum_d += over_width(flags.val_w, 0);
	else
	{
		sum_d += write_d_s_res(s_res, size);
		sum_d += over_width(flags.val_w, size);
	}
	return (sum_d);
}

static int	d_posit_over_w(t_flags flags, int size, char *s_res)
{
	int	sum_d;

	sum_d = 0;
	flags.fl_z = 0;
	if (flags.val_w > flags.val_p)
	{
		if (flags.fl_m == 0)
		{
			if (flags.val_p == 0 && *s_res == '0')
				sum_d += over_width(flags.val_w, 0);
			else
			{
				sum_d += over_width(flags.val_w, size);
				sum_d += write_d_s_res(s_res, size);
			}
		}
		if (flags.fl_m != 0)
			sum_d += d_posit_over_w_m(flags, size, s_res);
	}
	return (sum_d);
}

static int	d_posit_over_w_p(t_flags flags, int size, char *s_res)
{
	int	sum_d;

	sum_d = 0;
	flags.fl_z = 0;
	if (flags.val_w >= flags.val_p)
	{
		if (flags.fl_m == 0)
		{
			sum_d += over_width(flags.val_w, flags.val_p);
			sum_d += over_percision(flags.val_p, size);
			sum_d += write_d_s_res(s_res, size);
		}
		if (flags.fl_m != 0)
		{
			sum_d += over_percision(flags.val_p, size);
			sum_d += write_d_s_res(s_res, size);
			sum_d += over_width(flags.val_w, flags.val_p);
		}
	}
	return (sum_d);
}

static int	d_posit_over_p(t_flags flags, int size, char *s_res)
{
	int	sum_d;

	sum_d = 0;
	flags.fl_z = 0;
	if (flags.val_w < flags.val_p)
	{
		sum_d += over_percision(flags.val_p, size);
		sum_d += write_d_s_res(s_res, size);
	}
	return (sum_d);
}

int	d_posit(t_flags flags, int size, char *s_res)
{
	int	sum_d;

	sum_d = 0;
	if (flags.val_w < size && flags.val_p <= size)
		sum_d += write_d_s_res(s_res, size);
	if (flags.val_w < size && flags.val_p > size)
	{
		sum_d += over_percision(flags.val_p, size);
		sum_d += write_d_s_res(s_res, size);
	}
	if (flags.val_w >= size && flags.val_p < size)
		sum_d += d_posit_over_w(flags, size, s_res);
	if (flags.val_w >= size && flags.val_p >= size)
	{
		if (flags.val_p == 0)
			sum_d += over_width(flags.val_w, flags.val_p);
		else
		{
			sum_d += d_posit_over_w_p(flags, size, s_res);
			sum_d += d_posit_over_p(flags, size, s_res);
		}
	}
	return (sum_d);
}
