/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prep.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboy <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 13:45:33 by mboy              #+#    #+#             */
/*   Updated: 2021/06/07 13:45:46 by mboy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/bonus_cub3D.h"

void	prep_start_end(t_cub *cub, int n)
{
	cub->game->drawStartX = 100;
	cub->game->drawEndX = cub->parse->resX - 100;
	cub->game->drawStartY = 150;
	cub->game->drawEndY = cub->parse->resY - 100;
	cub->game->newX = cub->game->drawEndX - cub->game->drawStartX;
	cub->game->newY = cub->game->drawEndY - cub->game->drawStartY;
	if (n == 11)
	{
		cub->game->ratioX = (double)cub->game->startW / (double)cub->game->newX;
		cub->game->ratioY = (double)cub->game->startH / (double)cub->game->newY;
	}
	if (n == 15)
	{
		cub->game->ratioX = (double)cub->game->endW / (double)cub->game->newX;
		cub->game->ratioY = (double)cub->game->endH / (double)cub->game->newY;
	}
}

void	prep_num(t_cub *cub)
{
	cub->game->drawStartX = cub->parse->resX - 25 - cub->game->numW;
	cub->game->drawEndX = cub->parse->resX - 25;
	cub->game->drawStartY = 25 + cub->game->messH;
	cub->game->drawEndY = 25 + cub->game->messH + cub->game->numH;
	cub->game->newX = cub->game->drawEndX - cub->game->drawStartX;
	cub->game->newY = cub->game->drawEndY - cub->game->drawStartY;
	cub->game->ratioX = (double)cub->game->numW / (double)cub->game->newX;
	cub->game->ratioY = (double)cub->game->numH / (double)cub->game->newY;
}

void	prep_mess(t_cub *cub)
{
	cub->game->drawStartX = 22;
	cub->game->drawEndX = 22 + cub->game->messW;
	cub->game->drawStartY = 19;
	cub->game->drawEndY = 19 + cub->game->messH;
	cub->game->newX = cub->game->drawEndX - cub->game->drawStartX;
	cub->game->newY = cub->game->drawEndY - cub->game->drawStartY;
	cub->game->ratioX = (double)cub->game->messW / (double)cub->game->newX;
	cub->game->ratioY = (double)cub->game->messH / (double)cub->game->newY;
}

void	prep_lev(t_cub *cub)
{
	cub->game->drawStartX = 100 + ((cub->ray->sqr_side * cub->parse->mapX) / 2);
	cub->game->drawEndX = cub->parse->resX - 100
		- ((cub->ray->sqr_side * cub->parse->mapX) / 2);
	cub->game->drawStartY = (cub->parse->resY / 2) - 100;
	cub->game->drawEndY = cub->parse->resY - 50;
	cub->game->newX = cub->game->drawEndX - cub->game->drawStartX;
	cub->game->newY = cub->game->drawEndY - cub->game->drawStartY;
	cub->game->ratioX = (double)cub->game->levelW / (double)cub->game->newX;
	cub->game->ratioY = (double)cub->game->levelH / (double)cub->game->newY;
}

void	prep(t_cub *cub, int n)
{
	cub->game->drawStartX = 0;
	cub->game->drawStartY = 0;
	cub->game->drawEndX = 0;
	cub->game->drawEndY = 0;
	cub->game->newX = 0;
	cub->game->newY = 0;
	cub->game->ratioX = 0;
	cub->game->ratioY = 0;
	if (n >= 0 && n <= 10)
		prep_num(cub);
	else if (n == 11 || n == 15)
		prep_start_end(cub, n);
	else if (n == 12 || n == 13)
		prep_mess(cub);
	else if (n == 14)
		prep_lev(cub);
}
