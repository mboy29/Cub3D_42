/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboy <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 13:41:42 by mboy              #+#    #+#             */
/*   Updated: 2021/06/07 13:41:44 by mboy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/cub3D.h"

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
	cub->wall = malloc(sizeof(t_wall *) * TEXT);
	if (!cub->ray || !cub->wall)
		return (-1);
	init_mlx(cub->ray);
	while (++i < TEXT)
	{
		cub->wall[i] = malloc(sizeof(t_wall));
		if (!cub->wall[i] || init_wall(cub->wall[i]) == -1)
			return (-1);
	}
	return (0);
}

int	init(t_cub *cub)
{
	init_parse_key_calc(cub);
	init_ray_text_game(cub);
	return (0);
}
