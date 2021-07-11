#include "../ft_printf.h"

static int	c_w(char res, t_flags flags)
{
	int	sum_c;

	sum_c = 0;
	if ((flags.fl_z == 0 && flags.fl_m == 0)
		|| (flags.fl_z != 0 && flags.fl_m != 0))
	{
		over_width(flags.val_w, 1);
		sum_c = write_d_ch(res);
	}
	if (flags.fl_z != 0)
	{
		over_width_zero(flags.val_w, 1);
		sum_c = write_d_ch(res);
	}
	if (flags.fl_m != 0)
	{
		sum_c = write_d_ch(res);
		over_width(flags.val_w, 1);
	}
	return (sum_c);
}

int	perc(t_flags flags)
{
	char	res;
	int		sum_c;

	sum_c = 0;
	res = '%';
	if (flags.fl_w == 0)
		write(1, &res, 1);
	if (flags.fl_w != 0)
		c_w(res, flags);
	return (sum_c);
}
