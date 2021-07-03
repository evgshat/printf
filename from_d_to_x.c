#include "ft_printf.h"
#include "libft.h"

int	from_d_to_x(int chislo)
{
	int		ost;
	int		int_chislo;
	char	*int_ch;
	int		cnt_int_ch;
	char	c_ost;
	int		sum_d_to_x;
	char	int_chh;

	sum_d_to_x = 0;
	if (chislo == 0)
		return (0);
	if (chislo < 16)
	{
		c_ost = dictionary_from_d_to_x(chislo);
		write (1, &c_ost, 1);
		sum_d_to_x = 1;
		return (sum_d_to_x);
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
			int_chh = dictionary_from_d_to_x(int_chislo); //
			write (1, &int_chh, cnt_int_ch);
			sum_d_to_x = sum_d_to_x + sum(1);
		}
		c_ost = dictionary_from_d_to_x(ost);
		write (1, &c_ost, 1);
		sum_d_to_x = sum_d_to_x + sum(1);
	}
	return (sum_d_to_x);
}