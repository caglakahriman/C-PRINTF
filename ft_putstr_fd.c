#include "ft_printf.h"

int	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	if (!s)
	{
		i = ft_putstr_fd("(null)", 1);
		return (i);
	}
	while (s[i])
	{
		ft_putchar_fd(s[i], fd);
		i++;
	}	
	return (i);
}
