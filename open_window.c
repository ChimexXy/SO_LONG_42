/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozahnou <mozahnou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 01:16:51 by mozahnou          #+#    #+#             */
/*   Updated: 2025/03/26 07:44:57 by mozahnou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	window_open(mlx_s *mlx, x_game *game)
{
		printf("%d\n",  game->len_line);
	printf("%d\n",  game->wid_line);
	mlx->mlx_init = mlx_init(); 
	mlx->mlx_win = mlx_new_window(mlx->mlx_init, game->len_line * 32, game->wid_line * 32, "so_long");
	mlx_loop(mlx->mlx_init);
}
