#include "ft_printf.h"

int	write_s_null(char *s_res, int size, int value_precision, int flag_presicion)
{
	char	*s_null;
	int		sum_s;

	if (s_res == NULL)
	{
		s_null = (char *)malloc(sizeof(char) * 6);
		s_null = "(null)";
		if (value_precision >= 6 || (value_precision == 0 && flag_presicion == 0))
			write (1, s_null, 6);
		else
		{
			write (1, s_null, value_precision);
		}
		return (6);
	}
	else
	{
		write (1, s_res, size);
		sum_s = sum(size);
		return (sum_s);
	}
}