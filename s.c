#include "ft_printf.h"

void	s(struct s_flags flags, va_list args)
{
	char	*s_res;
	size_t	size;
	int		dif_arg;
	int		i_dif_arg;

	s_res = va_arg(args, char *);
	size = ft_strlen(s_res);
	if (flags.flag_width == 0 && flags.flag_precision == 0)
	{
		write (1, s_res, size);
	}
	// как в d.c (вроде)
	if (flags.flag_width != 0 && flags.flag_precision == 0)
	{
		if (size >= flags.value_width)
			write (1, s_res, size);
		if (size < flags.value_width)
		{
			dif_arg = flags.value_width - size;
			i_dif_arg = 0;
			while (i_dif_arg < dif_arg)
			{
				write (1, " ", 1);
				i_dif_arg++;
			}
			write (1, s_res, size);
		}
	}
	if (flags.flag_width == 0 && flags.flag_precision != 0)
	{
		if (size <= flags.value_precision)
			write (1, s_res, size);
		if (size > flags.value_precision)
		{
			i_dif_arg = 0;
			while (i_dif_arg < flags.value_precision)
			{
				write (1, &s_res[i_dif_arg], 1);
				i_dif_arg++;
			}
		}
	}
	if (flags.flag_width != 0 && flags.flag_precision != 0)
	{
		if (flags.value_width <= flags.value_precision)
		{
			i_dif_arg = 0;
			while (i_dif_arg < flags.value_precision)
			{
				write (1, &s_res[i_dif_arg], 1);
				i_dif_arg++;
			}
		}
		// как в d.c
		if (flags.value_width > flags.value_precision)
		{
			dif_arg = flags.value_width - flags.value_precision;
			i_dif_arg = 0;
			while (i_dif_arg < dif_arg)
			{
				write (1, " ", 1);
				i_dif_arg++;
			}
			i_dif_arg = 0;
			while (i_dif_arg < flags.value_precision)
			{
				write (1, &s_res[i_dif_arg], 1);
				i_dif_arg++;
			}
		}
	}
}