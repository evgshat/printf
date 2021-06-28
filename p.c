#include "ft_printf.h"

void	p(struct s_flags flags, va_list args)
{
	int	chislo;
	int	size;

	chislo = va_arg(args, int);
	size = size_of_x(chislo) + 2;
	if (flags.flag_width == 0 && flags.flag_precision == 0)
		from_d_to_p(chislo);
	if (flags.flag_width != 0 && flags.flag_precision == 0)
	{
		if (size >= flags.value_width)
			from_d_to_p(chislo);
		if (size < flags.value_width)
		{
			if (flags.flag_minus != 0)
			{
				from_d_to_p(chislo);
				over_width(flags, flags.value_width, size);
			}
			else
			{
				over_width(flags, flags.value_width, size);
				from_d_to_p(chislo);
			}
		}
	}
if (flags.flag_width != 0 && flags.flag_precision != 0)
	{
		if (size >= flags.value_width && size >= flags.value_precision)
		{
			from_d_to_x(chislo);
			return;
		}
		if (flags.value_precision >= flags.value_width)
		{
			over_percision(flags, size, flags.value_precision, size);
			from_d_to_x(chislo);
		}
		if (flags.value_precision < flags.value_width)
		{
			if (flags.flag_minus != 0)
			{
				over_percision(flags, size, flags.value_precision, size);
				from_d_to_x(chislo);
				over_width(flags, flags.value_width, flags.value_precision);
			}
			else
			{
				over_width(flags, flags.value_width, flags.value_precision);
				over_percision(flags, size, flags.value_precision, size);
				from_d_to_x(chislo);
			}
		}
	}
}