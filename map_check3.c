/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozahnou <mozahnou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 13:05:18 by mozahnou          #+#    #+#             */
/*   Updated: 2025/04/05 13:52:12 by mozahnou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	set_exit_position(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	game->exit_x = 0;
	game->exit_y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == 'E')
			{
				game->exit_x = x;
				game->exit_y = y;
				return ;
			}
			x++;
		}
		y++;
	}
}

int	check_exit_2(char **map, int x, int y)
{
	if (map[y][x + 1] != '.' && map[y][x - 1] != '.'
		&& map[y + 1][x] != '.' && map[y - 1][x] != '.')
	{
		pstr("Player Can't Passed The Exit\n");
		return (0);
	}
	return (1);
}
