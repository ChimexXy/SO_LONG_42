NAME = so_long
SRC = so_long.c utils1.c map_check1.c  split.c get_next_line.c \
		get_next_line_utils.c \
		

OBJ = $(SRC:.c=.o)
ARC = ft_printf/libftprintf.a

all : $(NAME)

$(NAME) : $(OBJ) so_long.h 
	$(CC) $(OBJ) $(ARC) -o $(NAME)

clean : 
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(NAME)

re : fclean all