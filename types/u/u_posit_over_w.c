#include "../../ft_printf.h"

static int	u_posit_minus(t_flags flags, int size, char *s_res)
{
	int	sum_u;

	sum_u = 0;
	if (flags.val_p == 0 && *s_res == '0')
		sum_u += over_width(flags.val_w, 0);
	else
	{
		sum_u += over_width(flags.val_w, size);
		sum_u += write(1, s_res, size);
	}
	return (sum_u);
}

static int	u_posit_not_minus(t_flags flags, int size, char *s_res)
{
	int	sum_u;

	sum_u = 0;
	if (flags.val_p == 0 && *s_res == '0')
		sum_u += over_width(flags.val_w, 0);
	else
	{
		sum_u += write(1, s_res, size);
		sum_u += over_width(flags.val_w, size);
	}
	return (sum_u);
}

int	u_posit_over_w(t_flags flags, int size, char *s_res)
{
	int	sum_u;

	sum_u = 0;
	flags.fl_z = 0;
	if (flags.val_w > flags.val_p)
	{
		if (flags.fl_m == 0)
			sum_u += u_posit_minus(flags, size, s_res);
		if (flags.fl_m != 0)
			sum_u += u_posit_not_minus(flags, size, s_res);
	}
	return (sum_u);
}
