#include "../ft_printf.h"

void	init_flag(t_flags *flags)
{
	flags->type = '-';
	flags->fl_w = 0;
	flags->val_w = 0;
	flags->fl_p = 0;
	flags->val_p = 0;
	flags->fl_m = 0;
	flags->fl_z = 0;
}
