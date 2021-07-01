/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboy <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 13:45:09 by mboy              #+#    #+#             */
/*   Updated: 2021/06/07 13:45:18 by mboy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/bonus_cub3D.h"

void	move_ver(t_cub *cub)
{
	int		calc;

	calc = 0;
	if (cub->key->forward_w_z > 0)
	{
		calc = cub->parse->map[(int)(cub->calc->posX + cub->calc->dirX
				* cub->calc->moveSpeed)][(int)cub->calc->posY];
		if (calc == '0' || calc == '5' || calc == '4')
			cub->calc->posX += cub->calc->dirX * cub->calc->moveSpeed;
		calc = cub->parse->map[(int)cub->calc->posX][(int)(cub->calc->posY
				+ cub->calc->dirY * cub->calc->moveSpeed)];
		if (calc == '0' || calc == '5' || calc == '4')
			cub->calc->posY += cub->calc->dirY * cub->calc->moveSpeed;
	}
	if (cub->key->back_s_s > 0)
	{
		calc = cub->parse->map[(int)(cub->calc->posX - cub->calc->dirX
				* cub->calc->moveSpeed)][(int)cub->calc->posY];
		if (calc == '0' || calc == '5' || calc == '4')
			cub->calc->posX -= cub->calc->dirX * cub->calc->moveSpeed;
		calc = cub->parse->map[(int)cub->calc->posX][(int)(cub->calc->posY
				- cub->calc->dirY * cub->calc->moveSpeed)];
		if (calc == '0' || calc == '5' || calc == '4')
			cub->calc->posY -= cub->calc->dirY * cub->calc->moveSpeed;
	}
}

void	move_hor(t_cub *cub)
{
	int	calc;

	calc = 0;
	if (cub->key->right_d_d > 0)
	{
		calc = cub->parse->map[(int)(cub->calc->posX + cub->calc->planX
				* cub->calc->moveSpeed)][(int)cub->calc->posY];
		if (calc == '0' || calc == '5' || calc == '4')
			cub->calc->posX += cub->calc->planX * cub->calc->moveSpeed;
		calc = cub->parse->map[(int)cub->calc->posX][(int)(cub->calc->posY
				+ cub->calc->planY * cub->calc->moveSpeed)];
		if (calc == '0' || calc == '5' || calc == '4')
			cub->calc->posY += cub->calc->planY * cub->calc->moveSpeed;
	}
	if (cub->key->left_a_q > 0)
	{
		calc = cub->parse->map[(int)(cub->calc->posX - cub->calc->planX
				* cub->calc->moveSpeed)][(int)cub->calc->posY];
		if (calc == '0' || calc == '5' || calc == '4')
			cub->calc->posX -= cub->calc->planX * cub->calc->moveSpeed;
		calc = cub->parse->map[(int)cub->calc->posX][(int)(cub->calc->posY
				- cub->calc->planY * cub->calc->moveSpeed * 2)];
		if (calc == '0' || calc == '5' || calc == '4')
			cub->calc->posY -= cub->calc->planY * cub->calc->moveSpeed;
	}
}

void	move_rignt(t_cub *cub)
{
	cub->calc->oldDirX = cub->calc->dirX;
	cub->calc->dirX = cub->calc->dirX * cos(-cub->calc->rotSpeed)
		- cub->calc->dirY * sin(-cub->calc->rotSpeed);
	cub->calc->dirY = cub->calc->oldDirX * sin(-cub->calc->rotSpeed)
		+ cub->calc->dirY * cos(-cub->calc->rotSpeed);
	cub->calc->oldPlanX = cub->calc->planX;
	cub->calc->planX = cub->calc->planX * cos(-cub->calc->rotSpeed)
		- cub->calc->planY * sin(-cub->calc->rotSpeed);
	cub->calc->planY = cub->calc->oldPlanX * sin(-cub->calc->rotSpeed)
		+ cub->calc->planY * cos(-cub->calc->rotSpeed);
}

void	move_left(t_cub *cub)
{
	cub->calc->oldDirX = cub->calc->dirX;
	cub->calc->dirX = cub->calc->dirX * cos(cub->calc->rotSpeed)
		- cub->calc->dirY * sin(cub->calc->rotSpeed);
	cub->calc->dirY = cub->calc->oldDirX * sin(cub->calc->rotSpeed)
		+ cub->calc->dirY * cos(cub->calc->rotSpeed);
	cub->calc->oldPlanX = cub->calc->planX;
	cub->calc->planX = cub->calc->planX * cos(cub->calc->rotSpeed)
		- cub->calc->planY * sin(cub->calc->rotSpeed);
	cub->calc->planY = cub->calc->oldPlanX * sin(cub->calc->rotSpeed)
		+ cub->calc->planY * cos(cub->calc->rotSpeed);
}

int	move(t_cub *cub)
{
	if (cub->key->forward_w_z > 0 || cub->key->back_s_s > 0)
		move_ver(cub);
	if (cub->key->right_d_d > 0 || cub->key->left_a_q > 0)
		move_hor(cub);
	if (cub->key->rotate_right > 0)
		move_rignt(cub);
	if (cub->key->rotate_left > 0)
		move_left(cub);
	game(cub, COINS);
	return (0);
}
