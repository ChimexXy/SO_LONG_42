/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozahnou <mozahnou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 21:22:04 by mozahnou          #+#    #+#             */
/*   Updated: 2025/03/20 21:24:05 by mozahnou         ###   ########.fr       */
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
	char **map;
	int len;
	int wid;
	int x;
	int y;
}	x_game;

// get_next_line
char	*get_next_line(int fd);
int		ft_strlen(char *str);
char	*ft_strdup(char *s);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_substr(char *string, int start, int len);
int		ft_find_new_line(char *str);
char	*ft_read_string(int fd, char *ret);
char	*ft_ret_line(char *line);
char	*ft_remind_val(char *string);

char	*ft_substr_2(char *str, int start, int end);
char	**ft_split(char *str);
int		ft_strlen(char *str);
int		ft_count_word(char *str);
void	check_name(char *name);
void	map_check1(x_game game, int fd);


#endif