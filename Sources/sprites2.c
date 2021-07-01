/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboy <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 13:40:30 by mboy              #+#    #+#             */
/*   Updated: 2021/06/07 13:40:31 by mboy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/cub3D.h"

void	sprites_calc(t_cub *cub, int i)
{
	cub->sprite[i]->distS = 0.0;
	cub->sprite[i]->spriteX = 0.0;
	cub->sprite[i]->spriteY = 0.0;
	cub->sprite[i]->invDet = 0.0;
	cub->sprite[i]->transX = 0.0;
	cub->sprite[i]->transY = 0.0;
	cub->sprite[i]->screenSX = 0.0;
	cub->sprite[i]->spriteX = (cub->sprite[i]->x - cub->calc->posX) + 0.5;
	cub->sprite[i]->spriteY = (cub->sprite[i]->y - cub->calc->posY) + 0.5;
	cub->sprite[i]->invDet = 1.0 / (cub->calc->planX
			* cub->calc->dirY - cub->calc->dirX * cub->calc->planY);
	cub->sprite[i]->transX = cub->sprite[i]->invDet
		* (cub->calc->dirY * cub->sprite[i]->spriteX - cub->calc->dirX
			* cub->sprite[i]->spriteY);
	cub->sprite[i]->transY = cub->sprite[i]->invDet
		* (-cub->calc->planY * cub->sprite[i]->spriteX + cub->calc->planX
			* cub->sprite[i]->spriteY);
	cub->sprite[i]->screenSX = (cub->parse->resX / 2)
		* (1 + cub->sprite[i]->transX / cub->sprite[i]->transY);
}

void	sprites_end_startY(t_cub *cub, int i)
{
	cub->sprite[i]->spriteH = 0;
	cub->sprite[i]->drawStartY = 0;
	cub->sprite[i]->drawEndY = 0;
	cub->sprite[i]->spriteH = abs((int)(cub->parse->resY
				/ cub->sprite[i]->transY));
	cub->sprite[i]->drawStartY = -cub->sprite[i]->spriteH
		/ 2 + cub->parse->resY / 2;
	if (cub->sprite[i]->drawStartY < 0)
		cub->sprite[i]->drawStartY = 0;
	cub->sprite[i]->drawEndY = cub->sprite[i]->spriteH
		/ 2 + cub->parse->resY / 2;
	if (cub->sprite[i]->drawEndY >= cub->parse->resY)
		cub->sprite[i]->drawEndY = cub->parse->resY - 1;
}

void	sprites_end_startX(t_cub *cub, int i)
{
	cub->sprite[i]->spriteW = 0;
	cub->sprite[i]->drawStartX = 0;
	cub->sprite[i]->drawEndX = 0;
	cub->sprite[i]->spriteW = abs((int)(cub->parse->resY
				/ cub->sprite[i]->transY));
	cub->sprite[i]->drawStartX = -cub->sprite[i]->spriteW
		/ 2 + cub->sprite[i]->screenSX;
	if (cub->sprite[i]->drawStartX < 0)
		cub->sprite[i]->drawStartX = 0;
	cub->sprite[i]->drawEndX = cub->sprite[i]->spriteW
		/ 2 + cub->sprite[i]->screenSX;
	if (cub->sprite[i]->drawEndX >= cub->parse->resX)
		cub->sprite[i]->drawEndX = cub->parse->resX - 1;
}

void	sprites_draw_loop(t_cub *cub, int i)
{
	int				y;
	int				d;
	unsigned int	color;

	d = 0;
	color = 0;
	y = cub->sprite[i]->drawStartY - 1;
	while (++y < cub->sprite[i]->drawEndY)
	{
		d = y * 256 - cub->parse->resY * 128
			+ cub->sprite[i]->spriteH * 128;
		cub->sprite[i]->texY = ((d * cub->calc->textH)
				/ cub->sprite[i]->spriteH) / 256;
		color = color_sprite(cub, i);
		if ((color & 0x00FFFFFF) != 0)
			gen_pixel(cub->ray, cub->sprite[i]->stripe, y, color);
	}
}

void	sprites_draw(t_cub *cub, int i)
{
	cub->sprite[i]->texX = 0;
	cub->sprite[i]->texY = 0;
	cub->sprite[i]->stripe = cub->sprite[i]->drawStartX - 1;
	while (++cub->sprite[i]->stripe < cub->sprite[i]->drawEndX)
	{
		cub->sprite[i]->texX = (int)(256 * (cub->sprite[i]->stripe
					- (-cub->sprite[i]->spriteW / 2 + cub->sprite[i]->screenSX))
				* cub->calc->textW / cub->sprite[i]->spriteW) / 256;
		if (cub->sprite[i]->transY > 0 && cub->sprite[i]->stripe > 0
			&& cub->sprite[i]->stripe < cub->parse->resX
			&& cub->sprite[i]->transY < cub->calc->bufS[cub->sprite[i]->stripe])
			sprites_draw_loop(cub, i);
	}
}
