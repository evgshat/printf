#include "../ft_printf.h"

void	parser_width(t_flags *flags, char *format, int *i, va_list args)
{
	char	*value_width;
	int		i_v;

	i_v = 0;
	flags->fl_w = 1;
	value_width = (char *)malloc(sizeof(char) * 20);
	if (format[*i] == '*')
	{
		flags->val_w = va_arg(args, int);
		if (flags->val_w < 0)
		{
			flags->val_w = flags->val_w * (-1);
			flags->fl_m = 1;
		}
		free (value_width);
		return ;
	}
	else
	{
		while (ft_isdigit(format[*i]) == 1)
		{
			value_width[i_v] = format[*i];
			i_v++;
			*i = *i + 1;
		}
		value_width[i_v] = '\0';
		flags->val_w = ft_atoi(value_width);
		free (value_width);
	}
}
