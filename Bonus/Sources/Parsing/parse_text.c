/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_text.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboy <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 13:46:45 by mboy              #+#    #+#             */
/*   Updated: 2021/06/07 13:46:50 by mboy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/bonus_cub3D.h"

int	parse_text_check(char *text)
{
	int	fd;

	fd = open(text, O_RDONLY);
	if (fd < 0 || fd > 255 || BUFFER_SIZE <= 0)
		return (-1);
	return (0);
}

int	parse_text_check1(char *line, int text, int start)
{
	static int	check = -1;

	if (text <= check || check + 1 != text)
		return (-1);
	check++;
	while (start > 0)
	{
		if (line[start] == 'N' || line[start] == 'O' || line[start] == 'S'
			|| line[start] == 'W' || line[start] == 'E' || line[start] == 'A'
			|| line[start] == '1' || line[start] == '2' || line[start] == '3'
			|| line[start] == '4' || line[start] == 'C' || line[start] == 'F'
			|| line[start] == ' ' || line[start] == '\0')
			start--;
		else
			return (-1);
	}
	if (check == 9 && text == 9)
		check = -1;
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

int	parse_text_letters(char *line, int i, t_cub *cub)
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
		if (line[i] == 'S' && line[i + 1] == '1' && line[i + 2] == ' ')
			return (parse_text_fetch(line, 4, i + 2, cub));
		if (line[i] == 'S' && line[i + 1] == '2' && line[i + 2] == ' ')
			return (parse_text_fetch(line, 5, i + 2, cub));
		if (line[i] == 'S' && line[i + 1] == '3' && line[i + 2] == ' ')
			return (parse_text_fetch(line, 6, i + 2, cub));
		if (line[i] == 'S' && line[i + 1] == '4' && line[i + 2] == ' ')
			return (parse_text_fetch(line, 7, i + 2, cub));
		if (line[i] == 'F' && line[i + 1] == ' ')
			return (parse_text_fetch(line, 8, i + 1, cub));
		if (line[i] == 'C' && line[i + 1] == ' ')
			return (parse_text_fetch(line, 9, i + 1, cub));
	}
	return (0);
}

int	parse_text(char *line, t_cub *cub)
{
	int	i;
	int	text;

	if (!cub->parse->texture)
	{
		cub->parse->texture = malloc(sizeof(char *) * (TEXT + 1));
		if (!cub->parse->texture)
			return (-1);
	}
	i = -1;
	text = 0;
	while (line[++i])
		if (parse_text_letters(line, i, cub) == -1)
			return (-1);
	cub->parse->texture[10] = NULL;
	return (0);
}
