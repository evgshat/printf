#include "ft_printf.h"

void	d(struct s_flags flags, va_list args)
{
	int		res;
	int		res_copy;
	int		size;
	char	*s_res;
	int		dif_arg;
	int		i_dif_arg;

	size = 0;
	// узнаем значение из аргумента и его длину (кол-во цифр)
	res = va_arg(args, int);
	res_copy = res;
	while (res_copy != 0)
	{
		res_copy = res_copy / 10;
		size++;
	}
	s_res = ft_itoa(res);
	// если нет ни ширины, ни точности
	if (flags.flag_width == 0 && flags.flag_precision == 0)
	{
		write (1, s_res, size);
	}
	// если нет ширины, но есть точность
	if (flags.flag_width == 0 && flags.flag_precision != 0)
	{
		if (size >= flags.value_precision)
			write (1, s_res, size);
		if (size < flags.value_precision)
		{
			dif_arg = flags.value_precision - size;
			i_dif_arg = 0;
			while (i_dif_arg < dif_arg)
			{
				write (1, "0", 1);
				i_dif_arg++;
			}
			write (1, s_res, size);
		}
	}
	// если есть ширина, но нет точности
	if (flags.flag_width != 0 && flags.flag_precision == 0)
	{
		if (size >= flags.value_width)
			write (1, s_res, size);
		if (size < flags.value_width)
		{
			dif_arg = flags.value_width - size;
			i_dif_arg = 0;
			while (i_dif_arg < dif_arg)
			{
				write (1, " ", 1);
				i_dif_arg++;
			}
			write (1, s_res, size);
		}
	}
	// если есть ширина и точность
	if (flags.flag_width != 0 && flags.flag_precision != 0)
	{
		if (size >= flags.value_width && size >= flags.value_precision)
			write (1, s_res, size);
		if (flags.value_precision >= flags.value_width)
		{
			dif_arg = flags.value_precision - size;
			i_dif_arg = 0;
			while (i_dif_arg < dif_arg)
			{
				write (1, "0", 1);
				i_dif_arg++;
			}
			write (1, s_res, size);
		}
		if (flags.value_precision < flags.value_width)
		{
			dif_arg = flags.value_width - flags.value_precision;
			i_dif_arg = 0;
			while (i_dif_arg < dif_arg)
			{
				write (1, " ", 1);
				i_dif_arg++;
			}
			dif_arg = flags.value_precision - size;
			i_dif_arg = 0;
			while (i_dif_arg < dif_arg)
			{
				write (1, "0", 1);
				i_dif_arg++;
			}
			write (1, s_res, size);
		}
	}
}