/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_window.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbernaze <cbernaze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 11:40:39 by cbernaze          #+#    #+#             */
/*   Updated: 2023/09/14 15:13:58 by cbernaze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

/*Function that sets all the data needed
for the window and the images later.*/

t_data	get_data_win()
{
	t_data	data;

	data.mlx_ptr = mlx_init();
	if (data.mlx_ptr == NULL)
		return (data);
	data.win_ptr = mlx_new_window(data.mlx_ptr, 1080, 720, "Lobby Boys");
	if (data.win_ptr == NULL)
		return (mlx_destroy_display(data.mlx_ptr), free(data.mlx_ptr), data);
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

int	create_window()
{
	t_data	data;

	data = get_data_win();
	mlx_loop_hook(data.mlx_ptr, &handle_no_event, &data);
	mlx_hook(data.win_ptr, DestroyNotify, 0, &close_win_mouse, &data);
	mlx_hook(data.win_ptr, KeyPress, KeyPressMask, &close_win_key, &data);
	mlx_loop(data.mlx_ptr);
	return (0);
}

int	main()
{
	int		map[8][8] = {{1, 1, 1, 1, 1, 1, 1, 1},
						{1, 0, 0, 0, 0, 0, 0, 1},
						{1, 0, 0, 0, 0, 0, 0, 1},
						{1, 0, 0, 0, 0, 0, 0, 1},
						{1, 0, 0, 0, 0, 0, 0, 1},
						{1, 0, 0, 0, 0, 0, 0, 1},
						{1, 0, 0, 0, 0, 0, 0, 1},
						{1, 1, 1, 1, 1, 1, 1, 1}};
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	int		floor[3] = {220, 100, 0};
	int		cieling[3] = {225, 30, 0};

	create_window();
	return (0);
}