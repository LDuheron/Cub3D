/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_window.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbernaze <cbernaze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 11:40:39 by cbernaze          #+#    #+#             */
/*   Updated: 2023/10/02 14:21:10 by cbernaze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*Function that sets all the data needed
for the window and the images later.*/

t_graph	get_data_win(t_parsing_data parsing)
{
	t_graph	data;

	data.pars = parsing;
	data.map = parsing.map;
	data.utils.key_a = 0;
	data.utils.key_d = 0;
	data.utils.key_w = 0;
	data.utils.key_s = 0;
	data.utils.key_left = 0;
	data.utils.key_right = 0;
	data.utils.move_speed = 0;
	data.utils.rot_speed = 0;
	data.ray = init_data_rc(parsing);
	data.mlx_ptr = mlx_init();
	if (data.mlx_ptr == NULL)
		return (data);
	data.win_ptr = mlx_new_window(data.mlx_ptr, WIN_WIDTH,
			WIN_HEIGHT, "Lobby Boys");
	if (data.win_ptr == NULL)
		return (mlx_destroy_display(data.mlx_ptr), free(data.mlx_ptr), data);
	data.img.ptr = mlx_new_image(data.mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
	if (data.img.ptr == NULL)
		return (mlx_destroy_window(data.mlx_ptr, data.win_ptr),
			mlx_destroy_display(data.mlx_ptr), free(data.mlx_ptr), data);
	data.img.addr = mlx_get_data_addr(data.img.ptr,
			&data.img.bpp, &data.img.line_len, &data.img.endian);
	return (data);
}

/*Function that draws a pixel at the coordinates x and y,
with the given color.*/

void	img_pix_put(t_img *img, int x, int y, int color)
{
	char	*pixel;

	pixel = img->addr + (y * img->line_len + x * (img->bpp / 8));
	*(int *)pixel = color;
}

/*Function that creates the window.*/

int	create_window(t_parsing_data parsing)
{
	t_graph	data;

	data = get_data_win(parsing);
	draw_background(&data);
	ft_raycasting(&data);
	mlx_loop_hook(data.mlx_ptr, &handle_no_event, &data);
	mlx_loop_hook(data.mlx_ptr, &move_it, &data);
	mlx_hook(data.win_ptr, DestroyNotify, 0, &close_win_mouse, &data);
	mlx_hook(data.win_ptr, KeyPress, KeyPressMask, &key_press, &data);
	mlx_hook(data.win_ptr, KeyRelease, KeyReleaseMask, &key_release, &data);
	mlx_loop(data.mlx_ptr);
	return (0);
}
