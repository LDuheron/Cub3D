/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbernaze <cbernaze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 12:13:39 by cbernaze          #+#    #+#             */
/*   Updated: 2023/10/04 14:40:04 by cbernaze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_exit(t_graph *data)
{
	mlx_loop_end(data->mlx_ptr);
	mlx_destroy_image(data->mlx_ptr, data->img.ptr);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_display(data->mlx_ptr);
	free_parsing_data(&data->pars);
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
