#include "../ft_printf.h"

int	x(struct s_flags flags, va_list args)
{
	unsigned long long		chislo;
	int		size;
	int		sum_x;
	int		sum_over_width;
	int		sum_over_percision;

	sum_x = 0;
	sum_over_width = 0;
	sum_over_percision = 0;
	chislo = va_arg(args, unsigned int);
	size = size_of_x(chislo);

	if (flags.flag_width == 0 && flags.flag_precision == 0)
		sum_x = from_d_to_x(chislo);
	if (flags.flag_precision == 1 && flags.value_precision == 0) // precision = 0 *s_res == '0'
	{
		if (flags.value_width > size)
		{
			flags.flag_zero = 0;
			if (flags.value_width > flags.value_precision) // ширина больше сайза
			{
				if (flags.flag_minus == 0)
					sum_over_width = over_width(flags.value_width, (size - 1));
				if (flags.flag_minus != 0)
					sum_over_width = over_width(flags.value_width, (size - 1));
			}
		}
		return (1);
	}
	if (flags.flag_width == 0 && flags.flag_precision != 0) //only_precision.c
	{
		if (size >= flags.value_precision)
			sum_x = from_d_to_x(chislo);
		if (size < flags.value_precision)
		{
			sum_over_percision = over_percision(flags.value_precision, size);
			sum_x = from_d_to_x(chislo);
		}
	}
	if (flags.flag_width != 0 && flags.flag_precision == 0) //only_width.c
	{
		if (size >= flags.value_width)
			sum_x = from_d_to_x(chislo);
		if (size < flags.value_width)
		{
			if (flags.flag_zero != 0 && flags.flag_minus == 0)
			{
				sum_over_width = over_width_zero(flags.value_width, size);
				sum_x = from_d_to_x(chislo);
			}
			if (flags.flag_minus != 0 && flags.flag_zero == 0)
			{
				sum_x = from_d_to_x(chislo);
				sum_over_width = over_width(flags.value_width, size);
			}
			if (flags.flag_minus == 0 && flags.flag_zero == 0)
			{
				sum_over_width = over_width(flags.value_width, size);
				sum_x = from_d_to_x(chislo);
			}
			if (flags.flag_minus != 0 && flags.flag_zero != 0)
			{
				sum_over_width = over_width(flags.value_width, size);
				sum_x = from_d_to_x(chislo);
			}
		}
	}
	if (flags.flag_width != 0 && flags.flag_precision != 0) //width_percision
	{
			if (flags.value_width <= size && flags.value_precision <= size)
				sum_x = from_d_to_x(chislo);
			if (flags.flag_width < size && flags.flag_precision > size)
			{
				sum_over_percision = over_percision(flags.value_precision, size);
				sum_x = from_d_to_x(chislo);
			}
			if (flags.value_width > size && flags.value_precision < size)
			{
				flags.flag_zero = 0;
				if (flags.value_width > flags.value_precision) // ширина больше сайза
				{
					if (flags.flag_zero == 0 && flags.flag_minus == 0)
					{
						sum_over_width = over_width(flags.value_width, size);
						sum_x = from_d_to_x(chislo);
					}
					if (flags.flag_minus != 0)
					{
						sum_x = from_d_to_x(chislo);
						sum_over_width = over_width(flags.value_width, size);
					}
				}
			}
			if (flags.value_width > size && flags.value_precision > size) //ширина и точность больше сайза
			{
				flags.flag_zero = 0;
				if (flags.value_width > flags.value_precision)
				{
					if (flags.flag_minus == 0)
					{
						sum_over_width = over_width(flags.value_width, flags.value_precision);
						sum_over_percision = over_percision(flags.value_precision, size);
						sum_x = from_d_to_x(chislo);
					}
					if (flags.flag_minus != 0)
					{
						sum_over_percision = over_percision(flags.value_precision, size);
						sum_x = from_d_to_x(chislo);
						sum_over_width = over_width(flags.value_width, flags.value_precision);
					}
				}
			}
			if (flags.value_width < size && flags.value_precision > size)
			{
				sum_over_percision = over_percision(flags.value_precision, size);
				sum_x = from_d_to_x(chislo);
			}
	}
	return (sum_x + sum_over_width + sum_over_percision);
}