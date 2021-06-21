// если перед % есть текст - то выводим

#include "ft_printf.h"

void	processor(const char *format, struct s_flags flags, va_list args)
{
	int	i;

	i = 0;
	if (format[i] != '%')
	{
		while (format[i] != '%')
		{
			write (1, &format[i], 1);
			i++;
		}
	}
	write (1, "\n", 1);
	if (flags.type == 'd')
		d(flags, args);
	if (flags.type == 'c')
		c(flags, args);
	if (flags.type == 's')
		s(flags, args);
}
