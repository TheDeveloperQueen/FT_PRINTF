NAME=libftprintf.a
FLAGS=-Wall -Wextra -Werror

FUNCTIONS=	aux_char.c \
			aux_nbr.c \
			ft_printf.c

OBJ= $(FUNCTIONS:%.c=%.o)

all: $(NAME)
$(NAME): $(OBJ)
	ar crs $(NAME) $^

%.o: %.c
	cc $(FLAGS) -c $<

clean:
	@rm -rf $(OBJ)
fclean: clean
	@rm -rf $(NAME)
re: fclean $(NAME)

.PHONY: all clean fclean re