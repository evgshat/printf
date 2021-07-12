#include "../ft_printf.h"

void	pars_type(t_values *elem)
{
	if (*elem->format == 'c')
		elem->type = 'c';
	if (*elem->format == 's')
		elem->type = 's';
	if (*elem->format == 'p')
		elem->type = 'p';
	if (*elem->format == 'd')
		elem->type = 'd';
	if (*elem->format == 'i')
		elem->type = 'i';
	if (*elem->format == 'u')
		elem->type = 'u';
	if (*elem->format == 'x')
		elem->type = 'x';
	if (*elem->format == 'X')
		elem->type = 'X';
	if (*elem->format == '%')
		elem->type = '%';
	elem->format++;
	check_type(elem);
}

void	pars_precision(t_values *elem)
{
	if (*elem->format == '.')
	{
		elem->format++;
		elem->precision = ft_atoi(elem->format);
	}
	while (ft_isdigit(*elem->format))
		elem->format++;
	pars_type(elem);
}

void	pars_width(t_values *elem)
{
	elem->width = ft_atoi(elem->format);
	while (ft_isdigit(*elem->format))
		elem->format++;
	pars_precision(elem);
}

void	pars_flags(t_values *elem)
{
	while (*elem->format)
	{
		if (*elem->format == '-')
			elem->flag_minus = 1;
		else if (*elem->format == '+')
			elem->flag_plus = 1;
		else if (*elem->format == ' ')
			elem->flat_space = 1;
		else if (*elem->format == '#')
			elem->flag_grid = 1;
		else if (*elem->format == '0')
			elem->flag_zero = 1;
		else
			break ;
		elem->format++;
	}
	flag_ignor(elem);
	pars_width(elem);
}
