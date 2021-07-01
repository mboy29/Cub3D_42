/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_map_c.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboy <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 13:47:18 by mboy              #+#    #+#             */
/*   Updated: 2021/06/07 13:47:19 by mboy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/bonus_cub3D.h"

int	is_map_c(char *line)
{
	int	i;
	int	c;
	int	space;

	i = -1;
	c = 0;
	space = 0;
	while (line[++i])
	{
		if (line[i] == 'N' || line[i] == 'S' || line[i] == 'E'
			|| line[i] == 'W' || line[i] == ' ' || line[i] == '1'
			|| line[i] == '2' || line[i] == '0' || line[i] == '3'
			|| line[i] == '4' || line[i] == '5' || line[i] == '\t')
			c++;
		if (line[i] == ' ')
			space++;
	}
	if ((c != 0 && c == (int)ft_strlen(line)) || space == (int)ft_strlen(line))
		return (c);
	return (-1);
}
