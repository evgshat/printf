#include "../ft_printf.h"

static int	c_w(char res, t_flags flags)
{
	int	sum_rerc;

	sum_rerc = 0;
	if ((flags.fl_z == 0 && flags.fl_m == 0)
		|| (flags.fl_z != 0 && flags.fl_m != 0))
	{
		sum_rerc += over_width(flags.val_w, 1);
		sum_rerc += write_d_ch(res);
	}
	if (flags.fl_z != 0)
	{
		sum_rerc += over_width_zero(flags.val_w, 1);
		sum_rerc += write_d_ch(res);
	}
	if (flags.fl_m != 0)
	{
		sum_rerc += write_d_ch(res);
		sum_rerc += over_width(flags.val_w, 1);
	}
	return (sum_rerc);
}

int	perc(t_flags flags)
{
	char	res;
	int		sum_rerc;

	sum_rerc = 0;
	res = '%';
	if (flags.fl_w == 0)
		sum_rerc += write(1, &res, 1);
	if (flags.fl_w != 0)
		sum_rerc += c_w(res, flags);
	return (sum_rerc);
}
