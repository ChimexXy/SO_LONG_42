/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozahnou <mozahnou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 01:16:51 by mozahnou          #+#    #+#             */
/*   Updated: 2025/03/30 01:08:08 by mozahnou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	window_open(mlx_s *mlx)
{
	mlx->mlx_init = mlx_init(); 
	mlx->mlx_win = mlx_new_window(mlx->mlx_init, mlx->len_line * 32, mlx->wid_line * 32, "so_long");
	select_img(mlx);
	map_post(mlx);
	mlx_key_hook(mlx->mlx_win, select_key, mlx);
	mlx_loop(mlx->mlx_init);
}

void	select_img(mlx_s *mlx)
{
	mlx->player = "./textures/player.xpm";
	mlx->exit1 = "./textures/exit1.xpm";
	mlx->exit2 = "./textures/exit2.xpm";
	mlx->wall = "./textures/wall.xpm";
	mlx->coin = "./textures/coin.xpm";
	if (!(mlx->img_player = mlx_xpm_file_to_image(mlx->mlx_init, mlx->player,
		&mlx->img_wid, &mlx->img_len)))
		exit(0);
	if (!(mlx->img_exit1 = mlx_xpm_file_to_image(mlx->mlx_init, mlx->exit1,
		&mlx->img_wid, &mlx->img_len)))
		exit(0);
	if (!(mlx->img_exit2 = mlx_xpm_file_to_image(mlx->mlx_init, mlx->exit2,
		&mlx->img_wid, &mlx->img_len)))
		exit(0);
	if (!(mlx->img_wall = mlx_xpm_file_to_image(mlx->mlx_init, mlx->wall,
		&mlx->img_wid, &mlx->img_len)))
		exit(0);
	if (!(mlx->img_coin = mlx_xpm_file_to_image(mlx->mlx_init, mlx->coin,
		&mlx->img_wid, &mlx->img_len)))
		exit(0);
}

void	map_post(mlx_s *mlx)
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

void	map_post2(mlx_s *mlx, int y, int x)
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

int	select_key(int key, mlx_s *mlx)
{
	if (key == 0)
		move_left(mlx);
	else if (key == 2)
		move_right(mlx);
	else if (key == 13)
		move_up(mlx);
	else if (key == 1)
		move_down(mlx);
	else if (key == 53 || key == 17)
		exit(0);
	else
		write(1, "Invalid Key Pressed :(\n", 23);
	return (0);
}