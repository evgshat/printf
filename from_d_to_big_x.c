#include "ft_printf.h"
#include "libft.h"

void	from_d_to_big_x(int chislo)
{
	int		ost;
	int		int_chislo;
	char	*int_ch;
	int		cnt_int_ch;
	char	c_ost;

	if (chislo < 16)
	{
		c_ost = dictionary_from_d_to_big_x(chislo);
		write (1, &c_ost, 1);
		return ;
	}
	if (chislo >= 16)
	{
		int_chislo = chislo / 16;
		ost = chislo % 16;
		if (int_chislo > 16)
			from_d_to_x(int_chislo);
		if (int_chislo < 16)
		{
			int_ch = ft_itoa(int_chislo);
			cnt_int_ch = ft_strlen(int_ch);
			write (1, int_ch, cnt_int_ch);
		}
		c_ost = dictionary_from_d_to_big_x(ost);
		write (1, &c_ost, 1);
	}
}