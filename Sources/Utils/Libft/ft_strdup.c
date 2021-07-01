/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboy <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 10:58:05 by mboy              #+#    #+#             */
/*   Updated: 2021/06/07 13:43:31 by mboy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../Includes/cub3D.h"

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*dst;

	dst = malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (!dst)
		return (NULL);
	i = -1;
	while (s1[++i] != '\0')
		dst[i] = s1[i];
	dst[i] = '\0';
	return (dst);
}
