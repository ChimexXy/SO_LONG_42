/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozahnou <mozahnou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 22:43:50 by mozahnou          #+#    #+#             */
/*   Updated: 2025/04/05 13:46:59 by mozahnou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	wall_check1(t_game *game)
{
	int	y;

	y = 0;
	while (game->map[0][y])
	{
		if ((game->map[0][y] != '1') && (y < game->len_line))
			return (0);
		if (game->map[game->wid_line - 1][y] != '1' 
				&& game->map[game->wid_line - 1][y])
		{
			if (game->map[game->wid_line - 1][y] == '\n')
				return (1);
			return (0);
		}
		y++;
	}
	if (!wall_check2(game))
		return (0);
	return (1);
}

int	wall_check2(t_game *game)
{
	int	x;
	int	len;

	x = 1;
	len = game->len_line;
	while (game->map[x] && x < game->wid_line)
	{
		if (game->map[x][0] != '1' || game->map[x][len - 1] != '1')
			return (0);
		x++;
	}
	return (1);
}

int	map_checker_param(t_game *game)
{
	int	i;

	i = 0;
	game->coin = 0;
	game->exit = 0;
	game->player = 0;
	while (game->one_line_map[i])
	{
		if (game->one_line_map[i] == 'E')
			game->exit++;
		if (game->one_line_map[i] == 'P')
			game->player++;
		if (game->one_line_map[i] == 'C')
			game->coin++;
		i++;
	}
	if (game->exit != 1)
		return (0);
	if (game->player != 1)
		return (0);
	if (game->coin < 1)
		return (0);
	return (1);
}

int	map_checker_param2(t_game *game)
{
	int		i;
	char	*str;

	i = 0;
	str = game->one_line_map;
	while (str[i])
	{
		if (str[i] == '1' || str[i] == '0' || str[i] == 'P'
			|| str[i] == 'E' || str[i] == 'C' || str[i] == '\n')
			i++;
		else
		{
			pstr("Map Contains Wrong Param\n");
			free(game->one_line_map);
			return (0);
		}
	}
	free(game->one_line_map);
	return (1);
}

int	check_new_map(char **map, t_game *game)
{
	int	x;
	int	y;
	int	c_check;

	y = 0;
	c_check = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'C')
				c_check++;
			x++;
		}
		y++;
	}
	if (!(check_c(c_check)) 
		|| !(check_exit_2(map, game->exit_x, game->exit_y)))
		return (0);
	return (1);
}
