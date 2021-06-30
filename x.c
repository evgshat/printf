#include "ft_printf.h"

int	x(struct s_flags flags, va_list args)
{
	int		chislo;
	int		size;
	int		sum_x;
	int		sum_over_width;
	int		sum_over_percision;

	sum_x = 0;
	sum_over_width = 0;
	sum_over_percision = 0;
	chislo = va_arg(args, int);
	size = size_of_x(chislo);

	if (flags.flag_width == 0 && flags.flag_precision == 0)
		sum_x = from_d_to_x(chislo);
	if (flags.flag_width == 0 && flags.flag_precision != 0)
	{
		if (size >= flags.value_precision)
			 sum_x = from_d_to_x(chislo);
		if (size < flags.value_precision)
		{
			sum_over_percision = over_percision(flags.value_precision, size);
			sum_x = from_d_to_x(chislo);
		}
	}
	if (flags.flag_width != 0 && flags.flag_precision == 0)
	{
		if (size >= flags.value_width)
			sum_x = from_d_to_x (chislo);
		if (size < flags.value_width)
		{
			if (flags.flag_minus == 0 && flags.flag_zero != 0)
			{
				sum_over_width = over_width_zero(flags.value_width, size);
				sum_x = from_d_to_x (chislo);
			}
			else
			{
				if (flags.flag_minus != 0)
				{
					sum_x = from_d_to_x (chislo);
					sum_over_width = over_width(flags.value_width, size);
				}
				else
				{
					sum_over_width = over_width(flags.value_width, size);
					sum_x = from_d_to_x (chislo);
				}
			}
		}
	}
	if (flags.flag_width != 0 && flags.flag_precision != 0)
	{
		if (size >= flags.value_width && size >= flags.value_precision)
		{
			sum_x = from_d_to_x(chislo);
			return (sum_x + sum_over_width + sum_over_percision);
		}
		if (flags.value_precision >= flags.value_width)
		{
			sum_over_percision = over_percision(flags.value_precision, size);
			sum_x = from_d_to_x(chislo);
		}
		if (flags.value_precision < flags.value_width)
		{
			if (flags.flag_minus != 0)
			{
				sum_over_percision = over_percision(flags.value_precision, size);
				sum_x = from_d_to_x(chislo);
				sum_over_width = over_width(flags.value_width, flags.value_precision);
			}
			else
			{
				sum_over_width = over_width(flags.value_width, flags.value_precision);
				sum_over_percision = over_percision(flags.value_precision, size);
				sum_x = from_d_to_x(chislo);
			}
		}
	}
	return (sum_x + sum_over_width + sum_over_percision);
}