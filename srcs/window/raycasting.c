/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbernaze <cbernaze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 11:25:16 by cbernaze          #+#    #+#             */
/*   Updated: 2023/09/20 13:42:20 by cbernaze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graph.h"

t_raycasting	init_data_rayc

int	ft_raycasting(char **map)
{
	t_raycasting	ray;

	ray.posX = 22;
	ray.posY = 12;
	ray.dirX = -1;
	ray.dirY = 0;
	ray.planeX = 0;
	ray.planeY = 0.66;
	// the FOV is 2*atan(0.66/1.0), so 66 degrees
	ray.time = 0;
	ray.oldTime = 0;
	int	x;
	int	xMax;

	x = 0;
	xMax = ft_unstrlen_plus(map);
	while (x < xMax)
	{

		x++;
	}
}
