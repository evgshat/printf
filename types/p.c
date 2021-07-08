#include "../ft_printf.h"

int	p(struct s_flags flags, va_list args)
{
	int		chislo;
	int		size;
	int		sum_po;
	int		sum_w;
	int		sum_p;

	sum_po = 0;
	sum_w = 0;
	sum_p = 0;
	chislo = va_arg(args, int);
	size = size_of_x(chislo) + 2;
	if (flags.fl_w == 0 && flags.fl_p == 0)
	{
		sum_po = from_d_to_p(chislo);
	}
	if (flags.fl_w != 0 && flags.fl_p == 0)
	{
		if (size >= flags.val_w)
			sum_po = from_d_to_p(chislo);
		if (size < flags.val_w)
		{
			if (flags.fl_m != 0)
			{
				sum_po = from_d_to_p(chislo);
				sum_w = over_width(flags.val_w, size);
			}
			else
			{
				sum_w = over_width(flags.val_w, size);
				sum_po = from_d_to_p(chislo);
			}
		}
	}
	if (flags.fl_w != 0 && flags.fl_p != 0)
	{
		if (size >= flags.val_w && size >= flags.val_p)
		{
			sum_po = from_d_to_x(chislo);
			return (sum_po + sum_w + sum_p);
		}
		if (flags.val_p >= flags.val_w)
		{
			sum_p = over_percision(flags.val_p, size);
			sum_po = from_d_to_x(chislo);
		}
		if (flags.val_p < flags.val_w)
		{
			if (flags.fl_m != 0)
			{
				sum_p = over_percision(flags.val_p, size);
				sum_po = from_d_to_x(chislo);
				sum_w = over_width(flags.val_w, flags.val_p);
			}
			else
			{
				sum_w = over_width(flags.val_w, flags.val_p);
				sum_p = over_percision(flags.val_p, size);
				sum_po = from_d_to_x(chislo);
			}
		}
	}
	return (sum_po + sum_w + sum_p);
}