/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboy <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 13:44:44 by mboy              #+#    #+#             */
/*   Updated: 2021/06/07 13:44:45 by mboy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/bonus_cub3D.h"

char	**game_text(void)
{
	char	**game;

	game = malloc(sizeof(char *) * 16);
	if (!game)
		return (NULL);
	game[0] = "./Textures/xpm/zero.xpm";
	game[1] = "./Textures/xpm/one.xpm";
	game[2] = "./Textures/xpm/two.xpm";
	game[3] = "./Textures/xpm/three.xpm";
	game[4] = "./Textures/xpm/four.xpm";
	game[5] = "./Textures/xpm/five.xpm";
	game[6] = "./Textures/xpm/six.xpm";
	game[7] = "./Textures/xpm/seven.xpm";
	game[8] = "./Textures/xpm/eight.xpm";
	game[9] = "./Textures/xpm/nine.xpm";
	game[10] = "./Textures/xpm/ten.xpm";
	game[11] = "./Textures/xpm/start.xpm";
	game[12] = "./Textures/xpm/mess.xpm";
	game[13] = "./Textures/xpm/mess1.xpm";
	game[14] = "./Textures/xpm/level.xpm";
	game[15] = "./Textures/xpm/end.xpm";
	return (game);
}

void	game_assign(t_cub *cub, char **game, int i)
{
	if (i >= 0 && i <= 10)
		cub->game->mlx[i]->img_ptr = mlx_xpm_file_to_image(
				cub->game->mlx[i]->mlx_ptr, game[i],
				&cub->game->numW, &cub->game->numH);
	if (i == 11)
		cub->game->mlx[i]->img_ptr = mlx_xpm_file_to_image(
				cub->game->mlx[i]->mlx_ptr, game[i],
				&cub->game->startW, &cub->game->startH);
	if (i == 12 || i == 13)
		cub->game->mlx[i]->img_ptr = mlx_xpm_file_to_image(
				cub->game->mlx[i]->mlx_ptr, game[i],
				&cub->game->messW, &cub->game->messH);
	if (i == 14)
		cub->game->mlx[i]->img_ptr = mlx_xpm_file_to_image(
				cub->game->mlx[i]->mlx_ptr, game[i],
				&cub->game->levelW, &cub->game->levelH);
	if (i == 15)
		cub->game->mlx[i]->img_ptr = mlx_xpm_file_to_image(
				cub->game->mlx[i]->mlx_ptr, game[i],
				&cub->game->endW, &cub->game->endH);
}

int	game_struct(t_cub *cub)
{
	int		i;
	char	**game;

	game = game_text();
	i = -1;
	while (++i < COINS - 1)
	{
		cub->game->mlx[i]->mlx_ptr = cub->ray->mlx_ptr;
		game_assign(cub, game, i);
		if (!cub->game->mlx[i]->img_ptr)
			return (-1);
		cub->game->mlx[i]->img_data = mlx_get_data_addr(
				cub->game->mlx[i]->img_ptr,
				&cub->game->mlx[i]->bpp, &cub->game->mlx[i]->len,
				&cub->game->mlx[i]->endian);
	}
	free(game);
	return (0);
}
