/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozahnou <mozahnou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 20:10:35 by mozahnou          #+#    #+#             */
/*   Updated: 2025/04/02 11:26:40 by mozahnou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_strdup(char *s)
{
	int		i;
	int		j;
	char	*ret;

	if (!s)
		return (NULL);
	i = 0;
	j = 0;
	ret = malloc(ft_strlen(s) + 1);
	if (!ret)
		return (NULL);
	while (s[i])
		ret[j++] = s[i++];
	ret[j] = '\0';
	return (ret);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;	
	int		j;
	int		k;
	char	*ret;

	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	i = 0;
	j = 0;
	k = 0;
	ret = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!ret)
		return (NULL);
	while (s1[i])
		ret[k++] = s1[i++];
	while (s2[j])
		ret[k++] = s2[j++];
	ret[k] = '\0';
	free(s1);
	s1 = NULL;
	return (ret);
}

char	*ft_substr(char *string, int start, int len)
{
	int		i;
	int		j;
	char	*ret;

	if (!string)
		return (ft_strdup(""));
	i = start;
	j = 0;
	ret = malloc(len + 1);
	if (!ret)
		return (NULL);
	while (len > 0 && string[i])
	{
		ret[j++] = string[i++];
		len--;
	}
	ret[j] = '\0';
	return (ret);
}
