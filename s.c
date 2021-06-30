#include "ft_printf.h"

int	s(struct s_flags flags, va_list args)
{
	char	*s_res;
	int		size;
	int		sum_s;
	int		sum_over_width;
	int		sum_over_percision;

	sum_s = 0;
	sum_over_width = 0;
	sum_over_percision = 0;
	s_res = va_arg(args, char *);
	if (s_res != 0)
	{
		size = ft_strlen(s_res);
	}
	else
	{
		return (sum_s + sum_over_width);
	}
	if (flags.flag_width == 0 && flags.flag_precision == 0)
	{
		write (1, s_res, size);
		sum_s = sum(size);
	}
	if (flags.flag_width != 0)
	{
		if (size < flags.value_width)
		{
			if (flags.flag_minus != 0)
			{
				write(1, s_res, size);
				sum_s = sum(size);
				sum_over_width = over_width(flags.value_width, size);
			}
			else
			{
				sum_over_width = over_width(flags.value_width, size);
				write (1, s_res, size);
				sum_s = sum(size);
			}
		}
		if (size >= flags.value_width)
			write (1, s_res, size);
			sum_s = sum(size);
	}
	return (sum_s + sum_over_width);
}