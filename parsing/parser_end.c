#include "../ft_printf.h"

int	parser_end(char *format, va_list args, int *i)
{
	int	res;
	int	proc_res;

	res = 0;
	if (format[*i] == '%')
		proc_res = processor(format, args, i);
	while (format[*i] != '\0')
	{
		write (1, &format[*i], 1);
		res++;
		*i = *i + 1;
	}
	return (res);
}
