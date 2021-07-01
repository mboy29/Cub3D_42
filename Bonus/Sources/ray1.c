/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboy <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 13:45:49 by mboy              #+#    #+#             */
/*   Updated: 2021/06/07 13:45:50 by mboy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/bonus_cub3D.h"

void	ray_hit_side(t_cub *cub)
{
	cub->calc->hit = 0;
	cub->calc->side = 0;
	while (cub->calc->hit == 0)
	{
		if (cub->calc->sideDistX < cub->calc->sideDistY)
		{
			cub->calc->sideDistX += cub->calc->deltaDistX;
			cub->calc->mapX += cub->calc->stepX;
			cub->calc->side = 0;
		}
		else
		{
			cub->calc->sideDistY += cub->calc->deltaDistY;
			cub->calc->mapY += cub->calc->stepY;
			cub->calc->side = 1;
		}
		if (cub->parse->map[cub->calc->mapX][cub->calc->mapY] == '1')
			cub->calc->hit = 1;
	}
}

void	ray_perp_h(t_cub *cub)
{
	cub->calc->perpwallDist = 0.0;
	if (cub->calc->side == 0)
		cub->calc->perpwallDist = ((double)cub->calc->mapX
				- cub->calc->posX + (1 - (double)cub->calc->stepX)
				/ 2) / cub->calc->rayDirX;
	else
		cub->calc->perpwallDist = ((double)cub->calc->mapY
				- cub->calc->posY + (1 - (double)cub->calc->stepY)
				/ 2) / cub->calc->rayDirY;
	cub->calc->lineHeight = (cub->calc->ratio
			* (double)cub->parse->resY / cub->calc->perpwallDist);
}

int	ray_end_start(t_cub *cub)
{
	cub->calc->drawStart = 0;
	cub->calc->drawEnd = 0;
	cub->calc->drawStart = -cub->calc->lineHeight / 2 + cub->parse->resY / 2;
	if (cub->calc->drawStart < 0)
		cub->calc->drawStart = 0;
	cub->calc->drawEnd = cub->calc->lineHeight / 2 + cub->parse->resY / 2;
	if (cub->calc->drawEnd >= cub->parse->resY)
		cub->calc->drawEnd = cub->parse->resY;
	return (0);
}

int	ray(t_cub *cub)
{
	int	x;

	x = -1;
	while (++x != cub->parse->resX)
	{
		ray_pos_dir(cub, x);
		ray_delta(cub);
		ray_step_side(cub);
		ray_hit_side(cub);
		ray_perp_h(cub);
		if ((ray_end_start(cub) == -1) || walls(cub, x) == -1
			|| (floors(cub, x) == -1))
			return (-1);
		cub->calc->bufS[x] = cub->calc->perpwallDist;
	}
	sprites(cub);
	return (0);
}
