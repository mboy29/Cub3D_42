/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboy <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 12:58:37 by mboy              #+#    #+#             */
/*   Updated: 2021/06/07 13:48:01 by mboy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen_gnl(char *str)
{
	size_t	i;

	i = 0;
	if (str)
		while (str[i])
			i++;
	return (i);
}

char	*ft_strdup_gnl(char *str)
{
	int		i;
	char	*dst;

	dst = malloc(sizeof(char) * ((ft_strlen_gnl(str) + 1)));
	if (!(dst))
	{
		free (dst);
		return (NULL);
	}
	i = -1;
	while (str[++i])
		dst[i] = str[i];
	dst[i] = '\0';
	return (dst);
}

char	*ft_strjoin_gnl(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*join;

	i = -1;
	j = 0;
	if (!s1 && !s2)
		return (NULL);
	join = malloc(sizeof(char) * (ft_strlen_gnl(s1) + ft_strlen_gnl(s2) + 2));
	if (!(join))
		return (NULL);
	while (s1[++i] != '\0')
		join[i] = s1[i];
	while (s2[j])
		join[i++] = s2[j++];
	join[i] = '\0';
	return (join);
}

char	*ft_strcut_front(char *str)
{
	int		i;
	char	*front;

	i = 0;
	while (str[i] != '\n')
		i++;
	front = malloc(sizeof(char) * (i + 1));
	if (!(front))
		return (NULL);
	i = 0;
	while (str[i] != '\n')
	{
		front[i] = str[i];
		i++;
	}
	front[i] = '\0';
	return (front);
}

char	*ft_strcut_back(char *str)
{
	int		i;
	int		j;
	char	*back;

	i = 0;
	while (str[i] != '\n')
		i++;
	i++;
	back = malloc(sizeof(char) * ((ft_strlen_gnl(str) - i) + 1));
	if (!(back))
		return (NULL);
	j = 0;
	while (str[i] != '\0')
		back[j++] = str[i++];
	back[j] = '\0';
	free (str);
	return (back);
}
