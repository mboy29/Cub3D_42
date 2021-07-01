/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_text.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboy <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 13:41:31 by mboy              #+#    #+#             */
/*   Updated: 2021/06/07 13:41:32 by mboy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/cub3D.h"

int	parse_text_check(char *text)
{
	int	fd;

	fd = open(text, O_RDONLY);
	if (fd < 0 || fd > 255 || BUFFER_SIZE <= 0)
		return (-1);
	close (fd);
	return (0);
}

int	parse_text_check1(char *line, int text, int start)
{
	static int	check = -1;

	if (text <= check)
		return (-1);
	check = text;
	while (line[start])
	{
		if (line[start] != 'N' && line[start] != 'O' && line[start] != 'S'
			&& line[start] != 'W' && line[start] != 'E' && line[start] != 'A'
			&& line[start] != ' ' && line[start] != '\0')
			return (-1);
		start--;
	}
	return (0);
}

int	parse_text_fetch(char *line, int text, int start, t_cub *cub)
{
	int	i;
	int	j;

	if (parse_text_check1(line, text, start) == -1)
		return (-1);
	cub->parse->texture[text] = malloc(sizeof(char) * (ft_strlen(line) + 1));
	if (!cub->parse->texture[text])
		return (-1);
	j = 0;
	i = start;
	while (line[i] != '.' && line[i])
		if (line[i++] != ' ')
			return (-1);
	if (i == (int)ft_strlen(line))
		return (-1);
	while (line[i] != '\0' && line[i] != ' ')
		cub->parse->texture[text][j++] = line[i++];
	while (line[i])
		if (line[i] != '\0' && line[i++] != ' ')
			return (-1);
	cub->parse->texture[text][j] = '\0';
	if (parse_text_check(cub->parse->texture[text]) == -1)
		return (-1);
	return (0);
}

int	parse_text_letters(char *line, t_cub *cub)
{
	int	i;

	i = -1;
	while (line[++i])
	{
		if (line[i - 1] == ' ' || line[i - 1] == '\0')
		{
			if (line[i] == 'N' && line[i + 1] == 'O' && line[i + 2] == ' ')
				return (parse_text_fetch(line, 0, i + 2, cub));
			if (line[i] == 'S' && line[i + 1] == 'O' && line[i + 2] == ' ')
				return (parse_text_fetch(line, 1, i + 2, cub));
			if (line[i] == 'E' && line[i + 1] == 'A' && line[i + 2] == ' ')
				return (parse_text_fetch(line, 2, i + 2, cub));
			if (line[i] == 'W' && line[i + 1] == 'E' && line[i + 2] == ' ')
				return (parse_text_fetch(line, 3, i + 2, cub));
			if (line[i] == 'S' && line[i + 1] == ' ')
				return (parse_text_fetch(line, 4, i + 1, cub));
		}
	}
	return (0);
}

int	parse_text(char *line, t_cub *cub)
{
	int			i;
	static int	text = 0;
	static int	rgb = 0;

	i = -1;
	while (line[++i])
		if ((line[i] == 'F' || line[i] == 'C') && line[i + 1] == ' ' && text++)
			if (parse_rgb(line, cub) == -1 && rgb++)
				return (-1);
	if (!cub->parse->texture)
	{
		cub->parse->texture = malloc(sizeof(char *) * TEXT);
		if (!cub->parse->texture)
			return (-1);
	}
	if (parse_text_letters(line, cub) == -1)
		return (-1);
	text++;
	cub->parse->texture[5] = NULL;
	if (text == 8 && rgb != 2)
		return (-1);
	return (0);
}
