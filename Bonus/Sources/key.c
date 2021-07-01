/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboy <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 13:44:52 by mboy              #+#    #+#             */
/*   Updated: 2021/06/07 13:44:59 by mboy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/bonus_cub3D.h"

int	key_press(int keycode, t_cub *cub)
{
	if (keycode == ENTER)
		cub->key->enter++;
	else if (keycode == EXIT)
		cub->key->space_exit++;
	else if (keycode == FORWARD_W_Z)
		cub->key->forward_w_z++;
	else if (keycode == BACK_S_S)
		cub->key->back_s_s++;
	else if (keycode == RIGHT_D_D)
		cub->key->right_d_d++;
	else if (keycode == LEFT_A_Q)
		cub->key->left_a_q++;
	else if (keycode == ROTATE_RIGHT)
		cub->key->rotate_right++;
	else if (keycode == ROTATE_LEFT)
		cub->key->rotate_left++;
	return (0);
}

int	key_release(int keycode, t_cub *cub)
{
	if (keycode == ENTER)
		cub->key->enter = 0;
	else if (keycode == EXIT)
		cub->key->space_exit = 0;
	else if (keycode == FORWARD_W_Z)
		cub->key->forward_w_z = 0;
	else if (keycode == BACK_S_S)
		cub->key->back_s_s = 0;
	else if (keycode == RIGHT_D_D)
		cub->key->right_d_d = 0;
	else if (keycode == LEFT_A_Q)
		cub->key->left_a_q = 0;
	else if (keycode == ROTATE_RIGHT)
		cub->key->rotate_right = 0;
	else if (keycode == ROTATE_LEFT)
		cub->key->rotate_left = 0;
	return (0);
}
