#include "../../ft_printf.h"

char	*res_for_s(va_list args, int *size)
{
	char	*s_res;

	s_res = va_arg(args, char *);
	while (1)
	{
		if (s_res == NULL || s_res == 0)
		{
			*size = 6;
			break ;
		}
		if (*s_res == '\0')
		{
			*size = 0;
			break ;
		}
		if (s_res != 0 && *s_res != '\0')
		{
			*size = ft_strlen(s_res);
			break ;
		}
	}
	return (s_res);
}
