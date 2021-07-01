/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboy <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 13:46:06 by mboy              #+#    #+#             */
/*   Updated: 2021/06/07 13:46:08 by mboy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/bonus_cub3D.h"

void	sprites_assign(t_cub *cub, int i)
{
	if (cub->sprite[i]->nb == '2')
		cub->sprite[i]->mlx->img_ptr
			= mlx_xpm_file_to_image(cub->sprite[i]->mlx->mlx_ptr,
				cub->parse->texture[4], &cub->calc->textW,
				&cub->calc->textH);
	if (cub->sprite[i]->nb == '3')
		cub->sprite[i]->mlx->img_ptr
			= mlx_xpm_file_to_image(cub->sprite[i]->mlx->mlx_ptr,
				cub->parse->texture[5], &cub->calc->textW,
				&cub->calc->textH);
	if (cub->sprite[i]->nb == '4')
		cub->sprite[i]->mlx->img_ptr
			= mlx_xpm_file_to_image(cub->sprite[i]->mlx->mlx_ptr,
				cub->parse->texture[6], &cub->calc->textW,
				&cub->calc->textH);
	if (cub->sprite[i]->nb == '5')
		cub->sprite[i]->mlx->img_ptr
			= mlx_xpm_file_to_image(cub->sprite[i]->mlx->mlx_ptr,
				cub->parse->texture[7], &cub->calc->textW,
				&cub->calc->textH);
}

int	sprites_struct(t_cub *cub)
{
	int	i;

	i = -1;
	while (++i < cub->parse->sprites)
	{
		cub->sprite[i]->mlx->mlx_ptr = cub->ray->mlx_ptr;
		sprites_assign(cub, i);
		if (!cub->sprite[i]->mlx->img_ptr)
			return (-1);
		cub->sprite[i]->mlx->img_data
			= mlx_get_data_addr(cub->sprite[i]->mlx->img_ptr,
				&cub->sprite[i]->mlx->bpp, &cub->sprite[i]->mlx->len,
				&cub->sprite[i]->mlx->endian);
	}
	return (0);
}

void	sprites_sort(t_cub *cub)
{
	int	i;
	int	j;

	i = -1;
	while (++i < cub->parse->sprites)
		cub->sprite[i]->distS = ((cub->calc->posX - (double)cub->sprite[i]->x)
				* (cub->calc->posX - (double)cub->sprite[i]->x)
				+ (cub->calc->posY - (double)cub->sprite[i]->y)
				* (cub->calc->posY - (double)cub->sprite[i]->y));
	i = -1;
	while (++i < cub->parse->sprites)
	{
		j = -1;
		while (++j < cub->parse->sprites - i - 1)
			if (cub->sprite[j + 1]->distS > cub->sprite[j]->distS)
				swap(cub, j, j + 1);
	}
}

int	sprites(t_cub *cub)
{
	int	i;

	i = -1;
	sprites_sort(cub);
	if (sprites_struct(cub) == -1)
		return (-1);
	while (++i < cub->parse->sprites)
	{
		if (cub->sprite[i]->pick == 0)
		{
			sprites_calc(cub, i);
			sprites_end_startX(cub, i);
			sprites_end_startY(cub, i);
			sprites_draw(cub, i);
		}
	}
	return (0);
}
