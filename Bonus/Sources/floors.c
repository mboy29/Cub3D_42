/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboy <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 13:44:30 by mboy              #+#    #+#             */
/*   Updated: 2021/06/07 13:44:37 by mboy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/bonus_cub3D.h"

void	floors_struct(t_cub *cub)
{
	cub->floor->floorWX = 0.0;
	cub->floor->floorWY = 0.0;
	if (cub->calc->side == 0 && cub->calc->rayDirX > 0)
	{
		cub->floor->floorWX = cub->calc->mapX;
		cub->floor->floorWY = cub->calc->mapY + cub->calc->wallX;
	}
	else if (cub->calc->side == 0 && cub->calc->rayDirX < 0)
	{
		cub->floor->floorWX = cub->calc->mapX + 1.0;
		cub->floor->floorWY = cub->calc->mapY + cub->calc->wallX;
	}
	else if (cub->calc->side == 1 && cub->calc->rayDirY > 0)
	{
		cub->floor->floorWX = cub->calc->mapX + cub->calc->wallX;
		cub->floor->floorWY = cub->calc->mapY;
	}
	else
	{
		cub->floor->floorWX = cub->calc->mapX + cub->calc->wallX;
		cub->floor->floorWY = cub->calc->mapY + 1.0;
	}
}

void	floors_calc(t_cub *cub, int y)
{
	cub->floor->dist = 0.0;
	cub->floor->W = 0.0;
	cub->floor->floorX = 0.0;
	cub->floor->floorY = 0.0;
	cub->floor->textX = 0;
	cub->floor->textY = 0;
	cub->floor->dist = cub->parse->resY / (2.0 * y - cub->parse->resY);
	cub->floor->W = (cub->floor->dist - cub->floor->distP)
		/ (cub->floor->distW - cub->floor->distP);
	cub->floor->floorX = cub->floor->W * cub->floor->floorWX
		+ (1.0 - cub->floor->W) * cub->calc->posX;
	cub->floor->floorY = cub->floor->W * cub->floor->floorWY
		+ (1.0 - cub->floor->W) * cub->calc->posY;
	cub->floor->textX = (int)(cub->floor->floorX * cub->calc->textW)
		% cub->calc->textW;
	cub->floor->textY = (int)(cub->floor->floorY * cub->calc->textH)
		% cub->calc->textH;
}

int	floors(t_cub *cub, int x)
{
	int				y;
	unsigned int	floor;
	unsigned int	ceiling;

	floor = 0;
	ceiling = 0;
	y = cub->calc->drawEnd;
	cub->floor->distW = 0.0;
	cub->floor->distP = 0.0;
	floors_struct(cub);
	cub->floor->distW = cub->calc->perpwallDist;
	if (cub->calc->drawEnd < 0)
		cub->calc->drawEnd = cub->parse->resY;
	y = cub->calc->drawEnd - 1;
	while (++y <= cub->parse->resY)
	{
		floors_calc(cub, y);
		floor = color_floor(cub, TEXT - 3);
		ceiling = color_floor(cub, TEXT - 2);
		gen_pixel(cub->ray, x, cub->parse->resY - y, ceiling);
		gen_pixel(cub->ray, x, y, floor);
	}
	return (0);
}
