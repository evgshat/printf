#include "../../ft_printf.h"

void	write_for_s(struct s_flags flags, char	*s_res)
{
	int	i_dif_arg;

	i_dif_arg = 0;
	while (i_dif_arg < flags.val_p)
	{
		write (1, &s_res[i_dif_arg], 1);
		i_dif_arg++;
	}
}
