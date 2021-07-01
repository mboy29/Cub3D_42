/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboy <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 13:47:05 by mboy              #+#    #+#             */
/*   Updated: 2021/06/07 13:47:06 by mboy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/bonus_cub3D.h"

void	init_game2(t_game *game)
{
	game->endW = 250;
	game->endH = 227;
	game->newX = 0;
	game->newY = 0;
	game->drawStartX = 0;
	game->drawStartY = 0;
	game->drawEndX = 0;
	game->drawEndY = 0;
	game->ratioX = 0.0;
	game->ratioY = 0.0;
	game->startX = 0;
	game->startY = 0;
	game->play = 0;
	game->level = 1;
}

int	init_game1(t_game *game)
{
	int	i;

	i = -1;
	game->mlx = malloc(sizeof(t_mlx *) * COINS);
	if (!game->mlx)
		return (-1);
	while (++i < COINS)
	{
		game->mlx[i] = malloc(sizeof(t_game));
		if (!game->mlx[i])
			return (-1);
		init_mlx(game->mlx[i]);
	}
	game->coins = 0;
	game->startH = 320;
	game->startW = 254;
	game->numH = 62;
	game->numW = 62;
	game->messW = 280;
	game->messH = 24;
	game->levelW = 320;
	game->levelH = 219;
	init_game2(game);
	return (0);
}

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

void	init_floor(t_floor *floor)
{
	floor->floorX = 0.0;
	floor->floorY = 0.0;
	floor->floorWX = 0.0;
	floor->floorWY = 0.0;
	floor->dist = 0.0;
	floor->distW = 0.0;
	floor->distP = 0.0;
	floor->W = 0.0;
	floor->textX = 0;
	floor->textY = 0;
}
