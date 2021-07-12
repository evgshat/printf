#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list				args;
	int					res;
	int					i;

	res = 0;
	i = 0;
	va_start(args, format);
	res += write_before_perc((char *)format, &i);
	res += processor(format, args, &i);
	return (res);
}
