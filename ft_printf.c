#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list				args;
	int					res;
	int					res_w;
	int					i;

	res = 0;
	res_w = 0;
	i = 0;
	va_start(args, format);
	res_w = write_before_perc((char *)format, &i);
	res += processor(format, args, &i);
	res += res_w;
	return (res);
}
