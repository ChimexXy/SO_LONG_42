/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozahnou <mozahnou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 01:16:51 by mozahnou          #+#    #+#             */
/*   Updated: 2025/04/05 14:00:00 by mozahnou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_mlx(t_mlx *mlx)
{
	free_double_pointer(mlx->map);
	free(mlx);
	exit(1);
}

int	close_window(t_mlx *mlx)
{
	mlx_destroy_window(mlx->mlx_init, mlx->mlx_win);
	free_mlx(mlx);
	return (0);
}

void	window_open(t_mlx *mlx)
{
	mlx->mv_count = 0;
	mlx->mlx_init = mlx_init(); 
	mlx->mlx_win = mlx_new_window(mlx->mlx_init, mlx->len_line * 32,
			mlx->wid_line * 32, "so_long");
	select_img(mlx);
	map_post(mlx);
	mlx_key_hook(mlx->mlx_win, select_key, mlx);
	mlx_hook(mlx->mlx_win, 17, 0, close_window, mlx);
	mlx_loop(mlx->mlx_init);
}

void	select_img(t_mlx *mlx)
{
	sturct_img_sel(mlx);
	mlx->img_player = mlx_xpm_file_to_image(mlx->mlx_init, mlx->player, 
		&mlx->img_wid, &mlx->img_len);
	if (!(mlx->img_player))
		free_mlx(mlx);
	if (!(mlx->img_exit1 = mlx_xpm_file_to_image(mlx->mlx_init, mlx->exit1,
			&mlx->img_wid, &mlx->img_len)))
		free_mlx(mlx);
	if (!(mlx->img_exit2 = mlx_xpm_file_to_image(mlx->mlx_init, mlx->exit2,
			&mlx->img_wid, &mlx->img_len)))
		free_mlx(mlx);
	if (!(mlx->img_wall = mlx_xpm_file_to_image(mlx->mlx_init, mlx->wall,
			&mlx->img_wid, &mlx->img_len)))
		free_mlx(mlx);
	if (!(mlx->img_coin = mlx_xpm_file_to_image(mlx->mlx_init, mlx->coin,
			&mlx->img_wid, &mlx->img_len)))
		free_mlx(mlx);
}

int	select_key(int key, t_mlx *mlx)
{
	if (key == 0)
		move_left(mlx);
	else if (key == 2)
		move_right(mlx);
	else if (key == 13)
		move_up(mlx);
	else if (key == 1)
		move_down(mlx);
	else if (key == 53)
		free_mlx(mlx);
	else
		write(1, "Invalid Key Pressed :(\n", 23);
	return (0);
}
