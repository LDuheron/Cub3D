/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbernaze <cbernaze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 12:13:39 by cbernaze          #+#    #+#             */
/*   Updated: 2023/09/24 19:19:55 by cbernaze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graph.h"

void	ft_exit(t_data *data)
{
	mlx_loop_end(data->mlx_ptr);
	mlx_destroy_image(data->mlx_ptr, data->img.ptr);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	exit(1);
}

int	close_win_key(int keysym, t_data *data)
{
	double	oldDirX;
	double	oldPlaneX;

	// printf("x = %f, y = %f\n", data->player.posX, data->player.posY);
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
	if (keysym == XK_d || keysym == XK_Right)
	{
		oldDirX = data->ray.dirX;
		data->ray.dirX = data->ray.dirX * cos(-ROT_SPEED) - data->ray.dirY * sin(-ROT_SPEED);
		data->ray.dirY = oldDirX * sin(-ROT_SPEED) + data->ray.dirY * cos(-ROT_SPEED);
		oldPlaneX = data->ray.planeX;
		data->ray.planeX = data->ray.planeX * cos(-ROT_SPEED) - data->ray.planeY * sin(-ROT_SPEED);
		data->ray.planeY = oldPlaneX * sin(-ROT_SPEED) + data->ray.planeY * cos(-ROT_SPEED);
	}
	if (keysym == XK_a || keysym == XK_Left)
	{
		oldDirX = data->ray.dirX;
		data->ray.dirX = data->ray.dirX * cos(ROT_SPEED) - data->ray.dirY * sin(ROT_SPEED);
		data->ray.dirY = oldDirX * sin(ROT_SPEED) + data->ray.dirY * cos(ROT_SPEED);
		oldPlaneX = data->ray.planeX;
		data->ray.planeX = data->ray.planeX * cos(ROT_SPEED) - data->ray.planeY * sin(ROT_SPEED);
		data->ray.planeY = oldPlaneX * sin(ROT_SPEED) + data->ray.planeY * cos(ROT_SPEED);
	}
	// printf("x = %f, y = %f\n", data->player.posX, data->player.posY);
	draw_rect(data);
	// draw_map(*data);
	ft_raycasting((char**)data->map, data);
	return (0);
}

int	close_win_mouse(t_data *data)
{
	ft_exit(data);
	return (0);
}

int	handle_no_event(void *data)
{
	(void)data;
	return (0);
}