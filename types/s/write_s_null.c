#include "../../ft_printf.h"

int	write_s_null(char *s_res, int size, int val_p, int fl_p)
{
	char	*s_null;
	int		sum_s;

	if (s_res == NULL)
	{
		s_null = (char *)malloc(sizeof(char) * 6);
		s_null = "(null)";
		if (val_p >= 6 || (val_p == 0 && fl_p == 0))
			write (1, s_null, 6);
		else
			write (1, s_null, val_p);
		free(s_null); //
		return (6);
	}
	else
	{
		write (1, s_res, size);
		sum_s = sum(size);
		return (sum_s);
	}
}
