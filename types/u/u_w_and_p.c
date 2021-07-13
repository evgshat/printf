#include "../../ft_printf.h"

static int	u_posit_over_w_p(t_flags flags, int size, char *s_res)
{
	int	sum_u;

	sum_u = 0;
	flags.fl_z = 0;
	if (flags.val_w >= flags.val_p)
	{
		if (flags.fl_m == 0)
		{
			sum_u += over_width(flags.val_w, flags.val_p);
			sum_u += over_percision(flags.val_p, size);
			sum_u += write(1, s_res, size);
		}
		if (flags.fl_m != 0)
		{
			sum_u += over_percision(flags.val_p, size);
			sum_u += write(1, s_res, size);
			sum_u += over_width(flags.val_w, flags.val_p);
		}
	}
	return (sum_u);
}

static int	u_posit_over_p(t_flags flags, int size, char *s_res)
{
	int	sum_u;

	sum_u = 0;
	flags.fl_z = 0;
	if (flags.val_w < flags.val_p)
	{
		sum_u += over_percision(flags.val_p, size);
		sum_u += write(1, s_res, size);
	}
	return (sum_u);
}

int	u_posit(t_flags flags, int size, char *s_res)
{
	int	sum_u;

	sum_u = 0;
	if (flags.val_w < size && flags.val_p <= size)
		sum_u += write(1, s_res, size);
	if (flags.val_w < size && flags.val_p > size)
	{
		sum_u += over_percision(flags.val_p, size);
		sum_u += write(1, s_res, size);
	}
	if (flags.val_w >= size && flags.val_p < size)
		sum_u += u_posit_over_w(flags, size, s_res);
	if (flags.val_w >= size && flags.val_p >= size)
	{
		if (flags.val_p == 0)
			sum_u += over_width(flags.val_w, flags.val_p);
		else
		{
			sum_u += u_posit_over_w_p(flags, size, s_res);
			sum_u += u_posit_over_p(flags, size, s_res);
		}
	}
	return (sum_u);
}

int	u_w_and_p(t_flags flags, int size, char *s_res)
{
	int	sum_u;

	sum_u = 0;
	if (flags.fl_w != 0 && flags.fl_p != 0)
		sum_u += u_posit(flags, size, s_res);
	return (sum_u);
}
