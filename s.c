#include "ft_printf.h"

void	s(struct s_flags flags, va_list args)
{
	char	*s_res;
	int		size;

	s_res = va_arg(args, char *);
	size = ft_strlen(s_res);
	if (flags.flag_width == 0 && flags.flag_precision == 0)
		write (1, s_res, size);
	if (flags.flag_width != 0 && flags.flag_precision == 0)
	{
		if (size >= flags.value_width)
			write (1, s_res, size);
		if (size < flags.value_width)
		{
			over_width(flags, size, flags.value_width, size);
			write (1, s_res, size);
		}
	}
	if (flags.flag_width == 0 && flags.flag_precision != 0)
	{
		if (size <= flags.value_precision)
			write (1, s_res, size);
		if (size > flags.value_precision)
			write_for_s(flags, s_res);
	}
	if (flags.flag_width != 0 && flags.flag_precision != 0)
	{
		if (flags.value_width <= flags.value_precision)
			write_for_s(flags, s_res);
		if (flags.value_width > flags.value_precision)
		{
			over_width(flags, size, flags.value_width, flags.value_precision);
			write_for_s(flags, s_res);
		}
	}
}