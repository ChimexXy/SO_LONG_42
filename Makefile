NAME = so_long
SRC = so_long.c utils1.c map_check1.c  split.c get_next_line.c \
		get_next_line_utils.c map_check2.c flood_fill.c\

OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ) so_long.h 
	$(CC) $(OBJ) -o $(NAME)

clean : 
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(NAME)

re : fclean all