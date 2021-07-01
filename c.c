#include "ft_printf.h"

int	c(struct s_flags flags, va_list args)
{
	char	res;
	int		sum_c;
	int		sum_over_width;

	sum_c = 0;
	sum_over_width = 0;
	res = va_arg(args, int);
	if (flags.flag_width == 0)
	{
		write(1, &res, 1);
		sum_c = sum(1);
	}
	if (flags.flag_width != 0)
	{
		if (flags.flag_zero == 0 && flags.flag_minus == 0)
		{
			over_width(flags.value_width, 1);
			write(1, &res, 1);
			sum_c = sum(1);
		}
		if (flags.flag_zero != 0)
		{
			over_width_zero(flags.value_width, 1);
			write(1, &res, 1);
			sum_c = sum(1);
		}
		if (flags.flag_minus != 0)
		{
			write(1, &res, 1);
			sum_c = sum(1);
			sum_over_width = over_width(flags.value_width, 1);
		}
		if (flags.flag_zero != 0 && flags.flag_minus != 0)
		{
			over_width(flags.value_width, 1);
			write(1, &res, 1);
			sum_c = sum(1);
		}
	}
	return (sum_c + sum_over_width);
}