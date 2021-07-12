#include "../../ft_printf.h"

int	write_s_null(char *s_res, int size, int val_p, int fl_p)
{
	char	*s_null;
	int		sum_s;

	s_null = "(null)";
	if (s_res == NULL)
	{
		if (val_p >= 6 || (val_p == 0 && fl_p == 0))
		{
			write (1, s_null, 6);
			return (6);
		}
		else
			write (1, s_null, val_p);
		return (val_p);
	}
	else
	{
		sum_s = write (1, s_res, size);
		return (sum_s);
	}
}
