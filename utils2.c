/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozahnou <mozahnou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 23:25:03 by mozahnou          #+#    #+#             */
/*   Updated: 2025/04/05 14:10:03 by mozahnou         ###   ########.fr       */
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

int	check_c(int c_check)
{
	if (c_check > 0)
	{
		pstr("Player Can't Take All Coins :(\n");
		return (0);
	}
	return (1);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	put_nbr(int n)
{
	if (n > 9)
	{
		put_nbr(n / 10);
		put_nbr(n % 10);
	}
	else
		ft_putchar(n + 48);
}

int	map_size(t_game *game)
{
	if (game->len_line > 80 || game->wid_line > 44)
	{
		pstr("The Size of Map Not Exist :(\n");
		return (0);
	}
	return (1);
}
