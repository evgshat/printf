#include "../ft_printf.h"

int	write_before_perc(const char *format, int *i)
{
	int	res = 0;

	res = 0;
	if (format[*i] == '\0')
		return (res);
	while (format[*i] != '%')
	{
		write(1, &format[*i], 1);
		*i = *i + 1;
		res++;
	}
	*i = *i + 1;
	return (res);
}
