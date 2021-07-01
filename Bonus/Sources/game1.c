/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboy <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 13:44:40 by mboy              #+#    #+#             */
/*   Updated: 2021/06/07 17:51:18 by mboy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/bonus_cub3D.h"

void	game_draw(t_cub *cub, int n)
{
	int				i;
	int				j;
	unsigned int	color;

	i = -1;
	color = 0;
	cub->game->startX = 0;
	cub->game->startY = 0;
	cub->game->textX = 0;
	cub->game->startY = 0;
	cub->game->startY = cub->game->drawStartY;
	while (++i < cub->game->newY)
	{
		j = -1;
		cub->game->startX = cub->game->drawStartX;
		while (++j < cub->game->newX)
		{
			cub->game->textX = (int)(cub->game->ratioX * j);
			cub->game->textY = (int)(cub->game->ratioY * i);
			color = color_game(cub, n);
			gen_pixel(cub->ray, cub->game->startX, cub->game->startY, color);
			cub->game->startX++;
		}
		cub->game->startY++;
	}
}

void	game_coins(t_cub *cub)
{
	int	i;

	i = -1;
	if (cub->parse->map[(int)cub->calc->posX][(int)cub->calc->posY] == '5')
	{
		while (cub->sprite[++i])
		{
			if (cub->sprite[i]->x == floor(cub->calc->posX)
				&& cub->sprite[i]->y == floor(cub->calc->posY))
			{
				cub->sprite[i]->pick = 1;
				cub->game->coins++;
			}
			update(cub);
		}
	}
}

void	game_free(t_cub *cub)
{
	int	i;

	mlx_clear_window(cub->ray->mlx_ptr, cub->ray->win_ptr);
	i = -1;
	while (cub->parse->texture[++i])
		free(cub->parse->texture[i]);
	free(cub->parse->texture);
	cub->parse->texture = NULL;
	i = -1;
	while (cub->parse->map[++i])
		free(cub->parse->map[i]);
	free(cub->parse->map);
	cub->parse->map = NULL;
	i = -1;
	while (cub->sprite[++i])
	{
		free(cub->sprite[i]->mlx);
		free(cub->sprite[i]);
	}	
	free(cub->sprite);
	cub->sprite = NULL;
	init_parse(cub->parse);
	free(cub->calc->bufS);
	cub->calc->bufS = NULL;
	cub->sprite = NULL;
}

int	game_reset(t_cub *cub, int level)
{
	game_free(cub);
	if (level == 1)
		if (parse("./Maps/Bonus/map.cub", cub) == -1)
			return (-1);
	if (level == 2)
		if (parse("./Maps/Bonus/map1.cub", cub) == -1)
			return (-1);
	if (level == 3)
		if (parse("./Maps/Bonus/map2.cub", cub) == -1)
			return (-1);
	return (0);
}

int	game(t_cub *cub, int n)
{
	static int	init;

	init = 0;
	if (init == 0)
	{
		if (game_struct(cub) == -1)
			return (-1);
		init = 1;
	}
	if (n == COINS)
	{
		game_coins(cub);
		return (0);
	}
	prep(cub, n);
	game_draw(cub, n);
	mlx_put_image_to_window(cub->ray->mlx_ptr,
		cub->ray->win_ptr, cub->ray->img_ptr, 0, 0);
	return (0);
}
