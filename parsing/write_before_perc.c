#include "../ft_printf.h"

void	write_before_perc(const char *format, int *i)
{
	if (format[*i] == '\0')
		return ;
	while (format[*i] != '%')
	{
		write(1, &format[*i], 1);
		*i = *i + 1;
	}
	*i = *i + 1;
}
