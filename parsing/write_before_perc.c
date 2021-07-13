#include "../ft_printf.h"

int	write_before_perc(const char *format, int *i)
{
	int	res;

	res = 0;
	if (format[*i] == '\0')
		return (res);
	while (format[*i] != '%')
	{
		if (format[*i] == '\0')
			return (res);
		write(1, &format[*i], 1);
		*i = *i + 1;
		res++;
	}
	*i = *i + 1;
	return (res);
}
