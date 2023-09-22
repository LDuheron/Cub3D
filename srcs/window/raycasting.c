/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbernaze <cbernaze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 11:25:16 by cbernaze          #+#    #+#             */
/*   Updated: 2023/09/22 15:07:01 by cbernaze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graph.h"

t_raycasting	init_data_rc(char **map)
{
	t_raycasting	ray;

	ray.xMax = ft_unstrlen_plus((unsigned char**)map);
	ray.posX = ray.xMax/2;
	ray.posY = ray.xMax/2;
	ray.dirX = -1;
	ray.dirY = 0;
	ray.planeX = 0;
	ray.planeY = 0.66;
	// the FOV is 2*atan(0.66/1.0), so 66 degrees
	ray.time = 0;
	ray.oldTime = 0;
	return (ray);
}

void	nb_steps_n_sideDst(t_raycasting *ray)
{
	if (ray->rayDirX < 0)
	{
		ray->stepX = -1;
		ray->sideDistX = (ray->posX - ray->mapX) * ray->deltaDistX;
	}
	else
	{
		ray->stepX = 1;
		ray->sideDistX = (ray->mapX + 1.0 - ray->posX) * ray->deltaDistX;
	}
	if (ray->rayDirY < 0)
	{
		ray->stepY = -1;
		ray->sideDistY = (ray->posY - ray->mapY) * ray->deltaDistY;
	}
	else
	{
		ray->stepY = 1;
		ray->sideDistY = (ray->mapY + 1.0 - ray->posY) * ray->deltaDistY;
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
		printf("wall = %c\n", map[ray->mapX][ray->mapY]);
		if ((map[ray->mapX][ray->mapY]) > 48)
			ray->hit = 1;
	}
}

void	wall_coordinates(t_raycasting *ray)
{
		if (ray->side == X_SIDE)
			ray->perpWallDist = (ray->sideDistX - ray->deltaDistX);
		else
			ray->perpWallDist = (ray->sideDistY - ray->deltaDistY);
		//Calculate height of line to draw on screen
		ray->lineHeight = (int)(WIN_HEIGHT / ray->perpWallDist);
		//calculate lowest and highest pixel to fill in current stripe
		ray->drawStart = (-ray->lineHeight / 2) + (WIN_HEIGHT / 2);
		if (ray->drawStart < 0)
			ray->drawStart = 0;
		ray->drawEnd = (ray->lineHeight / 2) + (WIN_HEIGHT / 2);
		if (ray->drawEnd >= WIN_HEIGHT)
			ray->drawEnd = WIN_HEIGHT - 1;
}

void	draw_wall(t_raycasting ray, t_data data, int x)
{
	while (ray.drawStart < ray.drawEnd)
	{
		if (ray.side == X_SIDE)
			img_pix_put(&data.img, x, ray.drawStart, RED_PIXEL);
		else
			img_pix_put(&data.img, x, ray.drawStart, BLUE_PIXEL);
		ray.drawStart++;
	}
}

int	ft_raycasting(char **map, t_data *data)
{
	t_raycasting	ray;
	int	x;

	x = 0;
	ray = init_data_rc(map);
	printf("x = %d, xmax = %d\n", x, ray.xMax);
	while (x < ray.xMax)
	{
		//calculate ray position and direction
		ray.cameraX = 2 * x / (double)ray.xMax - 1;
		ray.rayDirX = ray.dirX + ray.planeX * ray.cameraX;
		ray.rayDirY = ray.dirY + ray.planeY * ray.cameraX;
		//which box of the map we're in
		ray.mapX = (int)ray.posX;
		ray.mapY = (int)ray.posY;
		ray.hit = 0;
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
		(nb_steps_n_sideDst(&ray), ray_dda(&ray, map),
			wall_coordinates(&ray), draw_wall(ray, *data, x));
		printf("start = %d, end = %d\n", ray.drawStart, ray.drawEnd);
		x++;
	}
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.ptr, 0, 0);
	return (SUCCESS);
}

