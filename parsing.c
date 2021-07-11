#include "ft_printf.h"

static int	format_percent(char *format, va_list args, t_flags *flags, int *i)
{
	int	res;

	res = 0;
	if (format[*i + 1] == ' ')
	{
		write(1, " ", 1);
		res++;
		(*i)++;
	}
	*i = parse_flags(format, ++(*i), flags, args);
	if (is_type(format[*i]))
		res += processor((char *)flags, args);
	return (res);
}

int	parsing(char *format, va_list args)
{
	t_flags	flags;
	size_t	res;
	size_t	i;

	res = 0;
	i = 0;
	while (1)
	{
		flags_init(&flags);
		if (format[i] == '\0')
			break ;
		if (format[i] == '%')
			res += format_percent(format, args, &flags, &i);
		else
		{
			write(1, &format[i], 1);
			res++;
		}
		i++;
	}
	return (res);
}
