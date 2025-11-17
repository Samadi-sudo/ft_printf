NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC =	ft_printf.c\
	ft_print_num.c\
	print_char.c\
	ft_print_hexa.c\
	ft_helper.c\
	flags_char.c\
	flags_x.c\
	flags_xx.c\
	flags_adress.c\
	flags_adress_2.c\
	flags_str.c\
	flag_signed.c\
	flags_unsigned.c\
	ft_helper_2.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

%.o : %.c ft_printf.h
	$(CC) $(CFLAGS) -c $< -o $@

bonus :	$(NAME)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all

.PHONY:	all clean fclean re bonus
