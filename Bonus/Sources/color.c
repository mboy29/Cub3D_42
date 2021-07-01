/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboy <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 13:44:22 by mboy              #+#    #+#             */
/*   Updated: 2021/06/07 13:44:24 by mboy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/bonus_cub3D.h"

unsigned int	color_wall(t_cub *cub, int n)
{
	char	*ptr;

	ptr = NULL;
	ptr = cub->wall[n]->mlx->img_data + (cub->calc->textY
			* cub->wall[n]->mlx->len + cub->calc->textX
			* (cub->wall[n]->mlx->bpp / 8));
	return (*(unsigned int *)ptr);
}

unsigned int	color_floor(t_cub *cub, int n)
{
	char	*ptr;

	ptr = NULL;
	ptr = cub->wall[n]->mlx->img_data + (cub->floor->textY
			* cub->wall[n]->mlx->len + cub->floor->textX
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

unsigned int	color_game(t_cub *cub, int n)
{
	char	*ptr;

	ptr = NULL;
	ptr = cub->game->mlx[n]->img_data + (cub->game->textY
			* cub->game->mlx[n]->len + cub->game->textX
			* (cub->game->mlx[n]->bpp / 8));
	return (*(unsigned int *)ptr);
}
