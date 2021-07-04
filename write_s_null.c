#include "ft_printf.h"

int	write_s_null(char *s_res, int size)
{
	char	*s_null;
	int		sum_s;

	if (s_res == NULL)
	{
		s_null = (char *)malloc(sizeof(char) * 6);
		s_null = "(null)";
		write (1, s_null, 6);
		return (6);
	}
	else
	{
		write (1, s_res, size);
		sum_s = sum(size);
		return (sum_s);
	}
}