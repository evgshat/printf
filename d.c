#include "ft_printf.h"

void	d(struct s_flags flags, va_list args)
{
	int		res;
	int		res_copy;
	int		size;
	char	*s_res;

	size = 0;
	res = va_arg(args, int);
	res_copy = res;
	while (res_copy != 0)
	{
		res_copy = res_copy / 10;
		size++;
	}
	if (res < 0)
		size++;
	s_res = ft_itoa(res);
	if (flags.flag_width == 0 && flags.flag_precision == 0)
		write (1, s_res, size);
	if (flags.flag_width == 0 && flags.flag_precision != 0)
	{
		if (size >= flags.value_precision)
			write (1, s_res, size);
		if (size < flags.value_precision)
		{
			over_percision(flags, size, flags.value_precision, size);
			write (1, s_res, size);
		}
	}
	if (flags.flag_width != 0 && flags.flag_precision == 0)
	{
		if (size >= flags.value_width)
			write (1, s_res, size);
		if (size < flags.value_width)
		{
			if (flags.flag_minus == 0 && flags.flag_zero != 0)
			{
				over_width_zero(flags, flags.value_width, size);
				write (1, s_res, size);
			}
			else
			{
				if (flags.flag_minus != 0)
				{
					write (1, s_res, size);
					over_width(flags, flags.value_width, size);
				}
				else
				{
					over_width(flags, flags.value_width, size);
					write (1, s_res, size);
				}
			}
		}
	}
	if (flags.flag_width != 0 && flags.flag_precision != 0)
	{
		if (size >= flags.value_width && size >= flags.value_precision)
		{
			write (1, s_res, size);
			return;
		}
		if (flags.value_precision >= flags.value_width)
		{
			over_width(flags, flags.value_precision, size);
			write (1, s_res, size);
		}
		if (flags.value_precision < flags.value_width)
		{
			if (flags.flag_minus != 0)
			{
				over_percision(flags, size, flags.value_precision, size);
				write (1, s_res, size);
				over_width(flags, flags.value_width, flags.value_precision);
			}
			else
			{
				over_width(flags, flags.value_width, flags.value_precision);
				over_percision(flags, size, flags.value_precision, size);
				write (1, s_res, size);
			}
		}
	}
}