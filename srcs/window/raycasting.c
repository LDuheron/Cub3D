/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbernaze <cbernaze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 11:25:16 by cbernaze          #+#    #+#             */
/*   Updated: 2023/09/25 16:34:06 by cbernaze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_raycasting	init_data_rc(t_parsing_data parsing)
{
	t_raycasting	ray;

	ray.pos_x = parsing.pos_p_x;
	ray.pos_y = parsing.pos_p_y;
	ray.dir_x = 1;
	ray.dir_y = 0;
	ray.plane_x = 0;
	ray.plane_y = 0.66;
	// the FOV is 2*atan(0.66/1.0), so 66 degrees
	return (ray);
}

void	nb_steps_n_sideDst(t_raycasting *ray)
{
	if (ray->ray_dir_x < 0)
	{
		ray->step_x = -1;
		ray->side_dist_x = (ray->pos_x - ray->map_x) * ray->delta_dist_x;
	}
	else
	{
		ray->step_x = 1;
		ray->side_dist_x = (ray->map_x + 1.0 - ray->pos_x) * ray->delta_dist_x;
	}
	if (ray->ray_dir_y < 0)
	{
		ray->step_y = -1;
		ray->side_dist_y = (ray->pos_y - ray->map_y) * ray->delta_dist_y;
	}
	else
	{
		ray->step_y = 1;
		ray->side_dist_y = (ray->map_y + 1.0 - ray->pos_y) * ray->delta_dist_y;
	}
}

void	ray_dda(t_raycasting *ray, char **map)
{
	while (ray->hit == 0)
	{
		//jump to next map square, either in x-direction, or in y-direction
		if (ray->side_dist_x < ray->side_dist_y)
		{
			ray->side_dist_x += ray->delta_dist_x;
			ray->map_x += ray->step_x;
			ray->side = X_SIDE;
		}
		else
		{
			ray->side_dist_y += ray->delta_dist_y;
			ray->map_y += ray->step_y;
			ray->side = Y_SIDE;
		}
		//Check if ray has hit a wall
		if ((map[ray->map_x][ray->map_y]) > 48)
			ray->hit = 1;
	}
}

void	wall_coordinates(t_raycasting *ray)
{
		if (ray->side == X_SIDE)
			ray->perp_wall_dist = (ray->side_dist_x - ray->delta_dist_x);
		else
			ray->perp_wall_dist = (ray->side_dist_y - ray->delta_dist_y);
		//Calculate height of line to draw on screen
		ray->line_height = (int)(WIN_HEIGHT / ray->perp_wall_dist);
		//calculate lowest and highest pixel to fill in current stripe
		ray->draw_start = -ray->line_height / 2 + WIN_HEIGHT / 2;
		if (ray->draw_start < 0)
			ray->draw_start = 0;
		ray->draw_end = ray->line_height / 2 + WIN_HEIGHT / 2;
		if (ray->draw_end >= WIN_HEIGHT)
			ray->draw_end = WIN_HEIGHT - 1;
}

void	draw_wall(t_raycasting ray, t_graph data, int x)
{
	while (ray.draw_start < ray.draw_end)
	{
		if (ray.side == X_SIDE)
			img_pix_put(&data.img, x, ray.draw_start, RED_PIXEL);
		else
			img_pix_put(&data.img, x, ray.draw_start, WHITE_PIXEL);
		ray.draw_start++;
	}
}

int	ft_raycasting(t_graph *data)
{
	int				x;
	t_raycasting	ray;

	x = 0;
	ray = data->ray;
	while (x < WIN_WIDTH)
	{
		//calculate ray position and direction
		ray.camera_x = 2 * x / (double)WIN_WIDTH - 1;
		ray.ray_dir_x = ray.dir_x + ray.plane_x * ray.camera_x;
		ray.ray_dir_y = ray.dir_y + ray.plane_y * ray.camera_x;
		//which box of the map we're in
		ray.map_x = (int)ray.pos_x;
		ray.map_y = (int)ray.pos_y;
		ray.hit = 0;
		//length of ray from one x or y-side to next x or y-side
		if (ray.ray_dir_x == 0)
			ray.delta_dist_x = 1e30;
		else
			ray.delta_dist_x = ft_abs(1 / ray.ray_dir_x);
		if (ray.ray_dir_y == 0)
			ray.delta_dist_y = 1e30;
		else
			ray.delta_dist_y = ft_abs(1 / ray.ray_dir_y);
		//calculate step and initial sideDist
		(nb_steps_n_sideDst(&ray), ray_dda(&ray, data->map),
		wall_coordinates(&ray), draw_wall(ray, *data, x));
		x++;
	}
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.ptr, 0, 0);
	return (SUCCESS);
}

