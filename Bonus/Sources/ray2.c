/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboy <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 13:45:56 by mboy              #+#    #+#             */
/*   Updated: 2021/06/07 13:45:59 by mboy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/bonus_cub3D.h"

int	ray_pos_dir(t_cub *cub, int x)
{
	cub->calc->cameraX = 0.0;
	cub->calc->rayDirX = 0.0;
	cub->calc->rayDirY = 0.0;
	cub->calc->mapX = 0;
	cub->calc->mapY = 0;
	cub->calc->cameraX = (2 * x / (double)cub->parse->resX) - 1;
	cub->calc->rayDirX = cub->calc->dirX
		+ cub->calc->planX * cub->calc->cameraX;
	cub->calc->rayDirY = cub->calc->dirY
		+ cub->calc->planY * cub->calc->cameraX;
	cub->calc->mapX = (int)cub->calc->posX;
	cub->calc->mapY = (int)cub->calc->posY;
	return (0);
}

void	ray_delta(t_cub *cub)
{
	cub->calc->deltaDistX = 0.0;
	cub->calc->deltaDistY = 0.0;
	if (cub->calc->rayDirY == 0)
		cub->calc->deltaDistX = 0;
	else if (cub->calc->rayDirX == 0)
		cub->calc->deltaDistX = 1;
	else
		cub->calc->deltaDistX = sqrt(1
				+ (cub->calc->rayDirY * cub->calc->rayDirY)
				/ (cub->calc->rayDirX * cub->calc->rayDirX));
	if (cub->calc->rayDirX == 0)
		cub->calc->deltaDistY = 0;
	else if (cub->calc->rayDirY == 0)
		cub->calc->deltaDistY = 1;
	else
		cub->calc->deltaDistY = sqrt(1
				+ (cub->calc->rayDirX * cub->calc->rayDirX)
				/ (cub->calc->rayDirY * cub->calc->rayDirY));
}

void	ray_step_side1(t_cub *cub)
{
	cub->calc->sideDistY = 0.0;
	if (cub->calc->rayDirY < 0)
	{
		cub->calc->stepY = -1;
		cub->calc->sideDistY = (cub->calc->posY
				- cub->calc->mapY) * cub->calc->deltaDistY;
	}
	else
	{
		cub->calc->stepY = 1;
		cub->calc->sideDistY = (cub->calc->mapY + 1.0
				- cub->calc->posY) * cub->calc->deltaDistY;
	}
}

void	ray_step_side(t_cub *cub)
{
	cub->calc->sideDistX = 0.0;
	if (cub->calc->rayDirX < 0)
	{
		cub->calc->stepX = -1;
		cub->calc->sideDistX = (cub->calc->posX
				- cub->calc->mapX) * cub->calc->deltaDistX;
	}
	else
	{
		cub->calc->stepX = 1;
		cub->calc->sideDistX = (cub->calc->mapX + 1.0
				- cub->calc->posX) * cub->calc->deltaDistX;
	}
	ray_step_side1(cub);
}
