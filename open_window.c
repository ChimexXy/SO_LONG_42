/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozahnou <mozahnou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 01:16:51 by mozahnou          #+#    #+#             */
/*   Updated: 2025/03/27 02:33:16 by mozahnou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	window_open(mlx_s *mlx, x_game *game)
{
	mlx->map = game->map;
	mlx->img_wid = 31;
	mlx->img_len = 31;
	mlx->mlx_init = mlx_init(); 
	mlx->mlx_win = mlx_new_window(mlx->mlx_init, game->len_line * 32, game->wid_line * 32, "so_long");
	select_img(mlx);
	map_post(mlx);
	mlx_loop(mlx->mlx_init);
}

void	select_img(mlx_s *mlx)
{
	mlx->player = "./textures/player.xpm";
	mlx->exit1 = "./textures/exit1.xpm";
	mlx->exit2 = "./textures/exit2.xpm";
	// mlx->exit2 = "./textures/wall.xpm";
	// mlx->exit2 = "./textures/coin.xpm";
	mlx->img_player = mlx_xpm_file_to_image(mlx->mlx_init, mlx->player,
		&mlx->img_wid, &mlx->img_len);
	mlx->img_exit1 = mlx_xpm_file_to_image(mlx->mlx_init, mlx->exit1,
		&mlx->img_wid, &mlx->img_len);
	mlx->img_exit2 = mlx_xpm_file_to_image(mlx->mlx_init, mlx->exit2,
		&mlx->img_wid, &mlx->img_len);
}

void	map_post(mlx_s *mlx)
{
	int	x;
	int	y;

	y = 0;
	while(mlx->map[y])
	{
		x = 0;
		while(mlx->map[y][x])
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
	if (mlx->map[y][x] == '1')
		mlx_put_image_to_window(mlx->mlx_init, mlx->mlx_win, mlx->img_exit2,
			x * 32, y * 32);

}