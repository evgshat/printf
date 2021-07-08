// #include "libft.h"
#include "ft_printf.h"

int	ft_isdigit(int ch)
{
	int	res;

	res = 0;
	if (ch >= '0' && ch <= '9')
		res = 1;
	return (res);
}