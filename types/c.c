#include "../ft_printf.h"

int	c(t_flags flags, va_list args)
{
	char	res;
	int		sum_c;
	int		sum_over_width;

	sum_c = 0;
	sum_over_width = 0;
	res = va_arg(args, int);
	if (flags.fl_w == 0)
	{
		write(1, &res, 1);
		sum_c = sum(1);
	}
	if (flags.fl_w != 0)
	{
		if (flags.fl_z == 0 && flags.fl_m == 0)
		{
			over_width(flags.val_w, 1);
			write(1, &res, 1);
			sum_c = sum(1);
		}
		if (flags.fl_z != 0)
		{
			over_width_zero(flags.val_w, 1);
			write(1, &res, 1);
			sum_c = sum(1);
		}
		if (flags.fl_m != 0)
		{
			write(1, &res, 1);
			sum_c = sum(1);
			sum_over_width = over_width(flags.val_w, 1);
		}
		if (flags.fl_z != 0 && flags.fl_m != 0)
		{
			over_width(flags.val_w, 1);
			write(1, &res, 1);
			sum_c = sum(1);
		}
	}
	return (sum_c + sum_over_width);
}