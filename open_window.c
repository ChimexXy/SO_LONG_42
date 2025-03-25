/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozahnou <mozahnou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 01:16:51 by mozahnou          #+#    #+#             */
/*   Updated: 2025/03/25 21:43:47 by mozahnou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	window_open(x_game *game)
{
	mlx_s *mlx;

	mlx->mlx_init = mlx_init();
	mlx->mlx_win = mlx_new_window(0, 0, 0, 0);
}