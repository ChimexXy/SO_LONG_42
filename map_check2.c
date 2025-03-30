/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozahnou <mozahnou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 22:43:50 by mozahnou          #+#    #+#             */
/*   Updated: 2025/03/30 02:13:01 by mozahnou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	wall_check1(x_game *game)
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

int	wall_check2(x_game *game)
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

int	map_checker_param(x_game *game)
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

int	map_checker_param2(x_game *game)
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
			write(1, "param check faild\n", 18);
			return (0);
		}
	}
	free(game->one_line_map);
	return (1);
}

int	check_new_map(char **map)
{
	int	x;
	int	y;
	int	c_check;
	int	e_check;

	y = 0;
	c_check = 0;
	e_check = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'C')
				c_check++;
			if (map[y][x] == 'E')
				e_check++;
			x++;
		}
		y++;
	}
	if (c_check > 1 || e_check > 0)
	{
		write(1, "Player can't passed to exit or take all coins\n", 46);
		return (0);
	}
	return (1);
}
