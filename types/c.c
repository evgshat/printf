#include "../ft_printf.h"

static int	c_w(char res, t_flags flags)
{
	int	sum_c;

	sum_c = 0;
	if ((flags.fl_z == 0 && flags.fl_m == 0)
		|| (flags.fl_z != 0 && flags.fl_m != 0))
	{
		sum_c += over_width(flags.val_w, 1);
		sum_c += write_d_ch(res);
	}
	if (flags.fl_z != 0)
	{
		sum_c += over_width_zero(flags.val_w, 1);
		sum_c += write_d_ch(res);
	}
	if (flags.fl_m != 0)
	{
		sum_c += write_d_ch(res);
		sum_c += over_width(flags.val_w, 1);
	}
	return (sum_c);
}

int	c(t_flags flags, va_list args)
{
	char	res;
	int		sum_c;

	sum_c = 0;
	res = va_arg(args, int);
	if (flags.fl_w == 0)
		sum_c += write(1, &res, 1);
	if (flags.fl_w != 0)
		sum_c += c_w(res, flags);
	return (sum_c);
}
