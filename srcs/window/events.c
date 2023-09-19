/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbernaze <cbernaze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 12:13:39 by cbernaze          #+#    #+#             */
/*   Updated: 2023/09/19 14:18:50 by cbernaze         ###   ########.fr       */
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
	// printf("x = %f, y = %f\n", data->player.posX, data->player.posY);
	if (keysym == XK_Escape)
		ft_exit(data);
	if (keysym == XK_w || keysym == XK_Up)
		data->player.posY -= 8;
	if (keysym == XK_s || keysym == XK_Down)
		data->player.posY += 8;
	if (keysym == XK_a || keysym == XK_Left)
		data->player.posX -= 8;
	if (keysym == XK_d || keysym == XK_Right)
		data->player.posX += 8;
	// printf("x = %f, y = %f\n", data->player.posX, data->player.posY);
	draw_rect(data);
	draw_map(*data);
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