/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbernaze <cbernaze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 14:47:47 by cbernaze          #+#    #+#             */
/*   Updated: 2023/10/05 16:45:50 by cbernaze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_data_rc2(t_parsing_data parsing, t_raycasting *ray)
{
	if (parsing.pos_type == 'E')
	{
		ray->dir_x = 0;
		ray->dir_y = 1;
		ray->plane_x = 0.66;
		ray->plane_y = 0;
	}
	if (parsing.pos_type == 'W')
	{
		ray->dir_x = 0;
		ray->dir_y = -1;
		ray->plane_x = -0.66;
		ray->plane_y = 0;
	}
}

t_raycasting	init_data_rc(t_parsing_data parsing)
{
	t_raycasting	ray;

	ray.pos_x = parsing.pos_p_x + 0.5;
	ray.pos_y = parsing.pos_p_y + 0.5;
	if (parsing.pos_type == 'N')
	{
		ray.dir_x = -1;
		ray.dir_y = 0;
		ray.plane_x = 0;
		ray.plane_y = 0.66;
	}
	if (parsing.pos_type == 'S')
	{
		ray.dir_x = 1;
		ray.dir_y = 0;
		ray.plane_x = 0;
		ray.plane_y = -0.66;
	}
	init_data_rc2(parsing, &ray);
	return (ray);
}

void	init_tx2(t_graph data, t_img *tex)
{
	if (data.ray.side == X_SIDE)
	{
		if (data.ray.ray_dir_x > 0.f)
			*tex = data.tx_1;
		else
			*tex = data.tx_2;
	}
	else
	{
		if (data.ray.ray_dir_y > 0.f)
			*tex = data.tx_3;
		else
			*tex = data.tx_4;
	}
}

void	init_tx(t_texture *tx, t_graph data, t_img *tex)
{
	init_tx2(data, tex);
	if (data.ray.side == X_SIDE)
		tx->wall_x = data.ray.pos_y + data.ray.perp_wall_dist
			* data.ray.ray_dir_y;
	else
		tx->wall_x = data.ray.pos_x + data.ray.perp_wall_dist
			* data.ray.ray_dir_x;
	tx->wall_x -= floor(tx->wall_x);
	if ((data.ray.side == X_SIDE && data.ray.ray_dir_x < 0)
		|| (data.ray.side == Y_SIDE && data.ray.ray_dir_y < 0))
		tx->wall_x = 1.0f - tx->wall_x;
	tx->tex_x = (int)(tx->wall_x * tex->width);
	tx->step = 1.0 * tex->height / data.ray.line_height;
	tx->tex_pos = (data.ray.draw_start - WIN_HEIGHT / 2
			+ data.ray.line_height / 2) * tx->step;
}
