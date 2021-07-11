#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		res;

	va_start(args, format);
	res = 0;
	res += parsing((char *)format, args);
	va_end(args);
	return (res);
}

// int	ft_printf(char const *format, ...)
// {
// 	va_list				args;
// 	int					res;
// 	int					i;
// 	int					er;

// 	res = 0;
// 	i = 0;
// 	va_start(args, format);
// 	er = errors(format);
// 	write_before_perc((char *)format, &i);
// 	res = processor(format, args, &i, &res);
// 	return (res);
// }

