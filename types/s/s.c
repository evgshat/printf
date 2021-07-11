#include "../../ft_printf.h"

static int	s_only_p(t_flags flags, char *s_res, int size)
{
	int	sum_s;

	sum_s = 0;
	if ((size <= flags.val_p) && flags.val_p != 0)
		sum_s +=  write_s_null(s_res, size, flags.val_p, flags.fl_p);
	if ((size > flags.val_p) && flags.val_p != 0)
	{
		if (s_res == NULL)
			sum_s +=  write_s_null(s_res, size, flags.val_p, flags.fl_p);
		else
			sum_s +=  write_s(flags.val_p, s_res);
	}
	if (flags.val_p == 0)
		return (sum_s);
	return (sum_s);
}

static int	s_only_w(t_flags flags, char *s_res, int size)
{
	int	sum_s;

	sum_s = 0;
	if (size < flags.val_w)
	{
		if (flags.fl_m != 0)
		{
			sum_s += write_s_null(s_res, size, flags.val_p, flags.fl_p);
			if (s_res == NULL)
				sum_s += over_width(flags.val_w, 6);
			else
				sum_s += over_width(flags.val_w, size);
		}
		else
		{
			if (s_res == NULL)
				sum_s += over_width(flags.val_w, 6);
			else
				sum_s += over_width(flags.val_w, size);
			sum_s += write_s_null(s_res, size, flags.val_p, flags.fl_p);
		}
	}
	if (size >= flags.val_w)
		sum_s += write_s_null(s_res, size, flags.val_p, flags.fl_p);
	return (sum_s);
}

int	s(t_flags flags, va_list args)
{
	char	*s_res;
	int		size;
	int		sum_s;

	sum_s = 0;
	s_res = res_for_s(args, &size);
	if (flags.fl_w == 0 && flags.fl_p == 0)
		sum_s +=  write_s_null(s_res, size, flags.val_p, flags.fl_p);
	if (flags.fl_w == 0 && flags.fl_p != 0)
		sum_s += s_only_p(flags, s_res, size);
	if (flags.fl_w != 0 && flags.fl_p == 0)
		sum_s += s_only_w(flags, s_res, size);
	if (flags.fl_w != 0 && flags.fl_p != 0)
		sum_s += s_w_and_p(flags, s_res, size);
	return (sum_s);
}
