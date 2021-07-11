#include "../ft_printf.h"

t_flags	new_parser_flags(const char *format, va_list args, int *i)
{
	t_flags			flags;
	int				res;

	res = 0;
	init_flag(&flags);
	while (format[*i] != '\0')
	{
		if (format[*i] == '0')
			parser_zero(&flags, i);
		if (format[*i] == '-')
			parser_minus(&flags, i);
		if (ft_isdigit(format[*i]) == 1)
			parser_width(&flags, (char *)format, i, args);
		if (format[*i] == '.')
			parser_dot(&flags, (char *)format, i, args);
		if (format[*i] == '%')
		{
			flags.type = format[*i];
			*i = *i + 1;
			break ;
		}
		if (is_type(format[*i]) == 1)
		{
			flags.type = format[*i];
			*i = *i + 1;
			break ;
		}
		*i = *i + 1;
	}
	return (flags);
}
