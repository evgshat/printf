#include "../ft_printf.h"

void	parser_dot(t_flags *flags, char *format, int *i, va_list args)
{
	char	*val_p;
	int		i_v;

	*i = *i + 1;
	i_v = 0;
	flags->fl_p = 1;
	if (format[*i] == '*')
		flags->val_p = va_arg(args, int);
	while (ft_isdigit(format[*i]) == 1)
	{
		val_p = (char *)malloc(sizeof(char) * 20);
		val_p[i_v] = format[*i];
		i_v++;
		*i = *i + 1;
		val_p[i_v] = '\0';
		flags->val_p = ft_atoi(val_p);
		free (val_p);
	}
}
