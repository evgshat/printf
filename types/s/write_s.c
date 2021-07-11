#include "../../ft_printf.h"

int	write_s(int p, char *s_res)
{
	char	*s_null;
	int		i_dif_arg;

	i_dif_arg = 0;
	if (s_res == NULL)
	{
		s_null = (char *)malloc(sizeof(char) * 6);
		s_null = "(null)";
		write (1, s_null, 6);
		return (6);
	}
	while (i_dif_arg < p)
	{
		write (1, s_res, 1);
		i_dif_arg++;
		s_res++;
	}
	return (p);
}
