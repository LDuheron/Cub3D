/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbernaze <cbernaze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 12:13:39 by cbernaze          #+#    #+#             */
/*   Updated: 2023/09/29 16:51:45 by cbernaze         ###   ########.fr       */
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

int	key_release(int keysym, t_graph *data)
{
	if (keysym == XK_w || keysym == XK_Up)
		data->utils.key_w = 0;
	if (keysym == XK_s || keysym == XK_Down)
		data->utils.key_s = 0;
	if (keysym == XK_d)
		data->utils.key_d = 0;
	if (keysym == XK_a)
		data->utils.key_a = 0;
	if (keysym == XK_Right)
		data->utils.key_right = 0;
	if (keysym == XK_Left)
		data->utils.key_left = 0;
	return (0);
}

int	key_press(int keysym, t_graph *data)
{
	if (keysym == XK_Escape)
		ft_exit(data);
	if (keysym == XK_w || keysym == XK_Up)
		data->utils.key_w = 1;
	if (keysym == XK_s || keysym == XK_Down)
		data->utils.key_s = 1;
	if (keysym == XK_d)
		data->utils.key_d = 1;
	if (keysym == XK_a)
		data->utils.key_a = 1;
	if (keysym == XK_Right)
		data->utils.key_right = 1;
	if (keysym == XK_Left)
		data->utils.key_left = 1;
	return (0);
}

void	lateral_moves(t_graph *data)
{
	if (data->utils.key_d == 1 && data->map
		[(int)(data->ray.pos_x + data->ray.plane_x * MOVE_SPEED)]
		[(int)(data->ray.pos_y + data->ray.plane_y * MOVE_SPEED)] == 48)
	{
		data->ray.pos_x += data->ray.plane_x * MOVE_SPEED;
		data->ray.pos_y += data->ray.plane_y * MOVE_SPEED;
		draw_background(data);
		ft_raycasting(data);
	}
	if (data->utils.key_a == 1 && data->map
		[(int)(data->ray.pos_x - data->ray.plane_x * MOVE_SPEED)]
		[(int)(data->ray.pos_y - data->ray.plane_y * MOVE_SPEED)] == 48)
	{
		data->ray.pos_x -= data->ray.plane_x * MOVE_SPEED;
		data->ray.pos_y -= data->ray.plane_y * MOVE_SPEED;
		draw_background(data);
		ft_raycasting(data);
	}
}

void	front_n_back(t_graph *data)
{
	if (data->utils.key_w == 1 && data->map
		[(int)(data->ray.pos_x + data->ray.dir_x * MOVE_SPEED)]
		[(int)(data->ray.pos_y + data->ray.dir_y * MOVE_SPEED)] == 48)
	{
		data->ray.pos_x += data->ray.dir_x * MOVE_SPEED;
		data->ray.pos_y += data->ray.dir_y * MOVE_SPEED;
		draw_background(data);
		ft_raycasting(data);
	}
	if (data->utils.key_s == 1 && data->map
		[(int)(data->ray.pos_x - data->ray.dir_x * MOVE_SPEED)]
		[(int)(data->ray.pos_y - data->ray.dir_y * MOVE_SPEED)] == 48)
	{
		data->ray.pos_x -= data->ray.dir_x * MOVE_SPEED;
		data->ray.pos_y -= data->ray.dir_y * MOVE_SPEED;
		draw_background(data);
		ft_raycasting(data);
	}
}

void	rotations_right(double old_dir_x, double old_plane_x, t_graph *data)
{
	if (data->utils.key_right == 1)
	{
		old_dir_x = data->ray.dir_x;
		data->ray.dir_x = data->ray.dir_x * cos(-ROT_SPEED)
			- data->ray.dir_y * sin(-ROT_SPEED);
		data->ray.dir_y = old_dir_x * sin(-ROT_SPEED)
			+ data->ray.dir_y * cos(-ROT_SPEED);
		old_plane_x = data->ray.plane_x;
		data->ray.plane_x = data->ray.plane_x * cos(-ROT_SPEED)
			- data->ray.plane_y * sin(-ROT_SPEED);
		data->ray.plane_y = old_plane_x * sin(-ROT_SPEED)
			+ data->ray.plane_y * cos(-ROT_SPEED);
	}
}

int	move_it(t_graph *data)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = 0.0;
	old_plane_x = 0.0;
	front_n_back(data);
	lateral_moves(data);
	rotations_right(old_dir_x, old_plane_x, data);
	if (data->utils.key_left == 1)
	{
		old_dir_x = data->ray.dir_x;
		data->ray.dir_x = data->ray.dir_x * cos(ROT_SPEED)
			- data->ray.dir_y * sin(ROT_SPEED);
		data->ray.dir_y = old_dir_x * sin(ROT_SPEED)
			+ data->ray.dir_y * cos(ROT_SPEED);
		old_plane_x = data->ray.plane_x;
		data->ray.plane_x = data->ray.plane_x * cos(ROT_SPEED)
			- data->ray.plane_y * sin(ROT_SPEED);
		data->ray.plane_y = old_plane_x * sin(ROT_SPEED)
			+ data->ray.plane_y * cos(ROT_SPEED);
	}
	draw_background(data);
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
