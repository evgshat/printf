#include "../ft_printf.h"

int	parser_end(char *format, va_list args, int *i)
{
	int	res;

	res = 0;
	if (format[*i] == '\0')
		return (0);
	while (format[*i] != '%')
	{
		if (format[*i] == '\0')
			return (0);
		write (1, &format[*i], 1);
		res++;
		*i = *i + 1;
	}
	if (format[*i] == '%')
	{
		*i = *i + 1;
		res += processor(format, args, i, &res);
	}
	while (format[*i] != '\0')
	{
		write (1, &format[*i], 1);
		res += 1;
		*i = *i + 1;
	}
	return (res);
}
