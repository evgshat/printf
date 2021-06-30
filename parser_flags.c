//cspdiuxX%

#include "ft_printf.h"

struct s_flags	parser_flags(const char **format, va_list args)
{
	struct s_flags	flags = {'-', 0, 0, 0, 0, 0, 0, 0};
	int				i;
	int				i_v;
	int				j;
	int				flag_for_type;
	const char		*point_dot;
	char			*value_width;


	j = 0;
	i = 0;
	i_v = 0;
	flag_for_type = 0;
	while (format[j][i] != '%')
		i++;
	i++;
	while (format[j][i] != '%' && format[j][i] != '\0')
	{
		if (format[j][i] == '0')
			flags.flag_zero = 1;
		if (format[j][i] >= '1' && format[j][i] <= '9')
		{
			flags.flag_width = 1;
			value_width = (char *)malloc(sizeof(char) * 20);
			while (format[j][i] >= '0' && format[j][i] <= '9')
			{
				value_width[i_v] = format[j][i];
				i_v++;
				i++;
			}
			value_width[i_v] = '\0';
			flags.value_width = ft_atoi(value_width);
			free (value_width);
		}
		if (format[j][i] == '*')
		{
			flags.flag_width = 1;
			flags.value_width = parser_width(args);
		}
		if (format[j][i] == '.')
		{
			i++;
			point_dot = &format[j][i];
			flags.flag_precision = 1;
			flags.value_precision = parser_dot(point_dot, args);
		}
		if (format[j][i] == '-')
			flags.flag_minus = 1;
		if (flag_for_type != 1)
		{
			if (format[j][i] == 'c' || format[j][i] == 's' || format[j][i] == 'p'
				|| format[j][i] == 'd' || format[j][i] == 'i' || format[j][i] == 'u'
				|| format[j][i] == 'x' || format[j][i] == 'X')
			{
				flags.type = format[j][i];
				flag_for_type = 1;
			}
		}
	i++;
	}
	*format = *format + i;
	return (flags);
}