#include "ft_printf.h"

static int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	return (c);
}

static	size_t	ft_strlen(const char *s)
{
	size_t	c;

	c = 0;
	while (s[c])
		c++;
	return (c);
}

void	ft_put_base(unsigned int nbr, const char *base, \
		int hexa_type, int *count)
{
	unsigned int	base_len;

	base_len = ft_strlen(base);
	if (nbr == 4294967295 && !hexa_type)
	{
		*count += ft_putchar_fd('4', 1);
		*count += ft_putchar_fd('2', 1);
		nbr = 94967295;
	}
	if (nbr < base_len)
	{
		if (hexa_type == 2)
			*count += ft_putchar_fd(ft_toupper(base[nbr % base_len]), 1);
		else
			*count += ft_putchar_fd(base[nbr % base_len], 1);
		return ;
	}
	else
		ft_put_base(nbr / base_len, base, hexa_type, count);
	*count += ft_putchar_fd(base[nbr % base_len], 1);
}
