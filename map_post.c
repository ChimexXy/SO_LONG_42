/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_post.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozahnou <mozahnou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 13:08:50 by mozahnou          #+#    #+#             */
/*   Updated: 2025/04/05 14:00:03 by mozahnou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	sturct_img_sel(t_mlx *mlx)
{
	mlx->player = "./textures/player.xpm";
	mlx->exit1 = "./textures/exit1.xpm";
	mlx->exit2 = "./textures/exit2.xpm";
	mlx->wall = "./textures/wall.xpm";
	mlx->coin = "./textures/coin.xpm";
}

void	map_post(t_mlx *mlx)
{
	int	x;
	int	y;

	y = 0;
	while (mlx->map[y])
	{
		x = 0;
		while (mlx->map[y][x])
		{
			map_post2(mlx, y, x);
			x++;
		}
		y++;
	}
}

void	map_post2(t_mlx *mlx, int y, int x)
{
	if (mlx->map[y][x] == 'P')
		mlx_put_image_to_window(mlx->mlx_init, mlx->mlx_win, mlx->img_player,
			x * 32, y * 32);
	if (mlx->map[y][x] == 'E')
		mlx_put_image_to_window(mlx->mlx_init, mlx->mlx_win, mlx->img_exit1,
			x * 32, y * 32);
	if (mlx->map[y][x] == 'C')
		mlx_put_image_to_window(mlx->mlx_init, mlx->mlx_win, mlx->img_coin,
			x * 32, y * 32);
	if (mlx->map[y][x] == '1')
		mlx_put_image_to_window(mlx->mlx_init, mlx->mlx_win, mlx->img_wall,
			x * 32, y * 32);
	if (mlx->map[y][x] == 'Z')
		mlx_put_image_to_window(mlx->mlx_init, mlx->mlx_win, mlx->img_exit2,
			x * 32, y * 32);
}
