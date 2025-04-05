NAME = so_long

CFLAGS	:= -Wextra -Wall -Werror

SRC = so_long.c utils1.c map_check1.c  split.c get_next_line.c \
		get_next_line_utils.c map_check2.c flood_fill.c utils2.c\
		open_window.c palyer_move.c map_post.c map_check3.c\

OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ) so_long.h 
	$(CC) $(OBJ)  -lmlx -framework OpenGL -framework AppKit -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean : 
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(NAME)

re : fclean all