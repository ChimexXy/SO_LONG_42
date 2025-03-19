/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozahnou <mozahnou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 21:22:04 by mozahnou          #+#    #+#             */
/*   Updated: 2025/03/19 12:53:00 by mozahnou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include <unistd.h>
#include <limits.h>
#include <fcntl.h>
#include <mlx.h>
#include "./ft_printf/ft_printf.h"
#include "./get_next_line/get_next_line.h"

typedef struct y_game{
	char **map;
	int len;
	int wid;
	int x;
	int y;
}	x_game;

char	**ft_split(char *str);
int		ft_strlen(char *str);
int		ft_count_word(char *str);

void check_name(char *name);


#endif