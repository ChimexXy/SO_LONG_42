/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   palyer_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozahnou <mozahnou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 07:40:47 by mozahnou          #+#    #+#             */
/*   Updated: 2025/04/05 13:03:00 by mozahnou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_exit_unlock(t_mlx *mlx)
{
	int	x;
	int	y;

	if (mlx->count_coin > 0)
		return ;
	y = 0;
	while (mlx->map[y])
	{
		x = 0;
		while (mlx->map[y][x])
		{
			if (mlx->map[y][x] == 'E')
				mlx->map[y][x] = 'Z';
			x++;
		}
		y++;
	}
}

void	move_left(t_mlx *mlx)
{
	if (mlx->map[mlx->y_p][mlx->x_p - 1] == '1')
		return ;
	if (mlx->map[mlx->y_p][mlx->x_p - 1] == 'C')
		mlx->count_coin--;
	if (mlx->map[mlx->y_p][mlx->x_p - 1] == 'E' && mlx->count_coin > 0)
		return ;
	if (mlx->map[mlx->y_p][mlx->x_p - 1] == 'Z')
	{
		free_double_pointer(mlx->map);
		exit(0);
	}
	mlx->map[mlx->y_p][mlx->x_p] = '0';
	mlx->x_p -= 1;
	mlx->map[mlx->y_p][mlx->x_p] = 'P';
	check_exit_unlock(mlx);
	mlx_clear_window(mlx->mlx_init, mlx->mlx_win);
	mlx->mv_count++;
	put_nbr(mlx->mv_count);
	write(1, "\n", 1);
	map_post(mlx);
}

void	move_right(t_mlx *mlx)
{
	if (mlx->map[mlx->y_p][mlx->x_p + 1] == '1')
		return ;
	if (mlx->map[mlx->y_p][mlx->x_p + 1] == 'C')
		mlx->count_coin--;
	if (mlx->map[mlx->y_p][mlx->x_p + 1] == 'E' && mlx->count_coin > 0)
		return ;
	if (mlx->map[mlx->y_p][mlx->x_p + 1] == 'Z')
	{
		free_double_pointer(mlx->map);
		exit(0);
	}
	mlx->map[mlx->y_p][mlx->x_p] = '0';
	mlx->x_p += 1;
	mlx->map[mlx->y_p][mlx->x_p] = 'P';
	check_exit_unlock(mlx);
	mlx_clear_window(mlx->mlx_init, mlx->mlx_win);
	mlx->mv_count++;
	put_nbr(mlx->mv_count);
	write(1, "\n", 1);
	map_post(mlx);
}

void	move_up(t_mlx *mlx)
{
	if (mlx->map[mlx->y_p - 1][mlx->x_p] == '1')
		return ;
	if (mlx->map[mlx->y_p - 1][mlx->x_p] == 'C')
		mlx->count_coin--;
	if (mlx->map[mlx->y_p - 1][mlx->x_p] == 'E' && mlx->count_coin > 0)
		return ;
	if (mlx->map[mlx->y_p - 1][mlx->x_p] == 'Z')
	{
		free_double_pointer(mlx->map);
		exit(0);
	}
	mlx->map[mlx->y_p][mlx->x_p] = '0';
	mlx->y_p -= 1;
	mlx->map[mlx->y_p][mlx->x_p] = 'P';
	check_exit_unlock(mlx);
	mlx_clear_window(mlx->mlx_init, mlx->mlx_win);
	mlx->mv_count++;
	put_nbr(mlx->mv_count);
	write(1, "\n", 1);
	map_post(mlx);
}

void	move_down(t_mlx *mlx)
{
	if (mlx->map[mlx->y_p + 1][mlx->x_p] == '1')
		return ;
	if (mlx->map[mlx->y_p + 1][mlx->x_p] == 'C')
		mlx->count_coin--;
	if (mlx->map[mlx->y_p + 1][mlx->x_p] == 'E' && mlx->count_coin > 0)
		return ;
	if (mlx->map[mlx->y_p + 1][mlx->x_p] == 'Z')
	{
		free_double_pointer(mlx->map);
		exit(0);
	}
	mlx->map[mlx->y_p][mlx->x_p] = '0';
	mlx->y_p += 1;
	mlx->map[mlx->y_p][mlx->x_p] = 'P';
	check_exit_unlock(mlx);
	mlx_clear_window(mlx->mlx_init, mlx->mlx_win);
	mlx->mv_count++;
	put_nbr(mlx->mv_count);
	write(1, "\n", 1);
	map_post(mlx);
}