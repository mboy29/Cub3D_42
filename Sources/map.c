/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboy <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 13:39:55 by mboy              #+#    #+#             */
/*   Updated: 2021/06/07 13:39:57 by mboy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/cub3D.h"

int	map_struct(t_cub *cub)
{
	if (((cub->parse->resX / 4) / cub->parse->mapX)
		<= ((cub->parse->resY / 4) / cub->parse->mapY))
	{
		cub->ray->sqr_side = (cub->parse->resX / 4) / cub->parse->mapX;
		if (cub->ray->sqr_side * cub->parse->mapX == cub->parse->resX)
			cub->ray->sqr_side--;
	}
	else
	{
		cub->ray->sqr_side = (cub->parse->resY / 4) / cub->parse->mapY;
		if (cub->ray->sqr_side * cub->parse->mapY == cub->parse->resY)
			cub->ray->sqr_side--;
	}
	cub->ray->cutX = 25;
	cub->ray->cutY = 25;
	return (0);
}

void	map_play(t_cub *cub)
{
	int	y;
	int	x;
	int	i;
	int	j;

	i = -1;
	y = cub->ray->cutY;
	while (cub->parse->map[++i])
	{
		j = -1;
		x = cub->ray->cutX;
		while (cub->parse->map[i][++j])
		{
			if (i == (int)cub->calc->posX && j == (int)cub->calc->posY)
			{
				cub->ray->startX = x + 1;
				cub->ray->startY = y + 1;
				gen_sqr(cub->ray, cub->ray->sqr_side - 1,
					0x00ffffff, 0x00271C17);
			}
			x = x + cub->ray->sqr_side;
		}
		y = y + cub->ray->sqr_side;
	}
}

void	map_sqt(t_cub *cub, int i, int j)
{
	if (cub->parse->map[i][j] == '1')
		gen_sqr(cub->ray, cub->ray->sqr_side, 0x00D8C397, 0x00271C17);
	else if (cub->parse->map[i][j] == '0'
			|| cub->parse->map[i][j] == cub->parse->playD)
		gen_sqr(cub->ray, cub->ray->sqr_side, 0x005A4135, 0x00271C17);
	else if (cub->parse->map[i][j] > '1')
		gen_sqr(cub->ray, cub->ray->sqr_side, 0x00402E26, 0x00271C17);
}

void	map_draw(t_cub *cub)
{
	int	y;
	int	x;
	int	i;
	int	j;

	i = -1;
	y = cub->ray->cutY;
	while (cub->parse->map[++i])
	{
		j = -1;
		x = cub->ray->cutX;
		while (cub->parse->map[i][++j])
		{
			cub->ray->startX = x;
			cub->ray->startY = y;
			map_sqt(cub, i, j);
			x = x + cub->ray->sqr_side;
		}
		y = y + cub->ray->sqr_side;
	}
}

int	map(t_cub *cub)
{
	if (map_struct(cub) == -1)
		return (-1);
	map_draw(cub);
	map_play(cub);
	return (0);
}
