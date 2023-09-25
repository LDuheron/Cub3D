/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbernaze <cbernaze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 12:13:39 by cbernaze          #+#    #+#             */
/*   Updated: 2023/09/25 16:13:13 by cbernaze         ###   ########.fr       */
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
		// if (data->map[(int)(data->ray.posX + data->ray.dirX * MOVE_SPEED)][(int)data->ray.posY] == 0)
			data->ray.posX += data->ray.dirX * MOVE_SPEED;
		// if (data->map[(int)data->ray.posX][(int)(data->ray.posY + data->ray.dirY * MOVE_SPEED)] == 0)
			data->ray.posY += data->ray.dirY * MOVE_SPEED;
	}
	if (keysym == XK_s || keysym == XK_Down)
	{
		// if (data->map[(int)(data->ray.posX - data->ray.dirX * MOVE_SPEED)][(int)data->ray.posY] == 0)
			data->ray.posX -= data->ray.dirX * MOVE_SPEED;
		// if (data->map[(int)data->ray.posX][(int)(data->ray.posY - data->ray.dirY * MOVE_SPEED)] == 0)
			data->ray.posY -= data->ray.dirY * MOVE_SPEED;
	}
	if (keysym == XK_a || keysym == XK_Left)
	{
		old_dir_x = data->ray.dirX;
		data->ray.dirX = data->ray.dirX * cos(-ROT_SPEED) - data->ray.dirY * sin(-ROT_SPEED);
		data->ray.dirY = old_dir_x * sin(-ROT_SPEED) + data->ray.dirY * cos(-ROT_SPEED);
		old_plane_x = data->ray.planeX;
		data->ray.planeX = data->ray.planeX * cos(-ROT_SPEED) - data->ray.planeY * sin(-ROT_SPEED);
		data->ray.planeY = old_plane_x * sin(-ROT_SPEED) + data->ray.planeY * cos(-ROT_SPEED);
	}
	if (keysym == XK_d || keysym == XK_Right)
	{
		old_dir_x = data->ray.dirX;
		data->ray.dirX = data->ray.dirX * cos(ROT_SPEED) - data->ray.dirY * sin(ROT_SPEED);
		data->ray.dirY = old_dir_x * sin(ROT_SPEED) + data->ray.dirY * cos(ROT_SPEED);
		old_plane_x = data->ray.planeX;
		data->ray.planeX = data->ray.planeX * cos(ROT_SPEED) - data->ray.planeY * sin(ROT_SPEED);
		data->ray.planeY = old_plane_x * sin(ROT_SPEED) + data->ray.planeY * cos(ROT_SPEED);
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