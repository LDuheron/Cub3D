/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbernaze <cbernaze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 11:25:16 by cbernaze          #+#    #+#             */
/*   Updated: 2023/10/05 16:44:12 by cbernaze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	nb_steps_n_side_dst(t_raycasting *ray)
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
	ray->line_height = (int)(WIN_HEIGHT / ray->perp_wall_dist);
	ray->draw_start = -ray->line_height / 2 + WIN_HEIGHT / 2;
	if (ray->draw_start < 0)
		ray->draw_start = 0;
	ray->draw_end = ray->line_height / 2 + WIN_HEIGHT / 2;
	if (ray->draw_end > WIN_HEIGHT)
		ray->draw_end = WIN_HEIGHT;
}

void	draw_wall(t_raycasting ray, t_graph data, int x)
{
	t_texture	tx;
	t_img		tex;

	init_tx(&tx, data, &tex);
	while (ray.draw_start < ray.draw_end)
	{
		tx.tex_y = (int)tx.tex_pos & (tex.height - 1);
		tx.tex_pos += tx.step;
		tx.color = tex.addr + (tx.tex_y * tex.line_len + tx.tex_x
				* (tex.bpp / 8));
		img_pix_put(&data.img, x, ray.draw_start, *(int *)tx.color);
		ray.draw_start++;
	}
}

void	ft_raycasting(t_graph *data)
{
	int	x;

	x = -1;
	while (x++ < WIN_WIDTH)
	{
		data->ray.camera_x = 2 * x / (double)WIN_WIDTH - 1;
		data->ray.ray_dir_x = data->ray.dir_x + data->ray.plane_x
			* data->ray.camera_x;
		data->ray.ray_dir_y = data->ray.dir_y + data->ray.plane_y
			* data->ray.camera_x;
		data->ray.map_x = (int)data->ray.pos_x;
		data->ray.map_y = (int)data->ray.pos_y;
		data->ray.hit = 0;
		if (data->ray.ray_dir_x == 0)
			data->ray.delta_dist_x = 1e30;
		else
			data->ray.delta_dist_x = fabs(1.0 / data->ray.ray_dir_x);
		if (data->ray.ray_dir_y == 0)
			data->ray.delta_dist_y = 1e30;
		else
			data->ray.delta_dist_y = fabs(1.0 / data->ray.ray_dir_y);
		(nb_steps_n_side_dst(&data->ray), ray_dda(&data->ray, data->map),
			wall_coordinates(&data->ray), draw_wall(data->ray, *data, x));
	}
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.ptr, 0, 0);
}
