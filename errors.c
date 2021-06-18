#include "ft_printf.h"

int	errors(const char *format)
{
	int	i;
	int	flag;

	i = 0;
	flag = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '%')
			flag++;
		if (format[i] == 'c' || format[i] == 's' || format[i] == 'p'
			|| format[i] == 'd' || format[i] == 'i' || format[i] == 'u'
			|| format[i] == 'x' || format[i] == 'X')
			flag++;
		i++;
	}
	if (flag == 2)
		return (1);
	else
		return (0);
}