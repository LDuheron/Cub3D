/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbernaze <cbernaze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 11:25:16 by cbernaze          #+#    #+#             */
/*   Updated: 2023/10/02 11:04:27 by cbernaze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_raycasting	init_data_rc(t_parsing_data parsing)
{
	t_raycasting	ray;

	ray.pos_x = parsing.pos_p_x + 0.1;
	ray.pos_y = parsing.pos_p_y + 0.1;
	if (parsing.pos_type == 78)
	{
		ray.dir_x = -1;
		ray.dir_y = 0;
		ray.plane_x = 0;
		ray.plane_y = 0.66;
	}
	if (parsing.pos_type == 83)
	{
		ray.dir_x = 1;
		ray.dir_y = 0;
		ray.plane_x = 0;
		ray.plane_y = -0.66;
	}
	if (parsing.pos_type == 69)
	{
		ray.dir_x = 0;
		ray.dir_y = 1;
		ray.plane_x = 0.66;
		ray.plane_y = 0;
	}
	if (parsing.pos_type == 87)
	{
		ray.dir_x = 0;
		ray.dir_y = -1;
		ray.plane_x = -0.66;
		ray.plane_y = 0;
	}
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
		if (ray->draw_end >= WIN_HEIGHT)
			ray->draw_end = WIN_HEIGHT - 1;
}

void	draw_wall(t_raycasting ray, t_graph data, int x)
{
	// void	*img;
	// int		color;
	// int		img_width;
	// int		img_height;
	// int		bpp;
	// int		line_len;
	// int		endian;

	// img = mlx_xpm_file_to_image(data.mlx_ptr, "/mnt/nfs/homes/cbernaze/Projets_42/Cercle_4/Cub3D/image/carpet.xpm", &img_width, &img_height);
	// mlx_get_data_addr(img, &bpp, &line_len, &endian);
	// color = (1 * line_len + 1 * (bpp / 8));
	// // printf("color = %d\n", color);
	// color = mlx_get_color_value(data.mlx_ptr, color);
	// printf("color = %d\n", color);
	while (ray.draw_start < ray.draw_end)
	{
		if (ray.side == X_SIDE)
			img_pix_put(&data.img, x, ray.draw_start, WHITE_PIXEL);
		else
			img_pix_put(&data.img, x, ray.draw_start, WHITE_PIXEL+40);
		ray.draw_start++;
	}
}

int	ft_raycasting(t_graph *data)
{
	int	x;

	x = -1;
	while (x++ < WIN_WIDTH)
	{
		data->ray.camera_x = 2 * x / (double)WIN_WIDTH - 1;
		data->ray.ray_dir_x = data->ray.dir_x + data->ray.plane_x * data->ray.camera_x;
		data->ray.ray_dir_y = data->ray.dir_y + data->ray.plane_y * data->ray.camera_x;
		data->ray.map_x = (int)data->ray.pos_x;
		data->ray.map_y = (int)data->ray.pos_y;
		data->ray.hit = 0;
		if (data->ray.ray_dir_x == 0)
			data->ray.delta_dist_x = 1e30;
		else
			data->ray.delta_dist_x = ft_abs(1 / data->ray.ray_dir_x);
		if (data->ray.ray_dir_y == 0)
			data->ray.delta_dist_y = 1e30;
		else
			data->ray.delta_dist_y = ft_abs(1 / data->ray.ray_dir_y);
		(nb_steps_n_sideDst(&data->ray), ray_dda(&data->ray, data->map),
		wall_coordinates(&data->ray), draw_wall(data->ray, *data, x));
	}
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.ptr, 0, 0);
	return (SUCCESS);
}
