/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_rgb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboy <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 13:41:01 by mboy              #+#    #+#             */
/*   Updated: 2021/06/07 13:41:04 by mboy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/cub3D.h"

int	parse_rgb_check(char *line, int nb)
{
	int	i;
	int	comma;

	i = 0;
	nb = 0;
	comma = 0;
	while (ft_isalpha(line[i]) == 0)
		i++;
	i++;
	while (line[i] == ' ')
		i++;
	if (ft_isdigit(line[i]) != 1 || i == (int)ft_strlen(line))
		return (-1);
	while (line[++i])
	{
		if (ft_isdigit(line[i]) != 1 && line[i] != ',' && line[i] != ' ')
			return (-1);
		else if (line[i] == ',')
			comma++;
		if (line[i] == ',' && ft_isdigit(line[i + 1]) == 1)
			nb++;
	}
	if (comma != 2 || nb != 2)
		return (-1);
	return (0);
}

int	*parse_rgb_fetch1(char **rgb, char *copy, int *color, int i)
{
	rgb = ft_split(copy, ',');
	if (!rgb)
		return (NULL);
	i = -1;
	while (rgb[++i])
	{
		color[i] = ft_atoi(rgb[i]);
		if (color[i] > 255)
			return (NULL);
		free (rgb[i]);
	}
	free (rgb);
	return (color);
}

int	*parse_rgb_fetch(char *line, int *color)
{
	int		i;
	int		j;
	char	**rgb;
	char	*copy;

	j = 0;
	rgb = NULL;
	color = malloc(sizeof(int) * 4);
	if (!color)
		return (NULL);
	copy = malloc(sizeof(char) * ((int)ft_strlen(line) - 1));
	if (!copy)
		return (NULL);
	i = 0;
	while (ft_isdigit(line[i + 1]) != 1)
		i++;
	while (line[++i])
		copy[j++] = line[i];
	copy[j] = '\0';
	color = parse_rgb_fetch1(rgb, copy, color, i);
	if (!color)
		return (NULL);
	free(copy);
	return (color);
}

int	parse_rgb_select(char *line, int i, t_cub *cub)
{
	int	*floor;
	int	*ceiling;

	floor = NULL;
	ceiling = NULL;
	if (line[i] == 'F')
	{
		floor = parse_rgb_fetch(line, floor);
		if (!floor)
			return (-1);
		cub->parse->floor = ((floor[0] << 16)
				| (floor[1]) << 8 | (floor[2]));
	}
	else if (line[i] == 'C')
	{
		ceiling = parse_rgb_fetch(line, ceiling);
		if (!ceiling)
			return (-1);
		cub->parse->ceiling = ((ceiling[0] << 16)
				| (ceiling[1]) << 8 | (ceiling[2]));
	}
	free (ceiling);
	free (floor);
	return (0);
}

int	parse_rgb(char *line, t_cub *cub)
{
	int			nb;
	int			i;

	nb = 0;
	if (parse_rgb_check(line, nb) == -1)
		return (-1);
	i = -1;
	while (line[++i])
		if (parse_rgb_select(line, i, cub) == -1)
			return (-1);
	return (0);
}
