#include "ft_printf.h"

int	u(struct s_flags flags, va_list args)
{
	unsigned int		res;
	unsigned int		res_copy;
	int					size;
	char				*s_res;
	int					sum_u;
	int					sum_over_width;
	int					sum_over_percision;

	sum_u = 0;
	sum_over_width = 0;
	sum_over_percision = 0;
	size = 0;
	res = va_arg(args, unsigned int);
	res_copy = res;
	while (res_copy != 0)
	{
		res_copy = res_copy / 10;
		size++;
	}
	if (res == 0)
		size++;
	s_res = ft_itoa_unint(res);
	if (flags.flag_width == 0 && flags.flag_precision == 0)
	{
		write (1, s_res, size);
		sum_u = sum(size);
	}
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
		{
			write (1, s_res, size);
			sum_u = sum(size);
		}
		if (size < flags.value_precision)
		{
			sum_over_percision = over_percision(flags.value_precision, size);
			write (1, s_res, size);
			sum_u = sum(size);
		}
	}
	if (flags.flag_width != 0 && flags.flag_precision == 0) //only_width.c
	{
		if (size >= flags.value_width)
		{
			write (1, s_res, size);
			sum_u = sum(size);
		}
		if (size < flags.value_width)
		{
			if (flags.flag_zero != 0 && flags.flag_minus == 0)
			{
				sum_over_width = over_width_zero(flags.value_width, size);
				sum_u = sum(size);
				write (1, s_res, size);
				sum_u = sum(size);
			}
			if (flags.flag_minus != 0 && flags.flag_zero == 0)
			{
				write (1, s_res, size);
				sum_u = sum(size);
				sum_over_width = over_width(flags.value_width, size);
			}
			if (flags.flag_minus == 0 && flags.flag_zero == 0)
			{
				sum_over_width = over_width(flags.value_width, size);
				write (1, s_res, size);
				sum_u = sum(size);
			}
			if (flags.flag_minus != 0 && flags.flag_zero != 0)
			{
				sum_over_width = over_width(flags.value_width, size);
				write (1, s_res, size);
				sum_u = sum(size);
			}
		}
	}
	if (flags.flag_width != 0 && flags.flag_precision != 0) //width_percision
	{
		if (*s_res != '-') // логика для положительных чисел
		{
			if (flags.value_width <= size && flags.value_precision <= size)
			{
				write (1, s_res, size);
				sum_u = sum(size);
			}
			if (flags.flag_width < size && flags.flag_precision > size)
			{
				sum_over_percision = over_percision(flags.value_precision, size);
				write (1, s_res, size);
				sum_u = sum(size);
			}
			if (flags.value_width > size && flags.value_precision < size)
			{
				flags.flag_zero = 0;
				if (flags.value_width > flags.value_precision) // ширина больше сайза
				{
					if (flags.flag_zero == 0 && flags.flag_minus == 0)
					{
						sum_over_width = over_width(flags.value_width, size);
						write (1, s_res, size);
						sum_u = sum(size);
					}
					if (flags.flag_minus != 0)
					{
						write (1, s_res, size);
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
						write (1, s_res, size);
						sum_u = sum(size);
					}
					if (flags.flag_minus != 0)
					{
						sum_over_percision = over_percision(flags.value_precision, size);
						write (1, s_res, size);
						sum_u = sum(size);
						sum_over_width = over_width(flags.value_width, flags.value_precision);
					}
				}
			}
			if (flags.value_width < size && flags.value_precision > size)
			{
				sum_over_percision = over_percision(flags.value_precision, size);
				write (1, s_res, size);
				sum_u = sum(size);
			}
		}
	}
	return (sum_u + sum_over_width + sum_over_percision);
}