#include "ft_printf.h"

int	d(struct s_flags flags, va_list args)
{
	int		res;
	int		res_copy;
	int		size;
	char	*s_res;
	int		sum_d;
	int		sum_over_width;
	int		sum_over_percision;

	size = 0;
	sum_d = 0;
	sum_over_width = 0;
	sum_over_percision = 0;
	res = va_arg(args, int);
	res_copy = res;
	while (res_copy != 0)
	{
		res_copy = res_copy / 10;
		size++;
	}
	if (res == 0)
		size++;
	if (res < 0)
		size++;
	s_res = ft_itoa(res);
	if (flags.flag_width == 0 && flags.flag_precision == 0)
	{
		write (1, s_res, size);
		sum_d = sum(size);
	}
	if (flags.flag_width == 0 && flags.flag_precision != 0) //only_precision.c
	{
		if (*s_res == '-')
		{
			write (1, "-", 1);
			res++;
			s_res++;
			size--;
		}
		if (size >= flags.value_precision)
		{
			write (1, s_res, size);
			sum_d = sum(size);
		}
		if (size < flags.value_precision)
		{
			sum_over_percision = over_percision(flags.value_precision, size);
			write (1, s_res, size);
			sum_d = sum(size);
		}
	}
	if (flags.flag_width != 0 && flags.flag_precision == 0) //only_width.c
	{
		if (size >= flags.value_width)
		{
			write (1, s_res, size);
			sum_d = sum(size);
		}
		if (size < flags.value_width)
		{
			if (flags.flag_zero != 0 && flags.flag_minus == 0)
			{
				if (*s_res == '-')
				{
					write (1, "-", 1);
					res++;
					s_res++;
					sum_over_width = over_width_zero(flags.value_width, size);
					sum_d = sum(size);
					write (1, s_res, size);
					sum_d = sum(size);
				}
				else
				{
					sum_over_width = over_width_zero(flags.value_width, size);
					sum_d = sum(size);
					write (1, s_res, size);
					sum_d = sum(size);
				}
			}
			if (flags.flag_minus != 0 && flags.flag_zero == 0)
			{
				write (1, s_res, size);
				sum_d = sum(size);
				sum_over_width = over_width(flags.value_width, size);
			}
			if (flags.flag_minus == 0 && flags.flag_zero == 0)
			{
				sum_over_width = over_width(flags.value_width, size);
				write (1, s_res, size);
				sum_d = sum(size);
			}
			if (flags.flag_minus != 0 && flags.flag_zero != 0)
			{
				sum_over_width = over_width(flags.value_width, size);
				write (1, s_res, size);
				sum_d = sum(size);
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
				sum_d = sum(size);
			}
			if (flags.flag_width < size && flags.flag_precision > size)
			{
				sum_over_percision = over_percision(flags.value_precision, size);
				write (1, s_res, size);
				sum_d = sum(size);
			}
			if (flags.value_width > size && flags.value_precision < size)
			{
				if (flags.value_width > flags.value_precision) // ширина больше сайза
				{
					if (flags.flag_zero == 0 && flags.flag_minus == 0)
					{
						sum_over_width = over_width(flags.value_width, size);
						write (1, s_res, size);
						sum_d = sum(size);
					}
					if (flags.flag_zero != 0)
					{
						sum_over_width = over_width_zero(flags.value_width, size);
						write (1, s_res, size);
						sum_d = sum(size);
					}
					if (flags.flag_minus != 0)
					{
						write(1, &res, 1);
						write (1, s_res, size);
						sum_over_width = over_width(flags.value_width, size);
					}
					if (flags.flag_zero != 0 && flags.flag_minus != 0)
					{
						over_width(flags.value_width, size);
						write (1, s_res, size);
						sum_d = sum(size);
					}
				}
			}
			if (flags.value_width > size && flags.value_precision > size) //ширина и точность больше сайза
			{
				if (flags.value_width > flags.value_precision)
				{
					if (flags.flag_zero == 0 && flags.flag_minus == 0)
					{
						sum_over_width = over_width(flags.value_width, flags.value_precision);
						sum_over_percision = over_percision(flags.value_precision, size);
						write (1, s_res, size);
						sum_d = sum(size);
					}
					if (flags.flag_zero != 0)
					{
						sum_over_percision = over_percision(flags.value_width, size);
						write (1, s_res, size);
						sum_d = sum(size);
					}
					if (flags.flag_minus != 0)
					{
						sum_over_percision = over_percision(flags.value_precision, size);
						sum_over_width = over_width(flags.value_width, flags.flag_precision);
						write (1, s_res, size);
						sum_d = sum(size);
					}
					if (flags.flag_zero != 0 && flags.flag_minus != 0)
					{
						sum_over_percision = over_percision(flags.value_precision, size);
						sum_over_width = over_width(flags.value_width, flags.flag_precision);
						write (1, s_res, size);
						sum_d = sum(size);
					}

				}
				if (flags.value_width <= flags.value_precision)
				{
					sum_over_percision = over_percision(flags.value_precision, size);
					write (1, s_res, size);
					sum_d = sum(size);
				}
			}
		}
	}
	return (sum_d + sum_over_width + sum_over_percision);
}