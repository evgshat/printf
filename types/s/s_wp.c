#include "../../ft_printf.h"

static int	s_w_and_p_one(t_flags flags, char *s_res, int size)
{
	int	sum_s;

	sum_s = 0;
	if (flags.fl_w < size && flags.fl_p > size)
		sum_s += write_s(flags.val_p, s_res);
	if (flags.val_w >= size && flags.val_p == size && size == 0)
		sum_s += over_width(flags.val_w, flags.val_p);
	if (flags.val_w < size && flags.val_p > size)
		sum_s += write_s(size, s_res);
	if (flags.val_w < size && flags.val_p == size)
		sum_s += write_s(flags.val_p, s_res);
	if (flags.val_w > size && flags.val_p == size && size != 0)
	{
		if (flags.fl_m == 0)
		{
			sum_s += over_width(flags.val_w, flags.val_p);
			sum_s += write_s(flags.val_p, s_res);
		}
		if (flags.fl_m != 0)
		{
			sum_s += write_s(flags.val_p, s_res);
			sum_s += over_width(flags.val_w, flags.val_p);
		}
	}
	return (sum_s);
}

int	s_w_and_p(t_flags flags, char *s_res, int size)
{
	int	sum_s;

	sum_s = 0;
	sum_s += s_w_and_p_one(flags, s_res, size);
	if (flags.val_p < size && flags.val_w < size)
		sum_s += s_less_wp(flags, s_res, size);
	if (flags.val_w >= size && flags.val_p < size)
		sum_s += s_over_w(flags, s_res, size);
	if (flags.val_w > size && flags.val_p > size)
		sum_s += s_over_wp(flags, s_res, size);
	return (sum_s);
}
