#include "../../ft_printf.h"

static int	u_w_over(t_flags flags, int size, char *s_res)
{
	int	sum_u;

	sum_u = 0;
	{
		sum_u += over_width_zero(flags.val_w, size);
		sum_u += write_d_s_res(s_res, size);
	}
	return (sum_u);
}

int	u_only_w(t_flags flags, char *s_res, int size)
{
	int	sum_u;

	sum_u = 0;
	if (flags.fl_w != 0 && flags.fl_p == 0)
	{
		if (size >= flags.val_w)
			sum_u += write_d_s_res(s_res, size);
		if (size < flags.val_w)
		{
			if (flags.fl_z != 0 && flags.fl_m == 0)
				sum_u += u_w_over(flags, size, s_res);
			if (flags.fl_m != 0 && flags.fl_z == 0)
			{
				sum_u += write_d_s_res(s_res, size);
				sum_u += over_width(flags.val_w, size);
			}
			if (flags.fl_m == 0 && flags.fl_z == 0)
			{
				sum_u += over_width(flags.val_w, size);
				sum_u += write_d_s_res(s_res, size);
			}
		}
	}
	return (sum_u);
}
