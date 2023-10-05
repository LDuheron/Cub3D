/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_window.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbernaze <cbernaze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 11:40:39 by cbernaze          #+#    #+#             */
/*   Updated: 2023/10/04 15:09:11 by cbernaze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*Initializes the keys value and the speed
for movements and rotation of the player.*/

void	init_data_utils(t_graph *data)
{
	data->utils.key_a = 0;
	data->utils.key_d = 0;
	data->utils.key_w = 0;
	data->utils.key_s = 0;
	data->utils.key_left = 0;
	data->utils.key_right = 0;
	data->utils.move_speed = 0;
	data->utils.rot_speed = 0;
}

/*Initializes datas in the t_img structures for all the textures.*/

int	init_texture_addrs(t_graph *data)
{
	data->tx_1.addr = mlx_get_data_addr(data->tx_1.ptr, &data->tx_1.bpp,
			&data->tx_1.line_len, &data->tx_1.endian);
	if (data->tx_1.addr == NULL)
		return (ERROR);
	data->tx_2.addr = mlx_get_data_addr(data->tx_2.ptr, &data->tx_2.bpp,
			&data->tx_2.line_len, &data->tx_2.endian);
	if (data->tx_2.addr == NULL)
		return (ERROR);
	data->tx_3.addr = mlx_get_data_addr(data->tx_3.ptr, &data->tx_3.bpp,
			&data->tx_3.line_len, &data->tx_3.endian);
	if (data->tx_3.addr == NULL)
		return (ERROR);
	data->tx_4.addr = mlx_get_data_addr(data->tx_4.ptr, &data->tx_4.bpp,
			&data->tx_4.line_len, &data->tx_4.endian);
	if (data->tx_4.addr == NULL)
		return (ERROR);
	return (SUCCESS);
}

/*Initializes the t_img structures for all the textures.*/

int	init_textures(t_graph *data)
{
	data->tx_1.ptr = mlx_xpm_file_to_image(data->mlx_ptr,
			data->pars.texture[0], &data->tx_1.width, &data->tx_1.height);
	if (data->tx_1.ptr == NULL)
		return (ERROR);
	data->tx_2.ptr = mlx_xpm_file_to_image(data->mlx_ptr,
			data->pars.texture[1], &data->tx_2.width, &data->tx_2.height);
	if (data->tx_2.ptr == NULL)
		return (free_textures(data), ERROR);
	data->tx_3.ptr = mlx_xpm_file_to_image(data->mlx_ptr,
			data->pars.texture[2], &data->tx_3.width, &data->tx_3.height);
	if (data->tx_3.ptr == NULL)
		return (free_textures(data), ERROR);
	data->tx_4.ptr = mlx_xpm_file_to_image(data->mlx_ptr,
			data->pars.texture[3], &data->tx_4.width, &data->tx_4.height);
	if (data->tx_4.ptr == NULL)
		return (free_textures(data), ERROR);
	if (init_texture_addrs(data) == ERROR)
		return (free_textures(data), ERROR);
	return (SUCCESS);
}

/*Function that sets all the data needed
for the window and the images later.*/

t_graph	get_data_win(t_parsing_data parsing)
{
	t_graph	data;

	data.pars = parsing;
	data.map = parsing.map;
	init_data_utils(&data);
	data.ray = init_data_rc(parsing);
	data.mlx_ptr = mlx_init();
	if (data.mlx_ptr == NULL)
		return (printf("Error: mlx_init failed\n"), data);
	if (init_textures(&data) == ERROR)
		return (mlx_destroy_display(data.mlx_ptr), free(data.mlx_ptr), data);
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

/*Function that creates the window.*/

int	create_window(t_parsing_data parsing)
{
	t_graph	data;

	data = get_data_win(parsing);
	if (!data.mlx_ptr)
		return (ERROR);
	draw_background(&data);
	ft_raycasting(&data);
	mlx_loop_hook(data.mlx_ptr, &handle_no_event, &data);
	mlx_loop_hook(data.mlx_ptr, &move_it, &data);
	mlx_hook(data.win_ptr, DestroyNotify, 0, &close_win_mouse, &data);
	mlx_hook(data.win_ptr, KeyPress, KeyPressMask, &key_press, &data);
	mlx_hook(data.win_ptr, KeyRelease, KeyReleaseMask, &key_release, &data);
	mlx_loop(data.mlx_ptr);
	return (SUCCESS);
}
