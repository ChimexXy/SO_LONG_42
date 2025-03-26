/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozahnou <mozahnou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 01:16:51 by mozahnou          #+#    #+#             */
/*   Updated: 2025/03/26 21:48:41 by mozahnou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	window_open(mlx_s *mlx, x_game *game)
{
	mlx->mlx_init = mlx_init(); 
	mlx->mlx_win = mlx_new_window(mlx->mlx_init, game->len_line * 64, game->wid_line * 64, "so_long");
	mlx_loop(mlx->mlx_init);
}
