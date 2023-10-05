/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduheron <lduheron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 14:39:42 by cbernaze          #+#    #+#             */
/*   Updated: 2023/10/05 15:52:14 by lduheron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*Moves the player left or right.*/

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

/*Moves the player forward or backward.*/

void	front_n_back(t_graph *data)
{
	if (data->utils.key_w == 1 && data->map
		[(int)(data->ray.pos_x + data->ray.dir_x * MOVE_SPEED)]
		[(int)data->ray.pos_y] == 48 && data->map[(int)data->ray.pos_x]
		[(int)(data->ray.pos_y + data->ray.dir_y * MOVE_SPEED)] == 48)
	{
		data->ray.pos_x += data->ray.dir_x * MOVE_SPEED;
		data->ray.pos_y += data->ray.dir_y * MOVE_SPEED;
		draw_background(data);
		ft_raycasting(data);
	}
	if (data->utils.key_s == 1 && data->map
		[(int)(data->ray.pos_x - data->ray.dir_x * MOVE_SPEED)]
		[(int)data->ray.pos_y] == 48 && data->map[(int)data->ray.pos_x]
		[(int)(data->ray.pos_y - data->ray.dir_y * MOVE_SPEED)] == 48)
	{
		data->ray.pos_x -= data->ray.dir_x * MOVE_SPEED;
		data->ray.pos_y -= data->ray.dir_y * MOVE_SPEED;
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


int	ft_anim(t_graph *data)
{
	static int	i;

	while (i < 30000)
	{
		if (i < 15000)
		{
			data->tx_2.ptr = mlx_xpm_file_to_image(data->mlx_ptr,
				"./image.pink_moulure_telecabine_snow_1_128.xpm", &data->tx_2.width, &data->tx_2.height);
		}
		else 
		{
			data->tx_2.ptr = mlx_xpm_file_to_image(data->mlx_ptr,
			"./image.pink_moulure_telecabine_snow_2_128.xpm", &data->tx_2.width, &data->tx_2.height);
		}
		i++;
	}
	return (0);
}



/*Function that changes the values of datas to moves or rotate
the player, it handles the rotation to left.*/

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
	ft_anim(data); ///// BONUS
	return (0);
}


