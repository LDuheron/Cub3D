/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_olds.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbernaze <cbernaze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 16:38:53 by cbernaze          #+#    #+#             */
/*   Updated: 2023/09/29 16:38:56 by cbernaze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	close_win_key(int keysym, t_graph *data)
{
	double	old_dir_x;
	double	old_plane_x;

	if (keysym == XK_Escape)
		ft_exit(data);
	if (keysym == XK_w || keysym == XK_Up)
	{
		if (data->map[(int)(data->ray.pos_x + data->ray.dir_x * MOVE_SPEED)]
			[(int)(data->ray.pos_y + data->ray.dir_y * MOVE_SPEED)] == 48)
		{
			data->ray.pos_x += data->ray.dir_x * MOVE_SPEED;
			data->ray.pos_y += data->ray.dir_y * MOVE_SPEED;
		}
	}
	if (keysym == XK_s || keysym == XK_Down)
	{
		if (data->map[(int)(data->ray.pos_x - data->ray.dir_x * MOVE_SPEED)]
			[(int)(data->ray.pos_y - data->ray.dir_y * MOVE_SPEED)] == 48)
		{
			data->ray.pos_x -= data->ray.dir_x * MOVE_SPEED;
			data->ray.pos_y -= data->ray.dir_y * MOVE_SPEED;
		}
	}
	if (keysym == XK_d)
	{
		if (data->map[(int)(data->ray.pos_x + data->ray.plane_x * MOVE_SPEED)]
			[(int)(data->ray.pos_y + data->ray.plane_y * MOVE_SPEED)] == 48)
		{
			data->ray.pos_x += data->ray.plane_x * MOVE_SPEED;
			data->ray.pos_y += data->ray.plane_y * MOVE_SPEED;
		}
	}
	if (keysym == XK_a)
	{
		if (data->map[(int)(data->ray.pos_x - data->ray.plane_x * MOVE_SPEED)]
			[(int)(data->ray.pos_y - data->ray.plane_y * MOVE_SPEED)] == 48)
		{
			data->ray.pos_x -= data->ray.plane_x * MOVE_SPEED;
			data->ray.pos_y -= data->ray.plane_y * MOVE_SPEED;
		}
	}
	if (keysym == XK_Right)
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
	if (keysym == XK_Left)
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
