/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozahnou <mozahnou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 23:25:03 by mozahnou          #+#    #+#             */
/*   Updated: 2025/03/30 02:33:14 by mozahnou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_double_pointer(char **array)
{
	int	i;

	i = 0;
	if (!array)
		return ;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array); 
	array = NULL;
}

int	check_c_e(int c_check, int e_check)
{
	if (c_check > 1 || e_check > 0)
	{
		write(1, "Player can't passed to exit or take all coins\n", 46);
		return (0);
	}
	return (1);
}
