// если перед % есть текст - то выводим

#include "ft_printf.h"

int	processor(const char *format, va_list args)
{
	int				i;
	int				res;
	struct s_flags	flags;
	const char		*for_parsing;
	int				flag_for_exit;

	i = 0;
	res = 0;
	flag_for_exit = 0;
	for_parsing = format;
	while (format[i] != '\0')
	{
		while (format[i] != '%')
		{
			if (format[i] == '\0')
			{
				flag_for_exit = 1;
				break ;
			}
			else
			{
				write (1, &format[i], 1);
				i++;
				res++;
			}
		}
		if (flag_for_exit == 1)
			break ;
		flags = parser_flags(&for_parsing, args);
		// printf("type = %c\nflag_width = %d\nvalue_width = %d\nflag_minus = %d\nflag_zero = %d\nflag_precision = %d\nvalue_precision = %d\nflag_star = %d\n",
		// flags.type, flags.flag_width,
		// flags.value_width, flags.flag_minus, flags.flag_zero,
		// flags.flag_precision, flags.value_precision, flags.flag_star);
		res = res + processor_type(flags, args);
		while (format[i] != flags.type)
		{
			i++;
		}
		i++;
	}
	return (res);
}