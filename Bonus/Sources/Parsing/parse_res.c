/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_res.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboy <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 13:46:32 by mboy              #+#    #+#             */
/*   Updated: 2021/06/07 13:46:34 by mboy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/bonus_cub3D.h"

int	parse_res_check(char *line)
{
	int	i;
	int	nb;
	int	space;

	i = 0;
	nb = 0;
	while (ft_isdigit(line[i]) != 1 && line[i])
		i++;
	if (i == (int)ft_strlen(line))
		return (-1);
	space = 0;
	while (line[i])
	{
		if (ft_isdigit(line[i]) == 0 && line[i] != ' ')
			return (-1);
		else if (line[i] == ' ')
			space++;
		if (line[i] == ' ' && ft_isdigit(line[i + 1]) == 1)
			nb++;
		i++;
	}
	if (space < 1 || nb != 1)
		return (-1);
	return (0);
}

char	*parse_res_fetch(char *line, int i)
{
	int		j;
	int		k;
	char	*res;

	k = i;
	while (ft_isdigit(line[i]) == 1)
		i++;
	res = malloc(sizeof(char) * (i - k + 1));
	if (!res)
		return (NULL);
	i = k;
	j = 0;
	while (ft_isdigit(line[i]) == 1)
		res[j++] = line[i++];
	res[j] = '\0';
	return (res);
}

int	parse_res_loop(char *line, char **res, int j, int k)
{
	int	i;

	i = 0;
	while (i != 2)
	{
		if (i == 0)
			res[i] = parse_res_fetch(line, k);
		else
			res[i] = parse_res_fetch(line, j + 1);
		if (!res[i++])
			return (-1);
	}
	return (0);
}

int	parse_res_limits(t_cub *cub)
{
	if (cub->parse->resX <= 1 || cub->parse->resY <= 1)
		return (-1);
	else if (cub->parse->resX <= 320)
		cub->parse->resX = 320;
	else if (cub->parse->resY <= 200)
		cub->parse->resY = 200;
	else if (cub->parse->resX > 1920)
		cub->parse->resX = 1920;
	else if (cub->parse->resY > 1080)
		cub->parse->resY = 1080;
	return (0);
}

int	parse_res(char *line, t_cub *cub)
{
	int		j;
	int		k;
	char	*res[2];

	if (parse_res_check(line) == -1)
		return (-1);
	k = -1;
	while (ft_isdigit(line[++k]) == 0)
		if (line[k] != ' ' && line[k] != '\0' && line[k] != 'R')
			return (-1);
	j = (int)ft_strlen(line);
	while (ft_isdigit(line[j]) == 0)
		j--;
	while (line[j] != ' ')
		j--;
	if (parse_res_loop(line, res, j, k) == -1)
		return (-1);
	cub->parse->resX = ft_atoi(res[0]);
	cub->parse->resY = ft_atoi(res[1]);
	if (parse_res_limits(cub) == -1)
		return (-1);
	free(res[0]);
	free(res[1]);
	return (0);
}
