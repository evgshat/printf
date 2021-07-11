#include "../../ft_printf.h"

static int	ost(t_flags flags, char *s_res, int size)
{
	int	sum_s;

	sum_s = 0;
	if (flags.val_w == flags.val_p)
	{
		if (s_res == NULL)
		{
			over_width(flags.val_w, 6);
			sum_s = write_s_null(s_res, size, flags.val_p, flags.fl_p);
		}
		else
		{
			over_width(flags.val_w, size);
			sum_s = write_s(size, s_res);
		}
	}
	if (flags.val_p > flags.val_w)
	{
		if (size == 0)
			over_width(flags.val_w, size);
	}
	return (sum_s);
}

static int	not_minus(t_flags flags, char *s_res, int size)
{
	int	sum_s;

	sum_s = 0;
	if (s_res != NULL)
	{
		sum_s = write_s(size, s_res);
		over_width(flags.val_w, size);
	}
	if (s_res == NULL)
	{
		sum_s = write_s_null(s_res, size, flags.val_p, flags.fl_p);
		over_width(flags.val_w, 6);
	}
	return (sum_s);
}

static int	minus(t_flags flags, char *s_res, int size)
{
	int	sum_s;

	sum_s = 0;
	if (s_res == NULL)
	{
		over_width(flags.val_w, 6);
		sum_s = write_s_null(s_res, size, flags.val_p, flags.fl_p);
	}
	else
	{
		over_width(flags.val_w, size);
		sum_s = write_s(flags.val_p - 1, s_res);
	}
	return (sum_s);
}

static int	s_w_over_then_p(t_flags flags, char *s_res, int size)
{
	int	sum_s;

	sum_s = 0;
	if (flags.fl_m != 0)
	{
		if (s_res != NULL)
		{
			sum_s = write_s(flags.val_p, s_res);
			over_width(flags.val_w, size);
		}
		if (s_res == NULL)
		{
			sum_s = write_s_null(s_res, size, flags.val_p, flags.fl_p);
			over_width(flags.val_w, size);
		}
	}
	return (sum_s);
}

int	s_over_wp(t_flags flags, char *s_res, int size)
{
	int	sum_s;

	sum_s = 0;
	flags.fl_z = 0;
	if (flags.val_w > flags.val_p && flags.val_p == size)
		s_w_over_then_p(flags, s_res, size);
	if (flags.val_w > flags.val_p && flags.val_p != size)
	{
		if (flags.fl_m == 0)
			minus(flags, s_res, size);
		if (flags.fl_m != 0)
			not_minus(flags, s_res, size);
	}
	ost(flags, s_res, size);
	return (sum_s);
}
