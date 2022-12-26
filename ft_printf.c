#include "ft_printf.h"

static int	replace(char c, va_list argumentptr)
{
	int	count;

	count = 0;
	if (c == 'c')
		count += ft_putchar_fd(va_arg(argumentptr, int), 1);
	else if (c == 's')
		count += ft_putstr_fd(va_arg(argumentptr, char *), 1);
	else if (c == 'p')
	{
		count += ft_putstr_fd("0x", 1);
		ft_put_pointer(va_arg(argumentptr, unsigned long long), &count);
	}
	else if (c == 'd' || c == 'i')
		ft_putnbr_fd(va_arg(argumentptr, int), 1, &count);
	else if (c == 'u')
		ft_put_base(va_arg(argumentptr, unsigned int), "0123456789", 0, &count);
	else if (c == 'x')
		ft_put_base(va_arg(argumentptr, unsigned int), \
				"0123456789abcdef", 1, &count);
	else if (c == 'X')
		ft_put_base(va_arg(argumentptr, unsigned int), \
				"0123456789ABCDEF", 2, &count);
	else if (c == '%')
		count += ft_putchar_fd('%', 1);
	return (count);
}

static int	find_format(const char *str, va_list argumentptr)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == '%' && str[i + 1])
		{
			while (str[++i] == ' ')
				;
			if (!str[i])
				return (-1);
			count += replace(str[i], argumentptr);
		}
		else
			count += ft_putchar_fd(str[i], 1);
		i++;
	}
	return (count);
}

int	ft_printf(const char *str, ...)
{
	va_list	argumentptr;
	int		count;

	va_start(argumentptr, str);
	count = 0;
	count += find_format(str, argumentptr);
	va_end(argumentptr);
	return (count);
}
