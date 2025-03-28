/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozahnou <mozahnou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 21:22:04 by mozahnou          #+#    #+#             */
/*   Updated: 2025/03/28 05:26:19 by mozahnou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10

#endif


#include <unistd.h>
#include <stdlib.h>
#include <limits.h>
#include <fcntl.h>
#include <stdio.h>
#include <mlx.h>

typedef struct mlx_game{
	char **map;
	void *mlx_init;
	void *mlx_win;
	char	*wall;
	char	*coin;
	char	*player;
	char	*exit1;
	char	*exit2;
	void	*img_wall;
	void	*img_coin;
	void	*img_player;
	void	*img_exit1;
	void	*img_exit2;
	int		img_len;
	int		img_wid;
	int		x_p;
	int		y_p;
} mlx_s;

typedef struct y_game{
	char 	**map;
	char 	*one_line_map;
	int 	len_line;
	int 	wid_line;
	int		player_pos_x;
	int		player_pos_y;
	int		coin;
	int		player;
	int 	exit;
	int		flood_coin;
	int 	flood_exit;
	int		x;
	int		y;
}	x_game;

// get_next_line
char	*get_next_line(int fd);
char	*ft_strdup(char *s);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_substr(char *string, int start, int len);
int		ft_find_new_line(char *str);
char	*ft_read_string(int fd, char *ret);
char	*ft_ret_line(char *line);
char	*ft_remind_val(char *string);

//map_parsing
int		check_name(char *name);
int		map_read_line(char *av, x_game *game, int fd);
int		map_check_len(x_game *game);
void	count_line(char *av, x_game *game);
int		wall_check1(x_game *game);
int		wall_check2(x_game *game);
int		join_map(x_game *game);
int		map_checker_param(x_game *game);
int		map_checker_param2(x_game *game);
int		map_checking(char *av, x_game *game, int fd);
int		check_new_map(char **map);

//flood fill
void	flood_fill(char **map, int x, int y);
void	set_player_position(x_game *game);
int		map_flood(x_game *game);

//utils
int		ft_strlen(char *str);
char	**ft_split(char *str, char sep);
char	*ft_substr_2(char *str, int start, int end);
int		ft_count_word(char *str, char sep);
int		ft_strlen2(char *str);
void	*ft_calloc(size_t count, size_t size);
void	ft_bzero(void *s, size_t n);
void	free_double_pointer(char **array);

// mlx
void	window_open(mlx_s *mlx, x_game *game);
void	select_img(mlx_s *mlx);
void	map_post(mlx_s *mlx);
void	map_post2(mlx_s *mlx, int x, int y);

#endif