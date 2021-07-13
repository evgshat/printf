#include "../ft_printf.h"

int	is_type(char ch)
{
	if (ch == 'c' || ch == 's' || ch == 'p'
		|| ch == 'd' || ch == 'i' || ch == 'u'
		|| ch == 'x' || ch == 'X')
		return (1);
	else
		return (0);
}
