/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gen.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboy <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 13:39:43 by mboy              #+#    #+#             */
/*   Updated: 2021/06/07 13:39:44 by mboy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/cub3D.h"

void	gen_pixel(t_mlx *mlx, int x, int y, int color)
{
	char	*dst;

	dst = mlx->img_data + (y * mlx->len + x * (mlx->bpp / 8));
	*(unsigned int *)dst = color;
}

void	gen_fullscreen(t_mlx *mlx, int color)
{
	int	y;
	int	x;

	y = -1;
	while (++y != mlx->resY)
	{
		x = -1;
		while (++x != mlx->resX)
			gen_pixel(mlx, x, y, color);
	}
}

void	gen_sqr(t_mlx *mlx, int sqr, int color, int colorline)
{
	int	i;
	int	j;

	j = mlx->startY - 1;
	while (++j != mlx->startY + sqr)
	{
		i = mlx->startX - 1;
		while (++i != mlx->startX + sqr)
		{
			if (i == mlx->startX || j == mlx->startY
				|| i == mlx->startX + sqr || j == mlx->startY + sqr)
				gen_pixel(mlx, i, j, colorline);
			else
				gen_pixel(mlx, i, j, color);
		}
	}
}
