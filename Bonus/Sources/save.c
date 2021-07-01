/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboy <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 13:46:02 by mboy              #+#    #+#             */
/*   Updated: 2021/06/07 13:46:04 by mboy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/bonus_cub3D.h"

void	save_header(t_cub *cub, int fd)
{
	int	i;
	int	tmp;

	i = -1;
	write(fd, "BM", 2);
	tmp = 14 + 40 + 4 * cub->parse->resX * cub->parse->resY;
	write(fd, &tmp, 4);
	tmp = 0;
	write(fd, &tmp, 2);
	write(fd, &tmp, 2);
	tmp = 54;
	write(fd, &tmp, 4);
	tmp = 40;
	write(fd, &tmp, 4);
	write(fd, &cub->parse->resX, 4);
	write(fd, &cub->parse->resY, 4);
	tmp = 1;
	write(fd, &tmp, 2);
	write(fd, &cub->ray->bpp, 2);
	tmp = 0;
	while (++i != 6)
		write(fd, &tmp, 4);
}

void	save_loop(t_cub *cub, int fd)
{
	int	x;
	int	y;
	int	r;
	int	g;
	int	b;

	y = cub->parse->resY;
	while (--y >= 0)
	{
		x = -1;
		while (++x < cub->parse->resX)
		{
			r = cub->ray->img_data[y * cub->ray->len
				+ x * cub->ray->bpp / 8];
			g = cub->ray->img_data[y * cub->ray->len
				+ x * cub->ray->bpp / 8 + 1];
			b = cub->ray->img_data[y * cub->ray->len
				+ x * cub->ray->bpp / 8 + 2];
			write(fd, &r, 1);
			write(fd, &g, 1);
			write(fd, &b, 1);
			write(fd, "\0", 1);
		}
	}
}

int	save(t_cub *cub)
{
	int	fd;

	fd = open("./screenshot.bmp", O_CREAT | O_RDWR);
	if (ray(cub) == -1 || map(cub) == -1 || fd == -1)
		return (-1);
	save_header(cub, fd);
	save_loop(cub, fd);
	system("chmod 777 screenshot.bmp");
	close (fd);
	return (0);
}
