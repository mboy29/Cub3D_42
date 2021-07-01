/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_sprite.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboy <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 13:46:37 by mboy              #+#    #+#             */
/*   Updated: 2021/06/07 13:46:38 by mboy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/bonus_cub3D.h"

int	parse_sprite_struct(t_cub *cub)
{
	int	i;

	i = -1;
	cub->sprite = malloc(sizeof(t_sprite) * (cub->parse->sprites + 1));
	if (!cub->sprite)
		return (-1);
	while (++i <= cub->parse->sprites)
	{
		cub->sprite[i] = malloc(sizeof(t_sprite));
		if (!cub->sprite[i])
			return (-1);
		if (init_sprite(cub->sprite[i]) == -1)
			return (-1);
	}
	cub->sprite[i] = NULL;
	return (0);
}

int	parse_sprite_pos(t_cub *cub, char map, int x, int y)
{
	static int	i = 0;

	if (!cub->sprite)
		if (parse_sprite_struct(cub) == -1)
			return (-1);
	if (map == '2' || map == '3' || map == '4' || map == '5')
	{
		cub->sprite[i]->nb = map;
		cub->sprite[i]->x = y;
		cub->sprite[i]->y = x;
		i++;
	}
	if (i == cub->parse->sprites)
		i = 0;
	return (0);
}

void	parse_sprite(t_cub *cub, char *line)
{
	int	i;

	i = -1;
	if (is_map_c(line) != -1)
		while (line[++i])
			if (line[i] == '2' || line[i] == '3'
				|| line[i] == '4' || line[i] == '5')
				cub->parse->sprites++;
}
