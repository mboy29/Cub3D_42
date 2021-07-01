/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboy <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 13:45:21 by mboy              #+#    #+#             */
/*   Updated: 2021/06/07 13:45:22 by mboy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/bonus_cub3D.h"

int	output_start(t_cub *cub)
{
	if (cub->game->play == 0)
	{
		if (game(cub, 11) == -1)
			return (-1);
		if (cub->key->enter > 0)
		{
			mlx_clear_window(cub->ray->mlx_ptr, cub->ray->win_ptr);
			cub->game->play = 1;
		}
	}
	return (0);
}

int	output_play(t_cub *cub)
{
	if (cub->game->play == 1)
	{
		if (ray(cub) == -1)
			return (ex(cub, 6, NULL));
		else if (map(cub) == -1)
			return (ex(cub, 7, NULL));
		move(cub);
		mlx_put_image_to_window(cub->ray->mlx_ptr,
			cub->ray->win_ptr, cub->ray->img_ptr, 0, 0);
		game(cub, cub->game->coins);
		game(cub, 12);
		if (cub->game->coins == 10)
			cub->game->play = 2;
	}
	return (0);
}

int	output_level(t_cub *cub)
{
	if (cub->game->play == 2 && cub->game->level < 3)
	{
		if (ray(cub) == -1)
			return (ex(cub, 6, NULL));
		else if (map(cub) == -1)
			return (ex(cub, 7, NULL));
		mlx_put_image_to_window(cub->ray->mlx_ptr,
			cub->ray->win_ptr, cub->ray->img_ptr, 0, 0);
		game(cub, cub->game->coins);
		game(cub, 13);
		game(cub, 14);
		if (cub->key->enter > 0)
		{
			cub->game->level++;
			cub->game->play = 1;
			cub->game->coins = 0;
			if (game_reset(cub, cub->game->level) == -1)
				return (-1);
			play_struct(cub);
			output(cub);
		}
	}
	return (0);
}

int	output_end(t_cub *cub)
{
	if (cub->game->play == 2 && cub->game->level == 3)
	{
		gen_fullscreen(cub->ray, 0x00271C17);
		game(cub, 15);
		if (cub->key->enter > 0)
		{
			cub->game->play = 1;
			cub->game->level = 0;
		}
		else if (cub->key->space_exit > 0)
			return (ex(cub, 0, NULL));
	}
	return (0);
}

int	output(t_cub *cub)
{
	if (cub->key->space_exit > 0)
		return (ex(cub, 0, NULL));
	if (output_start(cub) == -1)
		return (ex(cub, 10, NULL));
	if (output_play(cub) == -1
		|| output_level(cub) == -1
		|| output_end(cub) == -1)
		return (-1);
	return (0);
}
