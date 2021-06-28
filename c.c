#include "ft_printf.h"

int	c(struct s_flags flags, va_list args)
{
	char	res;
	int		sum_c;

	res = va_arg(args, int);
	if (flags.flag_width == 0 && flags.flag_precision == 0)
	{
		write(1, &res, 1);
		sum_c = sum(1);
	}
	if (flags.flag_width != 0)
	{
		if (flags.flag_minus != 0)
		{
			write(1, &res, 1);
			sum_c = sum(1);
			over_width(flags, flags.value_width, flags.value_precision);
		}
		else
		{
			over_width(flags, flags.value_width, flags.value_precision);
			write(1, &res, 1);
			sum_c = sum(1);
		}
	}
	return (sum_c);
}