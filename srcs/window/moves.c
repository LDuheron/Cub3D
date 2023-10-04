/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbernaze <cbernaze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 14:39:42 by cbernaze          #+#    #+#             */
/*   Updated: 2023/10/04 16:42:46 by cbernaze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*Moves the player left or right.*/

void	set_moves(t_graph *data, double *vel_x, double *vel_y)
{
	if (data->utils.key_w)
	{
		*vel_x += data->ray.dir_x * MOVE_SPEED;
		*vel_y += data->ray.dir_y * MOVE_SPEED;
	}
	if (data->utils.key_s)
	{
		*vel_x += -data->ray.dir_x * MOVE_SPEED;
		*vel_y += -data->ray.dir_y * MOVE_SPEED;
	}
	if (data->utils.key_a)
	{
		*vel_x += -data->ray.plane_x * MOVE_SPEED;
		*vel_y += -data->ray.plane_y * MOVE_SPEED;
	}
	if (data->utils.key_d)
	{
		*vel_x += data->ray.plane_x * MOVE_SPEED;
		*vel_y += data->ray.plane_y * MOVE_SPEED;
	}
}

/*Moves the player forward or backward.*/

void	moves(t_graph *data)
{
	double	vel_x;
	double	vel_y;

	vel_x = 0.0;
	vel_y = 0.0;
	set_moves(data, &vel_x, &vel_y);
	if (data->map
		[(int)(data->ray.pos_x + vel_x)]
		[(int)data->ray.pos_y] == '0')
	{
		data->ray.pos_x += vel_x;
		draw_background(data);
		ft_raycasting(data);
	}
	if (data->map[(int)data->ray.pos_x]
		[(int)(data->ray.pos_y + vel_y)] == '0')
	{
		data->ray.pos_y += vel_y;
		draw_background(data);
		ft_raycasting(data);
	}
}

/*Rotates the player to the right.*/

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

/*Function that changes the values of datas to moves or rotate
the player, it handles the rotation to left.*/

int	move_it(t_graph *data)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = 0.0;
	old_plane_x = 0.0;
	moves(data);
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
