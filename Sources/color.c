/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboy <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 13:39:31 by mboy              #+#    #+#             */
/*   Updated: 2021/06/07 13:39:33 by mboy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/cub3D.h"

unsigned int	color_wall(t_cub *cub, int n)
{
	char	*ptr;

	ptr = NULL;
	ptr = cub->wall[n]->mlx->img_data + (cub->calc->textY
			* cub->wall[n]->mlx->len + cub->calc->textX
			* (cub->wall[n]->mlx->bpp / 8));
	return (*(unsigned int *)ptr);
}

unsigned int	color_sprite(t_cub *cub, int n)
{
	char	*ptr;

	ptr = NULL;
	ptr = cub->sprite[n]->mlx->img_data + (cub->sprite[n]->texY
			* cub->sprite[n]->mlx->len + cub->sprite[n]->texX
			* (cub->sprite[n]->mlx->bpp / 8));
	return (*(unsigned int *)ptr);
}
