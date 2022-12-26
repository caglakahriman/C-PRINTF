#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>

int		ft_printf(const char *str, ...);
void	ft_put_base(unsigned int n, \
		const char *base, int hexa_type, int *count);
void	ft_put_pointer(unsigned long long n, int *count);
int		ft_putchar_fd(char c, int fd);
void	ft_putnbr_fd(int n, int fd, int *count);
int		ft_putstr_fd(char *s, int fd);

#endif
