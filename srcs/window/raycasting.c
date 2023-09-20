/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbernaze <cbernaze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 11:25:16 by cbernaze          #+#    #+#             */
/*   Updated: 2023/09/20 18:02:09 by cbernaze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graph.h"

t_raycasting	init_data_rc(char **map)
{
	t_raycasting	ray;

	ray.xMax = ft_unstrlen_plus(map);
	ray.posX = 22;
	ray.posY = 12;
	ray.dirX = -1;
	ray.dirY = 0;
	ray.planeX = 0;
	ray.planeY = 0.66;
	// the FOV is 2*atan(0.66/1.0), so 66 degrees
	ray.time = 0;
	ray.oldTime = 0;
	ray.hit = 0;
}

void	nb_steps_n_sideDst(t_raycasting *ray)
{
	if (ray->rayDirX < 0)
	{
		ray->stepX = -1;
		ray->sideDistX = (ray->posX - (double)ray->mapX) * ray->deltaDistX;
	}
	else
	{
		ray->stepX = 1;
		ray->sideDistX = ((double)ray->mapX + 1 - ray->posX) * ray->deltaDistX;
	}
	if (ray->rayDirY < 0)
	{
		ray->stepY = -1;
		ray->sideDistY = (ray->posY - (double)ray->mapY) * ray->deltaDistY;
	}
	else
	{
		ray->stepY = 1;
		ray->sideDistY = ((double)ray->mapY + 1 - ray->posY) * ray->deltaDistY;
	}
}

void	ray_dda(t_raycasting *ray, char **map)
{
	while (ray->hit == 0)
	{
		//jump to next map square, either in x-direction, or in y-direction
		if (ray->sideDistX < ray->sideDistY)
		{
			ray->sideDistX += ray->deltaDistX;
			ray->mapX += ray->stepX;
			ray->side = X_SIDE;
		}
		else
		{
			ray->sideDistY += ray->deltaDistY;
			ray->mapY += ray->stepY;
			ray->side = Y_SIDE;
		}
		//Check if ray has hit a wall
		if (map[ray->mapX][ray->mapY] > 0)
			ray->hit = 1;
	}
}

int	ft_raycasting(char **map, t_data *data)
{
	t_raycasting	ray;
	int	x;

	x = 0;
	while (x < ray.xMax)
	{
		//calculate ray position and direction
		ray.cameraX = 2 * x / (double)ray.xMax - 1;
		ray.rayDirX = ray.dirX + ray.planeX * ray.cameraX;
		ray.rayDirY = ray.dirY + ray.planeY * ray.cameraX;
		//which box of the map we're in
		ray.mapX = (int)ray.posX;
		ray.mapY = (int)ray.posY;
		//length of ray from one x or y-side to next x or y-side
		if (ray.rayDirX == 0)
			ray.deltaDistX = 1e30;
		else
			ray.deltaDistX = ft_abs(1 / ray.rayDirX);
		if (ray.rayDirY == 0)
			ray.deltaDistY = 1e30;
		else
			ray.deltaDistY = ft_abs(1 / ray.rayDirY);
		//calculate step and initial sideDist
		nb_steps_n_sideDst(&ray);
		ray_dda(&ray, map);
		if (ray.side == X_SIDE)
			ray.perpWallDist = (ray.sideDistX - ray.deltaDistX);
		else
			ray.perpWallDist = (ray.sideDistY - ray.deltaDistY);
		//Calculate height of line to draw on screen
		ray.lineHeight = (int)(WIN_HEIGHT / ray.perpWallDist);
		//calculate lowest and highest pixel to fill in current stripe
		ray.drawStart = -ray.lineHeight / 2 + WIN_HEIGHT / 2;
		if (ray.drawStart < 0)
			ray.drawStart = 0;
		ray.drawEnd = ray.lineHeight / 2 + WIN_HEIGHT / 2;
		if (ray.drawEnd >= WIN_HEIGHT)
			ray.drawEnd = WIN_HEIGHT - 1;
		while (ray.drawStart < ray.drawEnd)
		{
			img_pix_put(&data->img, x, ray.drawStart, RED_PIXEL);
			ray.drawStart++;
		}
		x++;
	}
}

