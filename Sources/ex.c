/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboy <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 13:39:37 by mboy              #+#    #+#             */
/*   Updated: 2021/06/07 13:39:39 by mboy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/cub3D.h"

int	ex_mlx(t_cub *cub, int error)
{
	printf("End Of Game.\n");
	if (error > 5 || error == 0)
	{
		if (cub->ray->img_ptr)
			mlx_destroy_image(cub->ray->mlx_ptr, cub->ray->img_ptr);
		if (cub->ray->win_ptr)
			mlx_destroy_window(cub->ray->mlx_ptr, cub->ray->win_ptr);
	}
	exit (0);
	free (cub);
	if (error == 0)
		return (0);
	return (-1);
}

void	ex_main(int error, void *elem)
{
	printf("Error\n");
	if (error == 1)
		printf("%s Malloc Struct Cub.\n", STR);
	else if (error == 2)
		printf("%s Open %s.\n", STR, (char *)elem);
	else if (error == 3)
		printf("%s Parse %s.\n", STR, (char *)elem);
}

void	ex_play(int error)
{
	printf("Error\n");
	if (error == 4)
		printf("%s Prepare Mlx Loop.\n", STR);
	else if (error == 5)
		printf("%s Init Mlx.\n", STR);
	else if (error == 6)
		printf("%s Raycast.\n", STR);
	else if (error == 7)
		printf("%s Treat Map.\n", STR);
}

void	ex_save(int error)
{
	if (error != 9)
		printf("Error\n");
	if (error == 8)
		printf("%s Save First Image.\n", STR);
	if (error == 9)
		printf("First Image Has Been Successfully Created.\n");
	if (error == 11)
		printf("Wrong Third Argument.\n");
	if (error == 12)
		printf("Wrong Number Of Arguments\n");
}

int	ex(t_cub *cub, int error, void *elem)
{
	if (error > 0 && error <= 3)
		ex_main(error, elem);
	if ((error > 3 && error < 8) || error == 10)
		ex_play(error);
	if (error >= 8 && error <= 12)
		ex_save(error);
	ex_mlx(cub, error);
	return (-1);
}
