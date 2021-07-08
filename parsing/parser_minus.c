#include "../ft_printf.h"

void	parser_minus(t_flags *flags, int *i)
{
	flags->fl_m = 1;
	*i = *i + 1;
}