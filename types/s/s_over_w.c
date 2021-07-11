#include "../../ft_printf.h"

static int	minus(t_flags flags, char *s_res, int size)
{
	int	sum_s;

	sum_s = 0;
	if (s_res == NULL)
	{
		if (flags.val_p == 0 && flags.fl_p == 1)
			sum_s += over_width(flags.val_w, 0);
		else
			sum_s += over_width(flags.val_w, flags.val_p);
		sum_s += write_s_null(s_res, size, flags.val_p, flags.fl_p);
	}
	else
	{
		sum_s += over_width(flags.val_w, flags.val_p);
		sum_s += write_s(flags.val_p, s_res);
	}
	return (sum_s);
}

static int	not_minus(t_flags flags, char *s_res, int size)
{
	int	sum_s;

	sum_s = 0;
	if (s_res != NULL)
	{
		sum_s += write_s(flags.val_p, s_res);
		sum_s += over_width(flags.val_w, flags.val_p);
	}
	if (s_res == NULL)
	{
		if (flags.val_p == 0)
			sum_s += over_width(flags.val_w, 0);
		if (flags.val_p != 0)
		{
			sum_s += write_s_null(s_res, size, flags.val_p, flags.fl_p);
			sum_s += over_width(flags.val_w, flags.val_p);
		}
	}
	return (sum_s);
}

int	s_over_w(t_flags flags, char *s_res, int size)
{
	int	sum_s;

	sum_s = 0;
	flags.fl_z = 0;
	if (flags.val_w > flags.val_p)
	{
		if (flags.fl_m == 0)
			sum_s += minus(flags, s_res, size);
		if (flags.fl_m != 0)
			sum_s += not_minus(flags, s_res, size);
	}
	return (sum_s);
}
