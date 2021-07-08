#include "../ft_printf.h"

int	s(t_flags flags, va_list args)
{
	char	*s_res;
	int		size;
	int		sum_s;
	int		sum_w;
	int		sum_p;


	sum_s = 0;
	sum_w = 0;
	sum_p = 0;
	s_res = va_arg(args, char *);
	while (1)
	{
		if (s_res == NULL || s_res == 0)
		{
			size = 6;
			break ;
		}
		if (*s_res == '\0')
		{
			size = 0;
			break ;
		}
		if (s_res != 0 && *s_res != '\0')
		{
			size = ft_strlen(s_res);
			break ;
		}
	}
	if (flags.fl_w == 0 && flags.fl_p == 0) // нет ни точности, ни ширины
	{
		sum_s = write_s_null(s_res, size, flags.val_p, flags.fl_p);
	}
	if (flags.fl_w == 0 && flags.fl_p != 0) // есть только точность
	{
		if ((size <= flags.val_p) && flags.val_p != 0)
		{
			sum_s = write_s_null(s_res, size, flags.val_p, flags.fl_p);
		}
		if ((size > flags.val_p) && flags.val_p != 0)
		{
			if (s_res == NULL)
				sum_s = write_s_null(s_res, size, flags.val_p, flags.fl_p);
			else
				sum_s = write_s(flags.val_p, s_res);
		}
		if (flags.val_p == 0)
			return (sum_s + sum_w);
	}
	if (flags.fl_w != 0 && flags.fl_p == 0) // есть только ширина
	{
		if (size < flags.val_w)
		{
			if (flags.fl_m != 0)
			{
				sum_s = write_s_null(s_res, size, flags.val_p, flags.fl_p);
				if (s_res == NULL)
					sum_w = over_width(flags.val_w, 6);
				else
					sum_w = over_width(flags.val_w, size);
			}
			else
			{
				if (s_res == NULL)
					sum_w = over_width(flags.val_w, 6);
				else
					sum_w = over_width(flags.val_w, size);
				sum_s = write_s_null(s_res, size, flags.val_p, flags.fl_p);
			}
		}
		if (size >= flags.val_w)
			sum_s = write_s_null(s_res, size, flags.val_p, flags.fl_p);
	}
	if (flags.fl_w != 0 && flags.fl_p != 0) // есть точность и ширина
	{
		if (flags.val_p < size && flags.val_w < size)
		{
			if (flags.val_w > flags.val_p)
			{
				if (flags.fl_m == 0)
				{
					if (s_res == NULL)
					{
						sum_w = over_width(flags.val_w, flags.val_p);
						sum_s = write_s_null(s_res, size, flags.val_p, flags.fl_p);
					}
					else
					{
						sum_w = over_width(flags.val_w, flags.val_p);
						sum_s = write_s(flags.val_p, s_res);
					}
				}
				if (flags.fl_m != 0)
				{
					if (s_res == NULL)
					{
						sum_s = write_s_null(s_res, size, flags.val_p, flags.fl_p);
						sum_w = over_width(flags.val_w, flags.val_p);
					}
					else
					{
						sum_s = write_s(flags.val_p, s_res);
						sum_w = over_width(flags.val_w, flags.val_p);
					}
				}
			}
			if (flags.val_w < flags.val_p)
			{
				if (s_res == NULL)
				{
					sum_w = over_width(flags.val_w, 6);
					sum_s = write_s_null(s_res, size, flags.val_p, flags.fl_p);
				}
				else
				{
					sum_w = over_width(flags.val_w, flags.val_p);
					sum_s = write_s(flags.val_p, s_res);
				}
			}
			if (flags.val_w == flags.val_p)
			{
				if (s_res == NULL)
				{
					sum_w = over_width(flags.val_w, 6);
					sum_s = write_s_null(s_res, size, flags.val_p, flags.fl_p);
				}
				else
				{
					sum_w = over_width(flags.val_w, flags.val_p);
					sum_s = write_s(flags.val_p, s_res);
				}
			}
		}
		if (flags.fl_w < size && flags.fl_p > size)
		{
			sum_s = write_s(flags.val_p, s_res);
		}
		if (flags.val_w >= size && flags.val_p == size && size == 0)
		{
			sum_w = over_width(flags.val_w, flags.val_p);
		}
		if (flags.val_w >= size && flags.val_p < size) //  ширина больше сайза, а точность меньше
		{
			flags.fl_z = 0;
			if (flags.val_w > flags.val_p) // ширина больше точности
			{
				if (flags.fl_m == 0)
				{
					if (s_res == NULL)
					{
						if (flags.val_p == 0 && flags.fl_p == 1)
						{
							sum_w = over_width(flags.val_w, 0);
						}
						else
						{
							sum_w = over_width(flags.val_w, flags.val_p);
						}
						sum_s = write_s_null(s_res, size, flags.val_p, flags.fl_p);
					}
					else
					{
						sum_w = over_width(flags.val_w, flags.val_p);
						sum_s = write_s(flags.val_p, s_res);
					}
				}
				if (flags.fl_m != 0)
				{
					if (s_res != NULL)
					{
						sum_s = write_s(flags.val_p, s_res);
						sum_w = over_width(flags.val_w, flags.val_p);
					}
					if (s_res == NULL)
					{
						if (flags.val_p == 0)
							sum_w = over_width(flags.val_w, 0);
						if (flags.val_p != 0)
						{
							sum_s = write_s_null(s_res, size, flags.val_p, flags.fl_p);
							sum_w = over_width(flags.val_w, flags.val_p);
						}
					}
				}
			}
		}
		if (flags.val_w > size && flags.val_p > size) //ширина и точность больше сайза
		{
			flags.fl_z = 0;
			if (flags.val_w > flags.val_p && flags.val_p == size)
			{
				if (flags.fl_m != 0)
				{
					if (s_res != NULL)
					{
						sum_s = write_s(flags.val_p, s_res);
						sum_w = over_width(flags.val_w, size);
					}
					if (s_res == NULL)
					{
						sum_s = write_s_null(s_res, size, flags.val_p, flags.fl_p);
						sum_w = over_width(flags.val_w, size);
					}
				}
			}
			if (flags.val_w > flags.val_p && flags.val_p != size)
			{
				if (flags.fl_m == 0)
				{
					if (s_res == NULL)
					{
						sum_w = over_width(flags.val_w, 6);
						sum_s = write_s_null(s_res, size, flags.val_p, flags.fl_p);
					}
					else
					{
						sum_w = over_width(flags.val_w, size);
						sum_s = write_s(flags.val_p - 1, s_res);
					}
				}
				if (flags.fl_m != 0)
				{
					if (s_res != NULL)
					{
						sum_s = write_s(size, s_res);
						sum_w = over_width(flags.val_w, size);
					}
					if (s_res == NULL)
					{
						sum_s = write_s_null(s_res, size, flags.val_p, flags.fl_p);
						sum_w = over_width(flags.val_w, 6);
					}
				}
			}
			if (flags.val_w == flags.val_p)
			{
				if (s_res == NULL)
				{
					sum_w = over_width(flags.val_w, 6);
					sum_s = write_s_null(s_res, size, flags.val_p, flags.fl_p);
				}
				else
				{
					sum_w = over_width(flags.val_w, size);
					sum_s = write_s(size, s_res);
				}
			}
			if (flags.val_p > flags.val_w)
			{
				if (size == 0)
					sum_w = over_width(flags.val_w, size);
			}
		}
		if (flags.val_w < size && flags.val_p > size)
		{
			sum_s = write_s(size, s_res);
		}
		if (flags.val_w < size && flags.val_p == size)
		{
			sum_s = write_s(flags.val_p, s_res);
		}
		if (flags.val_w > size && flags.val_p == size && size != 0)
		{
			if (flags.fl_m == 0)
			{
				sum_w = over_width(flags.val_w, flags.val_p);
				sum_s = write_s(flags.val_p, s_res);
			}
			if (flags.fl_m != 0)
			{
				sum_s = write_s(flags.val_p, s_res);
				sum_w = over_width(flags.val_w, flags.val_p);
			}
		}
		// if (flags.val_w > size && flags.val_p == size)
		// {
		// 	sum_w = over_width(flags.val_w, flags.val_p);
		// 	sum_s = write_s(flags.val_p, s_res);
		// }
	}
	return (sum_s + sum_w);
}

// static char *s_hidden = "hi low\0don't print me lol\0";