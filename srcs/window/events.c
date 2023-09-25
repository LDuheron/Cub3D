/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbernaze <cbernaze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 12:13:39 by cbernaze          #+#    #+#             */
/*   Updated: 2023/09/25 16:36:42 by cbernaze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_exit(t_graph *data)
{
	mlx_loop_end(data->mlx_ptr);
	mlx_destroy_image(data->mlx_ptr, data->img.ptr);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	exit(1);
}

int	close_win_key(int keysym, t_graph *data)
{
	double	old_dir_x;
	double	old_plane_x;

	if (keysym == XK_Escape)
		ft_exit(data);
	if (keysym == XK_w || keysym == XK_Up)
	{
		// if (data->map[(int)(data->ray.pos_x + data->ray.dir_x * MOVE_SPEED)][(int)data->ray.pos_y] == 0)
			data->ray.pos_x += data->ray.dir_x * MOVE_SPEED;
		// if (data->map[(int)data->ray.pos_x][(int)(data->ray.pos_y + data->ray.dir_y * MOVE_SPEED)] == 0)
			data->ray.pos_y += data->ray.dir_y * MOVE_SPEED;
	}
	if (keysym == XK_s || keysym == XK_Down)
	{
		// if (data->map[(int)(data->ray.pos_x - data->ray.dir_x * MOVE_SPEED)][(int)data->ray.pos_y] == 0)
			data->ray.pos_x -= data->ray.dir_x * MOVE_SPEED;
		// if (data->map[(int)data->ray.pos_x][(int)(data->ray.pos_y - data->ray.dir_y * MOVE_SPEED)] == 0)
			data->ray.pos_y -= data->ray.dir_y * MOVE_SPEED;
	}
	if (keysym == XK_a || keysym == XK_Left)
	{
		old_dir_x = data->ray.dir_x;
		data->ray.dir_x = data->ray.dir_x * cos(-ROT_SPEED) - data->ray.dir_y * sin(-ROT_SPEED);
		data->ray.dir_y = old_dir_x * sin(-ROT_SPEED) + data->ray.dir_y * cos(-ROT_SPEED);
		old_plane_x = data->ray.plane_x;
		data->ray.plane_x = data->ray.plane_x * cos(-ROT_SPEED) - data->ray.plane_y * sin(-ROT_SPEED);
		data->ray.plane_y = old_plane_x * sin(-ROT_SPEED) + data->ray.plane_y * cos(-ROT_SPEED);
	}
	if (keysym == XK_d || keysym == XK_Right)
	{
		old_dir_x = data->ray.dir_x;
		data->ray.dir_x = data->ray.dir_x * cos(ROT_SPEED) - data->ray.dir_y * sin(ROT_SPEED);
		data->ray.dir_y = old_dir_x * sin(ROT_SPEED) + data->ray.dir_y * cos(ROT_SPEED);
		old_plane_x = data->ray.plane_x;
		data->ray.plane_x = data->ray.plane_x * cos(ROT_SPEED) - data->ray.plane_y * sin(ROT_SPEED);
		data->ray.plane_y = old_plane_x * sin(ROT_SPEED) + data->ray.plane_y * cos(ROT_SPEED);
	}
	draw_rect(data);
	ft_raycasting(data);
	return (0);
}

int	close_win_mouse(t_graph *data)
{
	ft_exit(data);
	return (0);
}

int	handle_no_event(void *data)
{
	(void)data;
	return (0);
}