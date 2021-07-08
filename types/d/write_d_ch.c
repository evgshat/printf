#include "../../ft_printf.h"

int	write_d_ch(char ch)
{
	write (1, &ch, 1);
	return (1);
}
