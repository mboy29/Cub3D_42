/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboy <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 13:41:55 by mboy              #+#    #+#             */
/*   Updated: 2021/06/07 13:41:56 by mboy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/cub3D.h"

int	init_wall(t_wall *wall)
{
	wall->mlx = malloc(sizeof(t_mlx));
	if (!wall->mlx)
		return (-1);
	init_mlx(wall->mlx);
	wall->textNum = 0;
	wall->textX = 0;
	wall->textY = 0;
	wall->textH = 64;
	wall->textW = 64;
	wall->wallX = 0.0;
	wall->step = 0.0;
	wall->textPos = 0.0;
	wall->mapX = 0;
	wall->mapY = 0;
	wall->stepX = 0;
	wall->stepY = 0;
	wall->hit = 0;
	wall->side = 0;
	wall->drawStart = 0;
	wall->drawEnd = 0;
	return (0);
}

int	init_sprite(t_sprite *sprite)
{
	sprite->mlx = malloc(sizeof(t_mlx));
	if (!sprite->mlx)
		return (-1);
	init_mlx(sprite->mlx);
	sprite->x = 0;
	sprite->y = 0;
	sprite->nb = 0;
	sprite->pick = 0;
	sprite->stripe = 0;
	sprite->distS = 0.0;
	sprite->spriteX = 0.0;
	sprite->spriteY = 0.0;
	sprite->invDet = 0.0;
	sprite->transX = 0.0;
	sprite->transY = 0.0;
	sprite->screenSX = 0;
	sprite->spriteH = 64;
	sprite->spriteW = 64;
	sprite->drawStartY = 0;
	sprite->drawStartX = 0;
	sprite->drawEndY = 0;
	sprite->drawEndX = 0;
	sprite->texX = 0;
	sprite->texY = 0;
	return (0);
}
