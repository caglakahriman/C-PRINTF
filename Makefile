NAME = libftprintf.a

SRCS = ft_put_pointer.c \
	   ft_putchar_fd.c \
	   ft_putnbr_fd.c \
	   ft_putstr_fd.c \
	   ft_put_base.c \
	   ft_printf.c \

CC = gcc

FLAGS = -Wall -Werror -Wextra

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME) : $(OBJS)
	ar -rcs $(NAME) $(OBJS)

%.o : %.c
	$(CC) $(FLAGS) -c $< -o $@

clean: 
	rm -rf $(OBJS)
fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
		
