#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	t_values	elem;

	init_values(&elem);
	va_start(elem.args, format);
	elem.format = format;
	while (*elem.format)
	{
		while (*elem.format && *elem.format != '%')
		{
			write(1, elem.format, 1);
			elem.format++;
			elem.len++;
		}
		if (*elem.format && *elem.format == '%')
		{
			elem.format++;
			pars_flags(&elem);
		}
	}
	va_end(elem.args);
	return (elem.len);
}
