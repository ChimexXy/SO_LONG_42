/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozahnou <mozahnou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 22:47:06 by mozahnou          #+#    #+#             */
/*   Updated: 2025/03/23 02:25:28 by mozahnou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	set_player_position(x_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == 'P')
			{
				game->player_pos_x = x;
				game->player_pos_y = y;
				return ;
			}
			x++;
		}
		y++;
	}
}

int	flood_fill(x_game *game, char **map)
{
	// int	x;
	// int	y;

	// x = 0;
	// y = 0;
	set_player_position(game);
	printf("%d , %d \n", game->player_pos_y, game->player_pos_x);
	return (1);
}