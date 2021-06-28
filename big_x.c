#include "ft_printf.h"

void	big_x(struct s_flags flags, va_list args)
{
	int	chislo;
	int	size;

	chislo = va_arg(args, int);
	size = size_of_x(chislo);

	if (flags.flag_width == 0 && flags.flag_precision == 0)
		from_d_to_big_x(chislo);
	if (flags.flag_width == 0 && flags.flag_precision != 0)
	{
		if (size >= flags.value_precision)
			from_d_to_big_x(chislo);
		if (size < flags.value_precision)
		{
			over_percision(flags, size, flags.value_precision, size);
			from_d_to_big_x(chislo);
		}
	}
	if (flags.flag_width != 0 && flags.flag_precision == 0)
	{
		if (size >= flags.value_width)
			from_d_to_big_x(chislo);
		if (size < flags.value_width)
		{
			if (flags.flag_minus == 0 && flags.flag_zero != 0)
			{
				over_width_zero(flags, flags.value_width, size);
				from_d_to_big_x(chislo);
			}
			else
			{
				if (flags.flag_minus != 0)
				{
					from_d_to_big_x(chislo);
					over_width(flags, flags.value_width, size);
				}
				else
				{
					over_width(flags, flags.value_width, size);
					from_d_to_big_x(chislo);
				}
			}
		}
	}
	if (flags.flag_width != 0 && flags.flag_precision != 0)
	{
		if (size >= flags.value_width && size >= flags.value_precision)
		{
			from_d_to_big_x(chislo);
			return ;
		}
		if (flags.value_precision >= flags.value_width)
		{
			over_percision(flags, size, flags.value_precision, size);
			from_d_to_big_x(chislo);
		}
		if (flags.value_precision < flags.value_width)
		{
			if (flags.flag_minus != 0)
			{
				over_percision(flags, size, flags.value_precision, size);
				from_d_to_big_x(chislo);
				over_width(flags, flags.value_width, flags.value_precision);
			}
			else
			{
				over_width(flags, flags.value_width, flags.value_precision);
				over_percision(flags, size, flags.value_precision, size);
				from_d_to_big_x(chislo);
			}
		}
	}
}