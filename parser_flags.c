//cspdiuxX%

#include "ft_printf.h"

struct s_flags	parser_flags(const char *format, va_list args)
{
	struct s_flags	flags = {'-', 0, 0, 0, 0, 0, 0, 0};
	int				i;
	const char		*point_dot;

	if (format[i] != '%')
	{
		while (format[i] != '%')
			i++;
	}
	while (format[i] != '\0')
	{
		if (format[i] == '0')
			flags.flag_zero = 1;
		if (format[i] >= '1' && format[i] <= '9')
		{
			flags.flag_width = 1;
			flags.value_width = format[i] - '0';
		}
		if (format[i] == '*')
		{
			flags.flag_width = 1;
			flags.value_width = parser_width(args);
		}
		if (format[i] == '.')
		{
			i++;
			point_dot = &format[i];
			flags.flag_precision = 1;
			flags.value_precision = parser_dot(point_dot, args);
		}
		if (format[i] == '-')
			flags.flag_minus = 1;
		if (format[i] == 'c' || format[i] == 's' || format[i] == 'p'
			|| format[i] == 'd' || format[i] == 'i' || format[i] == 'u'
			|| format[i] == 'x' || format[i] == 'X')
		{
			flags.type = format[i];
		}
	i++;
	}
	return (flags);
}
