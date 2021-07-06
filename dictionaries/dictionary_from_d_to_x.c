#include "../ft_printf.h"

char	dictionary_from_d_to_x(int ost)
{
	char	c_ost;

	if (ost == 0)
		c_ost = '0';
	if (ost >= 1 && ost <= 9)
		c_ost = ost + '0';
	if (ost == 10)
		c_ost = 'a';
	if (ost == 11)
		c_ost = 'b';
	if (ost == 12)
		c_ost = 'c';
	if (ost == 13)
		c_ost = 'd';
	if (ost == 14)
		c_ost = 'e';
	if (ost == 15)
		c_ost = 'f';
	return (c_ost);
}