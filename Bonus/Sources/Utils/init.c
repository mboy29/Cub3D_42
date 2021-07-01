/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboy <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 13:47:00 by mboy              #+#    #+#             */
/*   Updated: 2021/06/07 13:47:02 by mboy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/bonus_cub3D.h"

int	init_parse_key_calc(t_cub *cub)
{
	cub->parse = malloc(sizeof(t_parse));
	cub->key = malloc(sizeof(t_key));
	cub->calc = malloc(sizeof(t_calc));
	if (!cub->parse || !cub->key || !cub->calc)
		return (-1);
	init_parse(cub->parse);
	init_key(cub->key);
	init_calc1(cub->calc);
	return (0);
}

int	init_ray_text_game(t_cub *cub)
{
	int	i;

	i = -1;
	cub->sprite = NULL;
	cub->ray = malloc(sizeof(t_mlx));
	cub->game = malloc(sizeof(t_game));
	cub->wall = malloc(sizeof(t_wall *) * TEXT);
	cub->floor = malloc(sizeof(t_floor));
	if (!cub->ray || !cub->game || !cub->wall || !cub->floor)
		return (-1);
	init_mlx(cub->ray);
	if (init_game1(cub->game) == -1)
		return (-1);
	while (++i < TEXT)
	{
		cub->wall[i] = malloc(sizeof(t_wall));
		if (!cub->wall[i] || init_wall(cub->wall[i]) == -1)
			return (-1);
	}
	init_floor(cub->floor);
	return (0);
}

int	init(t_cub *cub)
{
	init_parse_key_calc(cub);
	init_ray_text_game(cub);
	return (0);
}
