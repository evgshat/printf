#include "ft_printf.h"

int	big_x(struct s_flags flags, va_list args)
{
	int		chislo;
	int		size;
	int		sum_big_x;
	int		sum_over_width;
	int		sum_over_percision;

	sum_big_x = 0;
	sum_over_width = 0;
	sum_over_percision = 0;
	chislo = va_arg(args, int);
	size = size_of_x(chislo);

	if (flags.flag_width == 0 && flags.flag_precision == 0)
		sum_big_x = from_d_to_big_x(chislo);
	if (flags.flag_width == 0 && flags.flag_precision != 0)
	{
		if (size >= flags.value_precision)
			sum_big_x = from_d_to_big_x(chislo);
		if (size < flags.value_precision)
		{
			sum_over_percision = over_percision(flags.value_precision, size);
			sum_big_x = from_d_to_big_x(chislo);
		}
	}
	if (flags.flag_width != 0 && flags.flag_precision == 0)
	{
		if (size >= flags.value_width)
			sum_big_x = from_d_to_big_x(chislo);
		if (size < flags.value_width)
		{
			if (flags.flag_minus == 0 && flags.flag_zero != 0)
			{
				sum_over_width = over_width_zero(flags.value_width, size);
				sum_big_x = from_d_to_big_x(chislo);
			}
			else
			{
				if (flags.flag_minus != 0)
				{
					sum_big_x = from_d_to_big_x(chislo);
					sum_over_width = over_width(flags.value_width, size);
				}
				else
				{
					sum_over_width = over_width(flags.value_width, size);
					sum_big_x = from_d_to_big_x(chislo);
				}
			}
		}
	}
	if (flags.flag_width != 0 && flags.flag_precision != 0)
	{
		if (size >= flags.value_width && size >= flags.value_precision)
		{
			sum_big_x = from_d_to_big_x(chislo);
			return (sum_big_x + sum_over_width + sum_over_percision);
		}
		if (flags.value_precision >= flags.value_width)
		{
			sum_over_percision = over_percision(flags.value_precision, size);
			sum_big_x = from_d_to_big_x(chislo);
		}
		if (flags.value_precision < flags.value_width)
		{
			if (flags.flag_minus != 0)
			{
				sum_over_percision = over_percision(flags.value_precision, size);
				sum_big_x = from_d_to_big_x(chislo);
				sum_over_width = over_width(flags.value_width, flags.value_precision);
			}
			else
			{
				sum_over_width = over_width(flags.value_width, flags.value_precision);
				sum_over_percision = over_percision(flags.value_precision, size);
				sum_big_x = from_d_to_big_x(chislo);
			}
		}
	}
	return (sum_big_x + sum_over_width + sum_over_percision);
}