/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboy <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 13:47:33 by mboy              #+#    #+#             */
/*   Updated: 2021/06/07 13:47:34 by mboy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/bonus_cub3D.h"

int	update2(t_cub *cub, int x, int y)
{
	int	i;

	i = -1;
	while (cub->sprite[++i])
		if (cub->sprite[i]->pick == 1
			&& cub->sprite[i]->x == y && cub->sprite[i]->y == x)
			return (1);
	return (0);
}

int	update3(t_cub *cub, char **tmp)
{
	int	i;

	i = -1;
	while (cub->parse->map[++i])
		free(cub->parse->map[i]);
	free(cub->parse->map);
	cub->parse->map = malloc(sizeof(char *) * (cub->parse->mapY + 1));
	if (!cub->parse->map)
		return (-1);
	i = -1;
	while (++i != cub->parse->mapY)
	{
		cub->parse->map[i] = ft_strdup(tmp[i]);
		free(tmp[i]);
	}
	cub->parse->map[i] = NULL;
	return (0);
}

int	update1(t_cub *cub, int y, char **tmp)
{
	int		x;

	tmp[y] = malloc(sizeof(char) * (cub->parse->mapX + 1));
	if (!tmp[y])
		return (-1);
	x = -1;
	while (++x != cub->parse->mapX)
	{
		if (cub->parse->map[y][x] == '5' && update2(cub, x, y) == 1)
			tmp[y][x] = '0';
		else
			tmp[y][x] = cub->parse->map[y][x];
	}
	tmp[y][x] = '\0';
	return (0);
}

int	update(t_cub *cub)
{
	int		y;
	char	**tmp;

	tmp = malloc(sizeof(char *) * (cub->parse->mapY + 1));
	if (!tmp)
		return (-1);
	y = -1;
	while (++y != cub->parse->mapY)
		if (update1(cub, y, tmp) == -1)
			return (-1);
	tmp[y] = NULL;
	update3(cub, tmp);
	free(tmp);
	return (0);
}
