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
	while (1)
	{
		if (s_res == NULL || s_res == 0)
		{
			size = 6;
			break ;
		}
		if (*s_res == '\0')
		{
			size = 0;
			break ;
		}
		if (s_res != 0 && *s_res != '\0')
		{
			size = ft_strlen(s_res);
			break ;
		}
	}
	if (flags.flag_width == 0 && flags.flag_precision == 0) // нет ни точности, ни ширины
	{
		sum_s = write_s_null(s_res, size, flags.value_precision, flags.flag_precision);
	}
	if (flags.flag_width == 0 && flags.flag_precision != 0) // есть только точность
	{
		if ((size <= flags.value_precision) && flags.value_precision != 0)
		{
			sum_s = write_s_null(s_res, size, flags.value_precision, flags.flag_precision);
		}
		if ((size > flags.value_precision) && flags.value_precision != 0)
		{
			if (s_res == NULL)
				sum_s = write_s_null(s_res, size, flags.value_precision, flags.flag_precision);
			else
				sum_s = write_s(flags.value_precision, s_res);
		}
		if (flags.value_precision == 0)
			return (sum_s + sum_over_width);
	}
	if (flags.flag_width != 0 && flags.flag_precision == 0) // есть только ширина
	{
		if (size < flags.value_width)
		{
			if (flags.flag_minus != 0)
			{
				sum_s = write_s_null(s_res, size, flags.value_precision, flags.flag_precision);
				if (s_res == NULL)
					sum_over_width = over_width(flags.value_width, 6);
				else
					sum_over_width = over_width(flags.value_width, size);
			}
			else
			{
				if (s_res == NULL)
					sum_over_width = over_width(flags.value_width, 6);
				else
					sum_over_width = over_width(flags.value_width, size);
				sum_s = write_s_null(s_res, size, flags.value_precision, flags.flag_precision);
			}
		}
		if (size >= flags.value_width)
			sum_s = write_s_null(s_res, size, flags.value_precision, flags.flag_precision);
	}
	if (flags.flag_width != 0 && flags.flag_precision != 0) // есть точность и ширина
	{
		if (flags.value_precision < size && flags.value_width < size)
		{
			if (flags.value_width > flags.value_precision)
			{
				if (flags.flag_minus == 0)
				{
					if (s_res == NULL)
					{
						sum_over_width = over_width(flags.value_width, flags.value_precision);
						sum_s = write_s_null(s_res, size, flags.value_precision, flags.flag_precision);
					}
					else
					{
						sum_over_width = over_width(flags.value_width, flags.value_precision);
						sum_s = write_s(flags.value_precision, s_res);
					}
				}
				if (flags.flag_minus != 0)
				{
					if (s_res == NULL)
					{
						sum_s = write_s_null(s_res, size, flags.value_precision, flags.flag_precision);
						sum_over_width = over_width(flags.value_width, flags.value_precision);
					}
					else
					{
						sum_s = write_s(flags.value_precision, s_res);
						sum_over_width = over_width(flags.value_width, flags.value_precision);
					}
				}
			}
			if (flags.value_width < flags.value_precision)
			{
				if (s_res == NULL)
				{
					sum_over_width = over_width(flags.value_width, 6);
					sum_s = write_s_null(s_res, size, flags.value_precision, flags.flag_precision);
				}
				else
				{
					sum_over_width = over_width(flags.value_width, flags.value_precision);
					sum_s = write_s(flags.value_precision, s_res);
				}
			}
			if (flags.value_width == flags.value_precision)
			{
				if (s_res == NULL)
				{
					sum_over_width = over_width(flags.value_width, 6);
					sum_s = write_s_null(s_res, size, flags.value_precision, flags.flag_precision);
				}
				else
				{
					sum_over_width = over_width(flags.value_width, flags.value_precision);
					sum_s = write_s(flags.value_precision, s_res);
				}
			}
		}
		if (flags.flag_width < size && flags.flag_precision > size)
		{
			sum_s = write_s(flags.value_precision, s_res);
		}
		if (flags.value_width >= size && flags.value_precision == size && size == 0)
		{
			sum_over_width = over_width(flags.value_width, flags.value_precision);
		}
		if (flags.value_width >= size && flags.value_precision < size) //  ширина больше сайза, а точность меньше
		{
			flags.flag_zero = 0;
			if (flags.value_width > flags.value_precision) // ширина больше точности
			{
				if (flags.flag_minus == 0)
				{
					if (s_res == NULL)
					{
						if (flags.value_precision == 0 && flags.flag_precision == 1)
						{
							sum_over_width = over_width(flags.value_width, 0);
						}
						else
						{
							sum_over_width = over_width(flags.value_width, flags.value_precision);
						}
						sum_s = write_s_null(s_res, size, flags.value_precision, flags.flag_precision);
					}
					else
					{
						sum_over_width = over_width(flags.value_width, flags.value_precision);
						sum_s = write_s(flags.value_precision, s_res);
					}
				}
				if (flags.flag_minus != 0)
				{
					if (s_res != NULL)
					{
						sum_s = write_s(flags.value_precision, s_res);
						sum_over_width = over_width(flags.value_width, flags.value_precision);
					}
					if (s_res == NULL)
					{
						if (flags.value_precision == 0)
							sum_over_width = over_width(flags.value_width, 0);
						if (flags.value_precision != 0)
						{
							sum_s = write_s_null(s_res, size, flags.value_precision, flags.flag_precision);
							sum_over_width = over_width(flags.value_width, flags.value_precision);
						}
					}
				}
			}
		}
		if (flags.value_width > size && flags.value_precision > size) //ширина и точность больше сайза
		{
			flags.flag_zero = 0;
			if (flags.value_width > flags.value_precision && flags.value_precision == size)
			{
				if (flags.flag_minus != 0)
				{
					if (s_res != NULL)
					{
						sum_s = write_s(flags.value_precision, s_res);
						sum_over_width = over_width(flags.value_width, size);
					}
					if (s_res == NULL)
					{
						sum_s = write_s_null(s_res, size, flags.value_precision, flags.flag_precision);
						sum_over_width = over_width(flags.value_width, size);
					}
				}
			}
			if (flags.value_width > flags.value_precision && flags.value_precision != size)
			{
				if (flags.flag_minus == 0)
				{
					if (s_res == NULL)
					{
						sum_over_width = over_width(flags.value_width, 6);
						sum_s = write_s_null(s_res, size, flags.value_precision, flags.flag_precision);
					}
					else
					{
						sum_over_width = over_width(flags.value_width, size);
						sum_s = write_s(flags.value_precision - 1, s_res);
					}
				}
				if (flags.flag_minus != 0)
				{
					if (s_res != NULL)
					{
						sum_s = write_s(size, s_res);
						sum_over_width = over_width(flags.value_width, size);
					}
					if (s_res == NULL)
					{
						sum_s = write_s_null(s_res, size, flags.value_precision, flags.flag_precision);
						sum_over_width = over_width(flags.value_width, 6);
					}
				}
			}
			if (flags.value_width == flags.value_precision)
			{
				if (s_res == NULL)
				{
					sum_over_width = over_width(flags.value_width, 6);
					sum_s = write_s_null(s_res, size, flags.value_precision, flags.flag_precision);
				}
				else
				{
					sum_over_width = over_width(flags.value_width, size);
					sum_s = write_s(size, s_res);
				}
			}
			if (flags.value_precision > flags.value_width)
			{
				if (size == 0)
					sum_over_width = over_width(flags.value_width, size);
			}
		}
		if (flags.value_width < size && flags.value_precision > size)
		{
			sum_s = write_s(size, s_res);
		}
		if (flags.value_width < size && flags.value_precision == size)
		{
			sum_s = write_s(flags.value_precision, s_res);
		}
		if (flags.value_width > size && flags.value_precision == size && size != 0)
		{
			if (flags.flag_minus == 0)
			{
				sum_over_width = over_width(flags.value_width, flags.value_precision);
				sum_s = write_s(flags.value_precision, s_res);
			}
			if (flags.flag_minus != 0)
			{
				sum_s = write_s(flags.value_precision, s_res);
				sum_over_width = over_width(flags.value_width, flags.value_precision);
			}
		}
		// if (flags.value_width > size && flags.value_precision == size)
		// {
		// 	sum_over_width = over_width(flags.value_width, flags.value_precision);
		// 	sum_s = write_s(flags.value_precision, s_res);
		// }
	}
	return (sum_s + sum_over_width);
}

// static char *s_hidden = "hi low\0don't print me lol\0";