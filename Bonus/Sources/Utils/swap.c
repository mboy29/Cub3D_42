/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboy <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 13:47:29 by mboy              #+#    #+#             */
/*   Updated: 2021/06/07 13:47:30 by mboy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/bonus_cub3D.h"

void	swap(t_cub *cub, int swap1, int swap2)
{
	int		tmpX;
	int		tmpY;
	int		tmpNB;
	int		tmpPick;
	double	tmpDist;

	tmpX = cub->sprite[swap1]->x;
	tmpY = cub->sprite[swap1]->y;
	tmpNB = cub->sprite[swap1]->nb;
	tmpPick = cub->sprite[swap1]->pick;
	tmpDist = cub->sprite[swap1]->distS;
	cub->sprite[swap1]->x = cub->sprite[swap2]->x;
	cub->sprite[swap1]->y = cub->sprite[swap2]->y;
	cub->sprite[swap1]->nb = cub->sprite[swap2]->nb;
	cub->sprite[swap1]->pick = cub->sprite[swap2]->pick;
	cub->sprite[swap1]->distS = cub->sprite[swap2]->distS;
	cub->sprite[swap2]->x = tmpX;
	cub->sprite[swap2]->y = tmpY;
	cub->sprite[swap2]->nb = tmpNB;
	cub->sprite[swap2]->pick = tmpPick;
	cub->sprite[swap2]->distS = tmpDist;
}
