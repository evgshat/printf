#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

typedef struct s_values
{
	const char	*format;
	va_list		args;
	int			len;
	int			flag_plus;
	int			flag_minus;
	int			flag_zero;
	int			flag_grid;
	int			flat_space;
	int			width;
	int			precision;
	char		type;
}				t_values;

/* ft_printf.c */
int		ft_printf(const char *format, ...);

/* writers.c */
int		flag_writer(int n, int zero);
int		space_writer(int n);
int		zero_writer(int n);

/* format_c.c */
void	format_c(t_values *elem);

/* format_s.c */
void	format_s(t_values *elem);

/* format_d_i.c */
void	format_d_i(t_values *elem);

/* format_u.c */
void	format_u(t_values *elem);

/* format_x.c */
void	format_x(t_values *elem);

/* format_p.c */
void	format_p(t_values *elem);

/* format_percent.c */
void	format_percent(t_values *elem);

/* values.c */
void	init_values(t_values *elem);
void	clear_values(t_values *elem);

/* checks.c */
void	check_type(t_values *elem);
void	flag_ignor(t_values *elem);
int		biggest(int x, int y);

/* parsing.c */
void	pars_flags(t_values *elem);
void	pars_width(t_values *elem);
void	pars_precision(t_values *elem);
void	pars_type(t_values *elem);

/* func */
int		ft_atoi(const char *s);
int		ft_isdigit(int c);
size_t	str_null_len(const char *str);
void	ft_putnbr(int n);
void	ft_putnbr_u(unsigned int n);
void	ft_puthex(unsigned int n, char type);
void	ft_putpoint(unsigned long n);

#endif
