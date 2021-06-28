// добавить флаг нуля

#include "ft_printf.h"

void	c(struct s_flags flags, va_list args)
{
	char	res;

	res = va_arg(args, int);
	if (flags.flag_width != 0)
	{
		if (flags.flag_minus != 0)
		{
			write(1, &res, 1);
			over_width(flags, flags.value_width, flags.value_precision);
		}
		else
		{
			over_width(flags, flags.value_width, flags.value_precision);
			write(1, &res, 1);
		}
	}
}