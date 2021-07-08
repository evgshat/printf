#include "../../ft_printf.h"

static void	u_w_over(t_flags flags, int size, char *s_res)
{
	{
		over_width_zero(flags.val_w, size);
		write_d_s_res(s_res, size);
	}
}

int	u_only_w(t_flags flags, char *s_res, int size)
{
	int	sum_d;

	sum_d = 0;
	if (flags.fl_w != 0 && flags.fl_p == 0)
	{
		if (size >= flags.val_w)
			write_d_s_res(s_res, size);
		if (size < flags.val_w)
		{
			if (flags.fl_z != 0 && flags.fl_m == 0)
				u_w_over(flags, size, s_res);
			if (flags.fl_m != 0 && flags.fl_z == 0)
			{
				write_d_s_res(s_res, size);
				over_width(flags.val_w, size);
			}
			if (flags.fl_m == 0 && flags.fl_z == 0)
			{
				over_width(flags.val_w, size);
				write_d_s_res(s_res, size);
			}
		}
	}
	return (sum_d);
}
