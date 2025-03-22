/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozahnou <mozahnou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 21:22:04 by mozahnou          #+#    #+#             */
/*   Updated: 2025/03/22 18:13:45 by mozahnou         ###   ########.fr       */
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
#include "./ft_printf/ft_printf.h"

typedef struct y_game{
	char 	**map;
	char 	*one_line_map;
	int 	len_line;
	int 	wid_line;
	int 	x;
	int 	y;
	int		coin;
	int		player;
	int 	exit;
	
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

char	*ft_substr_2(char *str, int start, int end);
char	**ft_split(char *str, char sep);
int		ft_count_word(char *str, char sep);
void	check_name(char *name);
void	map_read_line(char *av, x_game *game, int fd);
void	map_check_len(x_game *game);
void	count_line(char *av, x_game *game);
void	wall_check(x_game *game);
void	map_checker_param(x_game *game);

//utils
int		ft_strlen(char *str);
int		ft_strlen2(char *str);
void	*ft_calloc(size_t count, size_t size);
void	ft_bzero(void *s, size_t n);

#endif