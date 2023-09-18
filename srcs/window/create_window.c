/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_window.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbernaze <cbernaze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 11:40:39 by cbernaze          #+#    #+#             */
/*   Updated: 2023/09/18 18:05:31 by cbernaze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

/*Function that sets all the data needed
for the window and the images later.*/

t_data	get_data_win()
{
	t_data	data;

	data.player.posX = WIN_WIDTH/2;
	data.player.posY = WIN_HEIGHT/2;
	data.mlx_ptr = mlx_init();
	if (data.mlx_ptr == NULL)
		return (data);
	data.win_ptr = mlx_new_window(data.mlx_ptr, WIN_WIDTH, WIN_HEIGHT, "Lobby Boys");
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
			// printf("pixel = %s, x = %d, y = %d\n", pixel, x, y);
	*(int *)pixel = color;
}

/*Function that creates the window.*/

int	create_window()
{
	t_data	data;

	data = get_data_win();
	draw_map(data);
	mlx_loop_hook(data.mlx_ptr, &handle_no_event, &data);
	mlx_hook(data.win_ptr, DestroyNotify, 0, &close_win_mouse, &data);
	mlx_hook(data.win_ptr, KeyPress, KeyPressMask, &close_win_key, &data);
	mlx_loop(data.mlx_ptr);
	return (0);
}

int	main(void)
{
	char	*map_1 = "   1    ";
	char	*map_2 = "  101    ";
	char	*map_3 = "  101    ";
	char	*map_4 = "11101111";
	char	*map_5 = "10000001";
	char	*map_6 = "10000001";
	char	*map_7 = "1000000111111";
	char	*map_8 = "10000000000001";
	char	*map_9 = "1000000111111";
	char	*map_10 = "10000001";
	char	*map_11 = "11111111";

	char	*map[11];
	map[0] = map_1;
	map[1] = map_2;
	map[2] = map_3;
	map[3] = map_4;
	map[4] = map_5;
	map[5] = map_6;
	map[6] = map_7;
	map[7] = map_8;
	map[8] = map_9;
	map[9] = map_10;
	map[10] = map_11;

	for (int i = 0; i < 11 ; i++)
		printf("%s\n", map[i]);
	// char	*no;
	// char	*so;
	// char	*we;
	// char	*ea;
	// int		floor[3] = {220, 100, 0};
	// int		cieling[3] = {225, 30, 0};

	create_window();
	return (0);
}
