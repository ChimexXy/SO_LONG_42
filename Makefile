NAME = so_long

CFLAGS	:= -Wextra -Wall -Werror -Wunreachable-code -Ofast

LIBMLX	:= ./MLX42

HEADERS	= -I $(LIBMLX)/include

LIBS := -lglfw -L"/Users/ychedmi/.brew/opt/glfw/lib" $(LIBMLX)/build/libmlx42.a -pthread -ldl -lm -framework Cocoa -framework OpenGL -framework IOKit

SRC = so_long.c utils1.c map_check1.c  split.c get_next_line.c \
		get_next_line_utils.c map_check2.c flood_fill.c utils2.c\

OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ) so_long.h 
	$(CC) $(OBJ) -o $(NAME)

clone:
	@git clone	https://github.com/codam-coding-college/MLX42.git

build:
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build
clean : 
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(NAME)

re : fclean all