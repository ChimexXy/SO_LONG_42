/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   palyer_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozahnou <mozahnou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 07:40:47 by mozahnou          #+#    #+#             */
/*   Updated: 2025/03/28 08:38:43 by mozahnou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_exit_unlock(mlx_s *mlx)
{
	int x, y;

	if (mlx->count_coin > 0)
		return;
	y = 0;
	while (mlx->map[y])
	{
		x = 0;
		while (mlx->map[y][x])
		{
			if (mlx->map[y][x] == 'E') // Change 'E' to 'O' (Open Exit)
				mlx->map[y][x] = 'Z';
			x++;
		}
		y++;
	}
}


void	move_left(mlx_s *mlx)
{
	if (mlx->map[mlx->y_p][mlx->x_p - 1] == '1') // Wall
		return;
	if (mlx->map[mlx->y_p][mlx->x_p - 1] == 'C') // Coin
		mlx->count_coin--;
	if (mlx->map[mlx->y_p][mlx->x_p - 1] == 'E' && mlx->count_coin > 0) // Locked exit
		return;
	if (mlx->map[mlx->y_p][mlx->x_p - 1] == 'Z') // Open exit
		exit(0);

	mlx->map[mlx->y_p][mlx->x_p] = '0'; // Remove player from old position
	mlx->x_p -= 1;
	mlx->map[mlx->y_p][mlx->x_p] = 'P';

	check_exit_unlock(mlx); // Check if exit should unlock
	mlx_clear_window(mlx->mlx_init, mlx->mlx_win);
	map_post(mlx);
}

void	move_right(mlx_s *mlx)
{
	if (mlx->map[mlx->y_p][mlx->x_p + 1] == '1')
		return;
	if (mlx->map[mlx->y_p][mlx->x_p + 1] == 'C')
		mlx->count_coin--;
	if (mlx->map[mlx->y_p][mlx->x_p + 1] == 'E' && mlx->count_coin > 0)
		return;
	if (mlx->map[mlx->y_p][mlx->x_p + 1] == 'Z')
		exit(0);

	mlx->map[mlx->y_p][mlx->x_p] = '0';
	mlx->x_p += 1;
	mlx->map[mlx->y_p][mlx->x_p] = 'P';

	check_exit_unlock(mlx);
	mlx_clear_window(mlx->mlx_init, mlx->mlx_win);
	map_post(mlx);
}

void	move_up(mlx_s *mlx)
{
	if (mlx->map[mlx->y_p - 1][mlx->x_p] == '1')
		return;
	if (mlx->map[mlx->y_p - 1][mlx->x_p] == 'C')
		mlx->count_coin--;
	if (mlx->map[mlx->y_p - 1][mlx->x_p] == 'E' && mlx->count_coin > 0)
		return;
	if (mlx->map[mlx->y_p - 1][mlx->x_p] == 'Z')
		exit(0);

	mlx->map[mlx->y_p][mlx->x_p] = '0';
	mlx->y_p -= 1;
	mlx->map[mlx->y_p][mlx->x_p] = 'P';

	check_exit_unlock(mlx);
	mlx_clear_window(mlx->mlx_init, mlx->mlx_win);
	map_post(mlx);
}

void	move_down(mlx_s *mlx)
{
	if (mlx->map[mlx->y_p + 1][mlx->x_p] == '1')
		return;
	if (mlx->map[mlx->y_p + 1][mlx->x_p] == 'C')
		mlx->count_coin--;
	if (mlx->map[mlx->y_p + 1][mlx->x_p] == 'E' && mlx->count_coin > 0)
		return;
	if (mlx->map[mlx->y_p + 1][mlx->x_p] == 'Z')
		exit(0);

	mlx->map[mlx->y_p][mlx->x_p] = '0';
	mlx->y_p += 1;
	mlx->map[mlx->y_p][mlx->x_p] = 'P';

	check_exit_unlock(mlx);
	mlx_clear_window(mlx->mlx_init, mlx->mlx_win);
	map_post(mlx);
}




// void	move_left(mlx_s *mlx)
// {
// 	if ((mlx->map[mlx->y_p][mlx->x_p - 1] != '1')
// 		&& (mlx->map[mlx->y_p][mlx->x_p - 1] != 'E'))
// 	{
// 		if (mlx->map[mlx->y_p][mlx->x_p - 1] != 'C')
// 			mlx->count_coin--;
// 		else if ((mlx->map[mlx->y_p][mlx->x_p - 1] == 'E')
// 			&& (mlx->count_coin == 0))
// 			exit(0);
// 		mlx->map[mlx->y_p][mlx->x_p] = '0';
// 		mlx->x_p -= 1;
// 		mlx->map[mlx->y_p][mlx->x_p] = 'P';
// 		mlx_clear_window(mlx->mlx_init, mlx->mlx_win);
// 		map_post(mlx);
// 	}
// 	else if (mlx->map[mlx->y_p][mlx->x_p - 1] == 'E'
// 		&& mlx->count_coin == 0)
// 		exit(0);
// }

// void	move_right(mlx_s *mlx)
// {
// 	if ((mlx->map[mlx->y_p][mlx->x_p + 1] != '1')
// 		&& (mlx->map[mlx->y_p][mlx->x_p + 1] != 'E'))
// 	{
// 		if (mlx->map[mlx->y_p][mlx->x_p + 1] != 'C')
// 			mlx->count_coin--;
// 		mlx->map[mlx->y_p][mlx->x_p] = '0';
// 		mlx->x_p += 1;
// 		mlx->map[mlx->y_p][mlx->x_p] = 'P';
// 		mlx_clear_window(mlx->mlx_init, mlx->mlx_win);
// 		map_post(mlx);
// 	}
// 	else if (mlx->map[mlx->y_p][mlx->x_p + 1] == 'E'
// 		&& mlx->count_coin == 0)
// 		exit(0);
// }

// void	move_up(mlx_s *mlx)
// {
// 	if ((mlx->map[mlx->y_p - 1][mlx->x_p] != '1')
// 		&& (mlx->map[mlx->y_p - 1][mlx->x_p] != 'E'))
// 	{
// 		if (mlx->map[mlx->y_p - 1][mlx->x_p] != 'C')
// 			mlx->count_coin--;
// 		mlx->map[mlx->y_p][mlx->x_p] = '0';
// 		mlx->y_p -= 1;
// 		mlx->map[mlx->y_p][mlx->x_p] = 'P';
// 		mlx_clear_window(mlx->mlx_init, mlx->mlx_win);
// 		map_post(mlx);
// 	}
// 	else if (mlx->map[mlx->y_p - 1][mlx->x_p] == 'E'
// 		&& mlx->count_coin == 0)
// 		exit(0);
// }

// void	move_down(mlx_s *mlx)
// {
// 	if ((mlx->map[mlx->y_p + 1][mlx->x_p] != '1')
// 		&& (mlx->map[mlx->y_p + 1][mlx->x_p] != 'E'))
// 	{
// 		if (mlx->map[mlx->y_p + 1][mlx->x_p] != 'C')
// 			mlx->count_coin--;
// 		mlx->map[mlx->y_p][mlx->x_p] = '0';
// 		mlx->y_p += 1;
// 		mlx->map[mlx->y_p][mlx->x_p] = 'P';
// 		mlx_clear_window(mlx->mlx_init, mlx->mlx_win);
// 		map_post(mlx);
// 	}
// 	else if (mlx->map[mlx->y_p + 1][mlx->x_p] == 'E'
// 		&& mlx->count_coin == 0)
// 		exit(0);
// }

