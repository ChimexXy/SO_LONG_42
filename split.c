/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozahnou <mozahnou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 12:12:29 by mozahnou          #+#    #+#             */
/*   Updated: 2025/03/21 21:53:09 by mozahnou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_count_word(char *str, char sep)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (str[i] == '.' && str[i + 1] == sep)
		i += 2;
	while (str[i])
	{
		if (str[i] != sep && str[i])
			j++;
		while (str[i] != sep && str[i])
			i++;
		if (str[i] == sep && str[i + 1] == sep)
			return (0);
		if (str[i] == sep && str[i])
			i++;
	}
	return (j);
}

char	*ft_substr_2(char *str, int start, int end)
{
	int		j;
	char	*ret;

	j = 0;
	ret = malloc((end - start) + 1);
	while (start < end)
	{
		ret[j] = str[start];
		start++;
		j++;
	}
	ret[j] = '\0';
	return (ret);
}

char	**ft_split(char *str, char sep)
{
	int		i;
	int		cnt;
	int		start;
	int		len_word;
	char	**ret;

	i = 0;
	cnt = 0;
	len_word = ft_count_word(str, sep);
	ret = malloc((len_word + 1) * sizeof(char *));
	while (cnt < len_word)
	{
		while (str[i] == sep)
			i++;
		start = i;
		while (str[i] != sep)
			i++;
		ret[cnt] = ft_substr_2(str, start, i);
		cnt++;
	}
	ret[cnt] = NULL;
	return (ret);
}
