#include "../../ft_printf.h"
static int	u_w_zero_p_zero(t_flags flags, char *s_res, int size)
{
	int	sum_u;

	sum_u = 0;
	if (flags.fl_w == 0 && flags.fl_p == 0)
		sum_u += write_d_s_res(s_res, size);
	return (sum_u);
}

static int	u_only_p(t_flags flags, char *s_res, int size)
{
	int	sum_u;

	sum_u = 0;
	if (flags.fl_w == 0 && flags.fl_p != 0)
	{
		if (size >= flags.val_p)
		{
			sum_u += write (1, s_res, size);
			// sum_u += sum(size);
		}
		if (size < flags.val_p)
		{
			sum_u += over_percision(flags.val_p, size);
			sum_u += write (1, s_res, size);
			// sum_u += sum(size);
		}
	}
	return (sum_u);
}

static int	u_fp_is_vp_zero(t_flags flags, int size)
{
	int	sum_u;

	sum_u = 0;
	if (flags.val_w > size)
	{
		flags.fl_z = 0;
		if (flags.val_w > flags.val_p)
		{
			if (flags.fl_m == 0)
				sum_u += over_width(flags.val_w, (size - 1));
			if (flags.fl_m != 0)
				sum_u += over_width(flags.val_w, (size - 1));
		}
	}
	return (sum_u);
}

int	u(struct s_flags flags, va_list args)
{
	int					size;
	char				*s_res;
	int					sum_u;

	sum_u = 0;
	size = 0;
	s_res = res_for_u(args, &size);
	sum_u += u_w_zero_p_zero(flags, s_res, size);
	if (flags.fl_p == 1 && flags.val_p == 0)
	{
		sum_u += u_fp_is_vp_zero(flags, size);
		return (1);
	}
	sum_u += u_only_p(flags, s_res, size);
	sum_u += u_only_w(flags, s_res, size);
	sum_u += u_w_and_p(flags, size, s_res);
	free(s_res); //
	return (sum_u);
}
