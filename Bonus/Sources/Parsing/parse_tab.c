/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_tab.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboy <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 13:46:41 by mboy              #+#    #+#             */
/*   Updated: 2021/06/07 13:46:42 by mboy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/bonus_cub3D.h"

int	parse_tab_fetch(char *line, int i, t_cub *cub)
{
	static int	map = 0;

	if (ft_strlen(line) > 0)
	{
		if (map > 0 && is_map_c(line) == -1)
			return (-1);
		if (is_map_c(line) != -1 && i <= cub->parse->mapY)
		{
			if (copy_map(cub, line, i) == -1)
				return (-1);
			if (!cub->parse->map[i++])
				return (-1);
			map++;
		}
		if (map == cub->parse->mapY)
			map = 0;
		return (i);
	}
	return (0);
}

int	parse_tab_check1(t_cub *cub, int y, int x)
{
	if (parse_sprite_pos(cub, cub->parse->map[y][x], x, y) == -1)
		return (-1);
	if (cub->parse->map[y][x] == 'N'
		|| cub->parse->map[y][x] == 'S'
		|| cub->parse->map[y][x] == 'E'
		|| cub->parse->map[y][x] == 'W')
		cub->parse->play += parse_play(x, y, cub->parse->map[y][x], cub);
	if (cub->parse->map[y][x] == '0' || cub->parse->map[y][x] == '2'
		|| cub->parse->map[y][x] == '3' || cub->parse->map[y][x] == '4'
		|| cub->parse->map[y][x] == '5')
		if (cub->parse->map[y + 1][x] == ' '
			|| cub->parse->map[y - 1][x] == ' '
			|| cub->parse->map[y][x + 1] == ' '
			|| cub->parse->map[y][x - 1] == ' '
			|| cub->parse->map[y][x + 1] == '\0')
			return (-1);
	if (x == 0 && (cub->parse->map[y][x] == '0'
		|| cub->parse->map[y][x] == '2'
		|| cub->parse->map[y][x] == '3'
		|| cub->parse->map[y][x] == '4'
		|| cub->parse->map[y][x] == '5'))
		return (-1);
	if (cub->parse->map[y][x] == '\t')
		return (-1);
	return (0);
}

int	parse_tab_check(t_cub *cub)
{
	int	x;
	int	y;

	y = -1;
	while (cub->parse->map[++y])
	{
		x = -1;
		while (cub->parse->map[y][++x])
			if (parse_tab_check1(cub, y, x) == -1)
				return (-1);
	}
	if (cub->parse->play != 1)
		return (-1);
	return (0);
}

int	parse_tab_line(char *str, t_cub *cub, int ret)
{
	int		i;
	int		fd;
	char	*line;

	fd = open_map(str);
	if (fd == -1)
		return (-1);
	i = 0;
	ret = get_next_line(fd, &line);
	while (ret > 0)
	{
		if (parse_tab_fetch(line, i, cub) == -1)
			return (-1);
		if (ft_strlen(line) > 0 && is_map_c(line) != -1)
			i++;
		free(line);
		ret = get_next_line(fd, &line);
	}
	i = parse_tab_fetch(line, i, cub);
	if (i == -1)
		return (-1);
	cub->parse->map[i] = NULL;
	close (fd);
	free(line);
	return (0);
}

int	parse_tab(char *str, t_cub *cub)
{
	cub->parse->map = malloc(sizeof(char *) * (cub->parse->mapY + 1));
	if (!cub->parse->map)
		return (-1);
	if (parse_tab_line(str, cub, 1) == -1 || parse_tab_check(cub) == -1)
		return (-1);
	return (0);
}
