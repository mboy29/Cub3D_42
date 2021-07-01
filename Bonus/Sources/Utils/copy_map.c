/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboy <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 13:46:56 by mboy              #+#    #+#             */
/*   Updated: 2021/06/07 13:46:58 by mboy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/bonus_cub3D.h"

int	copy_map(t_cub *cub, char *line, int i)
{
	int	j;

	cub->parse->map[i] = malloc(sizeof(char) * (cub->parse->mapX + 1));
	if (!cub->parse->map[i])
		return (-1);
	j = 0;
	while (j < (int)ft_strlen(line))
	{
		cub->parse->map[i][j] = line[j];
		j++;
	}
	while (j < cub->parse->mapX)
	{
		cub->parse->map[i][j] = ' ';
		j++;
	}
	cub->parse->map[i][j] = '\0';
	return (0);
}
