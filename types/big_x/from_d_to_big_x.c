#include "../../ft_printf.h"

static int	less_sixsteen(int *int_chislo)
{
	char	*int_ch;
	int		cnt_int_ch;
	char	int_chh;
	int		res;

	int_ch = ft_itoa(*int_chislo);
	cnt_int_ch = ft_strlen(int_ch);
	free(int_ch);
	int_chh = dictionary_from_d_to_big_x(*int_chislo);
	res = write (1, &int_chh, 1);
	return (res);
}

int	from_d_to_big_x(unsigned long long chislo)
{
	int		ost;
	int		int_chislo;
	char	c_ost;
	int		sum_d_to_big_x;

	sum_d_to_big_x = 0;
	if (chislo < 16)
	{
		c_ost = dictionary_from_d_to_big_x(chislo);
		sum_d_to_big_x = write (1, &c_ost, 1);
		return (sum_d_to_big_x);
	}
	if (chislo >= 16)
	{
		int_chislo = chislo / 16;
		ost = chislo % 16;
		if (int_chislo >= 16)
			from_d_to_big_x(int_chislo);
		if (int_chislo < 16)
			sum_d_to_big_x += less_sixsteen(&int_chislo);
		c_ost = dictionary_from_d_to_big_x(ost);
		sum_d_to_big_x += write (1, &c_ost, 1);
	}
	return (sum_d_to_big_x);
}
