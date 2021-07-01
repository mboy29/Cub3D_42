/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboy <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 13:40:05 by mboy              #+#    #+#             */
/*   Updated: 2021/06/07 13:40:06 by mboy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/cub3D.h"

void	play_struct_ns(t_cub *cub)
{
	cub->calc->dirY = 0;
	cub->calc->planX = 0;
	if (cub->parse->playD == 'N')
	{
		cub->calc->dirX = -1;
		cub->calc->planY = 0.66;
	}
	else if (cub->parse->playD == 'S')
	{
		cub->calc->dirX = 1;
		cub->calc->planY = -0.66;
	}
}

void	play_struct_we(t_cub *cub)
{
	cub->calc->dirX = 0;
	cub->calc->planY = 0;
	if (cub->parse->playD == 'E')
	{
		cub->calc->dirY = 1;
		cub->calc->planX = 0.66;
	}
	else if (cub->parse->playD == 'W')
	{
		cub->calc->dirY = -1;
		cub->calc->planX = -0.66;
	}
}

int	play_struct(t_cub *cub)
{
	int		i;
	double	res;

	i = -1;
	res = 4.0 / 3.0;
	cub->calc->ratio = ((double)cub->parse->resX
			/ (double)cub->parse->resY) / res;
	cub->calc->posX = cub->parse->playY + 0.5;
	cub->calc->posY = cub->parse->playX + 0.5;
	if (cub->parse->playD == 'N' || cub->parse->playD == 'S')
		play_struct_ns(cub);
	else if (cub->parse->playD == 'E' || cub->parse->playD == 'W')
		play_struct_we(cub);
	cub->calc->moveSpeed = 0.1;
	cub->calc->rotSpeed = 0.033 * 3;
	cub->calc->bufS = malloc(sizeof(double) * cub->parse->resX);
	if (!cub->calc->bufS)
		return (-1);
	while (++i < cub->parse->resX)
		cub->calc->bufS[i] = 0.0;
	cub->ray->resX = cub->parse->resX;
	cub->ray->resY = cub->parse->resY;
	return (0);
}

int	play(t_cub *cub)
{
	if (play_struct(cub) == -1)
		return (ex(cub, 4, NULL));
	cub->ray->mlx_ptr = mlx_init();
	if (!cub->ray->mlx_ptr)
		return (ex(cub, 5, NULL));
	cub->ray->win_ptr = mlx_new_window(cub->ray->mlx_ptr,
			cub->parse->resX, cub->parse->resY, "cub3D");
	cub->ray->img_ptr = mlx_new_image(cub->ray->mlx_ptr,
			cub->parse->resX, cub->parse->resY);
	cub->ray->img_data = mlx_get_data_addr(cub->ray->img_ptr,
			&cub->ray->bpp, &cub->ray->len, &cub->ray->endian);
	if (cub->calc->save == 1)
	{
		if (save(cub) == -1)
			return (ex(cub, 8, NULL));
		return (ex(cub, 9, NULL));
	}
	mlx_hook(cub->ray->win_ptr, 2, (1L << 0), key_press, cub);
	mlx_hook(cub->ray->win_ptr, 3, (1L << 1), key_release, cub);
	mlx_hook(cub->ray->win_ptr, 17, 0, ex_mlx, cub);
	mlx_loop_hook(cub->ray->mlx_ptr, ray, cub);
	mlx_loop(cub->ray->mlx_ptr);
	return (0);
}

int	main(int ac, char **av)
{
	t_cub	*cub;

	cub = malloc(sizeof(t_cub));
	if (!cub)
		return (ex(cub, 1, NULL));
	init(cub);
	if (ac < 2 || ac >= 3)
	{
		if (ac == 3)
		{
			if (ft_strcmp(av[2], "--save") == 0)
				cub->calc->save++;
			else
				return (ex(cub, 11, NULL));
		}
		else
			return (ex(cub, 12, NULL));
	}
	if (parse(av[1], cub) == -1)
		return (-1);
	play(cub);
	free(cub);
	return (0);
}
