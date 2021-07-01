/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboy <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 13:47:12 by mboy              #+#    #+#             */
/*   Updated: 2021/06/07 13:47:14 by mboy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/bonus_cub3D.h"

void	init_parse(t_parse *parse)
{
	parse->map = NULL;
	parse->resX = 0;
	parse->resY = 0;
	parse->mapX = 0;
	parse->mapY = 0;
	parse->play = 0;
	parse->playX = 0;
	parse->playY = 0;
	parse->playD = 0;
	parse->letter = 0;
	parse->texture = NULL;
	parse->sprites = 0;
}

void	init_key(t_key *key)
{
	key->enter = 0;
	key->space_exit = 0.;
	key->forward_w_z = 0;
	key->back_s_s = 0;
	key->right_d_d = 0;
	key->left_a_q = 0;
	key->rotate_right = 0;
	key->rotate_left = 0;
}

void	init_calc2(t_calc *calc)
{
	calc->lineHeight = 0;
	calc->ratio = 0.0;
	calc->drawEnd = 0;
	calc->drawStart = 0;
	calc->wallX = 0.0;
	calc->step = 0.0;
	calc->textPos = 0.0;
	calc->drawStart = 0;
	calc->drawEnd = 0;
	calc->textNum = 0;
	calc->textX = 0;
	calc->textY = 0;
	calc->textW = 0;
	calc->textH = 0;
	calc->mapX = 0;
	calc->mapY = 0;
	calc->stepX = 0;
	calc->stepY = 0;
	calc->hit = 0;
	calc->side = 0;
	calc->bufS = NULL;
}

void	init_calc1(t_calc *calc)
{
	calc->save = 0;
	calc->posX = 0.0;
	calc->posY = 0.0;
	calc->dirX = 0.0;
	calc->dirY = 0.0;
	calc->oldDirX = 0.0;
	calc->planX = 0.0;
	calc->planY = 0.0;
	calc->oldPlanX = 0.0;
	calc->cameraX = 0;
	calc->rayDirX = 0.0;
	calc->rayDirY = 0.0;
	calc->sideDistX = 0.0;
	calc->sideDistY = 0.0;
	calc->deltaDistX = 0.0;
	calc->deltaDistY = 0.0;
	calc->perpwallDist = 0.0;
	calc->moveSpeed = 0.0;
	calc->rotSpeed = 0.0;
	init_calc2(calc);
}

void	init_mlx(t_mlx *mlx)
{
	mlx->mlx_ptr = NULL;
	mlx->win_ptr = NULL;
	mlx->img_ptr = NULL;
	mlx->img_data = NULL;
	mlx->bpp = 0;
	mlx->len = 0;
	mlx->endian = 0;
	mlx->playXR = 0.0;
	mlx->playYR = 0.0;
	mlx->sqr_side = 0;
	mlx->cutX = 0;
	mlx->cutY = 0;
	mlx->resX = 0;
	mlx->resY = 0;
	mlx->startX = 0;
	mlx->startY = 0;
	mlx->endX = 0;
	mlx->endY = 0;
}
