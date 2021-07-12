#include "../../ft_printf.h"

static int	s_over_w_one(t_flags flags, char *s_res, int size)
{
	int	sum_s;

	sum_s = 0;
	if (s_res == NULL)
	{
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

static int	s_over_w_two(t_flags flags, char *s_res, int size)
{
	int	sum_s;

	sum_s = 0;
	if (s_res == NULL)
	{
		sum_s += write_s_null(s_res, size, flags.val_p, flags.fl_p);
		sum_s += over_width(flags.val_w, flags.val_p);
	}
	else
	{
		sum_s += write_s(flags.val_p, s_res);
		sum_s += over_width(flags.val_w, flags.val_p);
	}
	return (sum_s);
}

static int	s_over_p(t_flags flags, char *s_res, int size)
{
	int	sum_s;

	sum_s = 0;
	if (s_res == NULL)
	{
		sum_s += over_width(flags.val_w, 6);
		sum_s += write_s_null(s_res, size, flags.val_p, flags.fl_p);
	}
	else
	{
		sum_s += over_width(flags.val_w, flags.val_p);
		sum_s += write_s(flags.val_p, s_res);
	}
	return (sum_s);
}

static int	s_w_eq_p(t_flags flags, char *s_res, int size)
{
	int	sum_s;

	sum_s = 0;
	if (s_res == NULL)
	{
		sum_s += over_width(flags.val_w, 6);
		sum_s += write_s_null(s_res, size, flags.val_p, flags.fl_p);
	}
	else
	{
		sum_s += over_width(flags.val_w, flags.val_p);
		sum_s += write_s(flags.val_p, s_res);
	}
	return (sum_s);
}

int	s_less_wp(t_flags flags, char *s_res, int size)
{
	int	sum_s;

	sum_s = 0;
	if (flags.val_w > flags.val_p)
	{
		if (flags.fl_m == 0)
			sum_s += s_over_w_one(flags, s_res, size);
		if (flags.fl_m != 0)
		sum_s += s_over_w_two(flags, s_res, size);
	}
	if (flags.val_w < flags.val_p)
		sum_s += s_over_p(flags, s_res, size);
	if (flags.val_w == flags.val_p)
		sum_s += s_w_eq_p(flags, s_res, size);
	return (sum_s);
}
