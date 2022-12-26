#include "ft_printf.h"

void	ft_put_pointer(unsigned long long n, int *count)
{
	const char	*base;

	base = "0123456789abcdef";
	if (n < 16)
	{
		*count += ft_putchar_fd(base[n % 16], 1);
		return ;
	}
	else
		ft_put_pointer(n / 16, count);
	*count += ft_putchar_fd(base[n % 16], 1);
}
