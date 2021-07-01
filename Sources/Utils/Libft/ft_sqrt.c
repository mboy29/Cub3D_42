/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboy <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 13:42:55 by mboy              #+#    #+#             */
/*   Updated: 2021/06/07 13:42:57 by mboy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../Includes/cub3D.h"

double	ft_sqrt(double nb)
{
	double	sqrt;

	if (nb < 0)
		return (0);
	sqrt = 1;
	while (sqrt * sqrt < nb)
		++sqrt;
	if (sqrt * sqrt == nb)
		return (sqrt);
	return (0);
}
