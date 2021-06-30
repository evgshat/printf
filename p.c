#include "ft_printf.h"

int	p(struct s_flags flags, va_list args)
{
	int		chislo;
	int		size;
	int		sum_p;
	int		sum_over_width;
	int		sum_over_percision;

	sum_p = 0;
	sum_over_width = 0;
	sum_over_percision = 0;
	chislo = va_arg(args, int);
	size = size_of_x(chislo) + 2;
	if (flags.flag_width == 0 && flags.flag_precision == 0)
	{
		sum_p = from_d_to_p(chislo);
	}
	if (flags.flag_width != 0 && flags.flag_precision == 0)
	{
		if (size >= flags.value_width)
			sum_p = from_d_to_p(chislo);
		if (size < flags.value_width)
		{
			if (flags.flag_minus != 0)
			{
				sum_p = from_d_to_p(chislo);
				sum_over_width = over_width(flags.value_width, size);
			}
			else
			{
				sum_over_width = over_width(flags.value_width, size);
				sum_p = from_d_to_p(chislo);
			}
		}
	}
if (flags.flag_width != 0 && flags.flag_precision != 0)
	{
		if (size >= flags.value_width && size >= flags.value_precision)
		{
			sum_p = from_d_to_x(chislo);
			return (sum_p + sum_over_width + sum_over_percision);
		}
		if (flags.value_precision >= flags.value_width)
		{
			sum_over_percision = over_percision(flags.value_precision, size);
			sum_p = from_d_to_x(chislo);
		}
		if (flags.value_precision < flags.value_width)
		{
			if (flags.flag_minus != 0)
			{
				sum_over_percision = over_percision(flags.value_precision, size);
				sum_p = from_d_to_x(chislo);
				sum_over_width = over_width(flags.value_width, flags.value_precision);
			}
			else
			{
				sum_over_width = over_width(flags.value_width, flags.value_precision);
				sum_over_percision = over_percision(flags.value_precision, size);
				sum_p = from_d_to_x(chislo);
			}
		}
	}
	return (sum_p + sum_over_width + sum_over_percision);
}