/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboy <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 13:40:52 by mboy              #+#    #+#             */
/*   Updated: 2021/06/07 13:40:54 by mboy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/cub3D.h"

int	parse_play(int x, int y, char c, t_cub *cub)
{
	cub->parse->playX = x;
	cub->parse->playY = y;
	cub->parse->playD = c;
	cub->parse->map[y][x] = '0';
	return (1);
}

void	parse_size(char *line, t_cub *cub)
{
	if (is_map_c(line) != -1)
	{
		if (cub->parse->mapX < (int)ft_strlen(line))
			cub->parse->mapX = ft_strlen(line);
		cub->parse->mapY++;
	}
}

int	parse_line(char *line, t_cub *cub)
{
	int	i;

	parse_size(line, cub);
	parse_sprite(cub, line);
	i = -1;
	while (line[++i])
	{
		if (line[i] == 'R' && line[i + 1] == ' ')
		{
			cub->parse->letter++;
			if (parse_res(line, cub) == -1)
				return (-1);
		}
		if ((line[i] == 'N' && line[i + 1] == 'O') || (line[i] == 'S'
				&& line[i + 1] == 'O') || (line[i] == 'E' && line[i + 1] == 'A')
			|| (line[i] == 'W' && line[i + 1] == 'E') || (line[i] == 'S'
				&& line[i + 1] == ' ') || (line[i] == 'F' && line[i + 1] == ' ')
			|| (line[i] == 'C' && line[i + 1] == ' '))
		{
			cub->parse->letter++;
			if (parse_text(line, cub) == -1)
				return (-1);
		}
	}
	return (0);
}

int	parse_check(char *line)
{
	int	i;

	i = 0;
	while (line[i] == ' ')
		i++;
	if (line[i] != 'N' && line[i] != 'S' && line[i] != 'E'
		&& line[i] != 'W' && line[i] != 'F' && line[i] != 'C'
		&& line[i] != '1' && line[i] != ' ' && line[i] != 'R'
		&& line[i] != '\0')
		return (-1);
	return (0);
}

int	parse(char *str, t_cub *cub)
{
	int		fd;
	int		ret;
	char	*line;

	fd = open_map(str);
	if (fd == -1)
		return (ex(cub, 2, str));
	line = NULL;
	ret = get_next_line(fd, &line);
	while (ret > 0)
	{
		if (ret == -1 || parse_check(line) == -1 || parse_line(line, cub) == -1)
			return (ex(cub, 3, str));
		free (line);
		ret = get_next_line(fd, &line);
	}
	if (parse_line(line, cub) == -1 || parse_check(line) == -1
		|| cub->parse->letter != 8)
		return (ex(cub, 3, str));
	free (line);
	close (fd);
	if (parse_tab(str, cub) == -1 || cub->parse->floor == 0
		|| cub->parse->ceiling == 0)
		return (ex(cub, 3, str));
	return (0);
}
