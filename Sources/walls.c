/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboy <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 13:40:36 by mboy              #+#    #+#             */
/*   Updated: 2021/06/07 13:40:38 by mboy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/cub3D.h"

int	walls_struct(t_cub *cub)
{
	int	i;

	i = -1;
	while (++i < TEXT - 1)
	{
		cub->wall[i]->mlx->mlx_ptr = cub->ray->mlx_ptr;
		cub->wall[i]->mlx->img_ptr
			= mlx_xpm_file_to_image(cub->wall[i]->mlx->mlx_ptr,
				cub->parse->texture[i], &cub->calc->textW, &cub->calc->textH);
		if (!cub->wall[i]->mlx->img_ptr)
			return (-1);
		cub->wall[i]->mlx->img_data
			= mlx_get_data_addr(cub->wall[i]->mlx->img_ptr,
				&cub->wall[i]->mlx->bpp, &cub->wall[i]->mlx->len,
				&cub->wall[i]->mlx->endian);
	}
	return (1);
}

int	walls_chose(t_cub *cub)
{
	int	text;

	text = 0;
	if (cub->calc->side == 0 && cub->calc->rayDirX < 0)
		text = 0;
	else if (cub->calc->side == 0 && cub->calc->rayDirX >= 0)
		text = 1;
	else if (cub->calc->side == 1 && cub->calc->rayDirY < 0)
		text = 2;
	else if (cub->calc->side == 1 && cub->calc->rayDirY >= 0)
		text = 3;
	return (text);
}

void	walls_calc(t_cub *cub)
{
	cub->calc->textNum = 0;
	cub->calc->wallX = 0.0;
	cub->calc->textX = 0;
	cub->calc->step = 0;
	cub->calc->textPos = 0.0;
	cub->calc->textNum = cub->parse->map[cub->calc->mapX][cub->calc->mapY];
	if (cub->calc->side == 0)
		cub->calc->wallX = cub->calc->posY + cub->calc->perpwallDist
			* cub->calc->rayDirY;
	else
		cub->calc->wallX = cub->calc->posX + cub->calc->perpwallDist
			* cub->calc->rayDirX;
	cub->calc->wallX -= floor(cub->calc->wallX);
	cub->calc->textX = (int)(cub->calc->wallX * (double)cub->calc->textW);
	if ((cub->calc->side == 0 && cub->calc->rayDirX > 0)
		|| (cub->calc->side == 1 && cub->calc->rayDirY < 0))
		cub->calc->textX = cub->calc->textW - cub->calc->textX - 1;
	cub->calc->step = 1.0 * cub->calc->textH / cub->calc->lineHeight;
	cub->calc->textPos = (cub->calc->drawStart - cub->parse->resY
			/ 2 + cub->calc->lineHeight / 2) * cub->calc->step;
}

void	walls_draw(t_cub *cub, int x)
{
	int				i;
	int				y;
	unsigned int	color;

	i = -1;
	while (++i <= cub->calc->drawStart)
		gen_pixel(cub->ray, x, i, cub->parse->ceiling);
	color = 0;
	y = cub->calc->drawStart - 1;
	while (++y <= cub->calc->drawEnd)
	{
		if (cub->calc->textPos < 0)
			cub->calc->textY = 0;
		else
			cub->calc->textY = cub->calc->textPos;
		cub->calc->textPos += cub->calc->step;
		color = color_wall(cub, walls_chose(cub));
		if (cub->calc->side == 1)
			color = (color >> 1) & 8355711;
		gen_pixel(cub->ray, x, y, color);
	}
	i = y - 1;
	while (++i < cub->parse->resY)
		gen_pixel(cub->ray, x, i, cub->parse->floor);
}

int	walls(t_cub *cub, int x)
{
	static int	init = 0;

	if (init == 0)
	{
		if (walls_struct(cub) == -1)
			return (-1);
		init = 1;
	}
	walls_calc(cub);
	walls_draw(cub, x);
	return (0);
}
