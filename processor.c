// если перед % есть текст - то выводим

#include "ft_printf.h"

int	processor(const char *format, struct s_flags flags, va_list args)
{
	int	i;
	int	res;

	i = 0;
	if (format[i] != '%')
	{
		while (format[i] != '%')
		{
			write (1, &format[i], 1);
			i++;
		}
	}
	if (format[i+1] == '%')
		write (1, "%", 1);
	if (flags.type == 'd' || flags.type == 'i')
		d(flags, args);
	if (flags.type == 'c')
		res = c(flags, args);
	if (flags.type == 's')
		s(flags, args);
	if (flags.type == 'x')
		x(flags, args);
	if (flags.type == 'X')
		big_x(flags, args);
	if (flags.type == 'p')
		p(flags, args);
	if (flags.type == 'u')
		u(flags, args);

	return (res);
}
