#include "../ft_printf.h"

void	parser_zero(t_flags *flags, int *i)
{
	flags->fl_z = 1;
	*i = *i + 1;
}