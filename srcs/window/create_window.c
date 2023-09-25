/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_window.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbernaze <cbernaze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 11:40:39 by cbernaze          #+#    #+#             */
/*   Updated: 2023/09/25 12:41:29 by cbernaze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*Function that sets all the data needed
for the window and the images later.*/

t_graph	get_data_win(unsigned char **map)
{
	t_graph	data;

	data.player.posX = WIN_WIDTH/4;
	data.player.posY = WIN_HEIGHT/2;
	data.map = map;
	data.ray = init_data_rc((char**)map);
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

int	create_window(unsigned char **map)
{
	t_graph	data;

	data = get_data_win(map);
	// draw_map(data);
	ft_raycasting((char **)map, &data);
	mlx_loop_hook(data.mlx_ptr, &handle_no_event, &data);
	mlx_hook(data.win_ptr, DestroyNotify, 0, &close_win_mouse, &data);
	mlx_hook(data.win_ptr, KeyPress, KeyPressMask, &close_win_key, &data);
	mlx_loop(data.mlx_ptr);
	return (0);
}

// int	main(void)
// {
// 	// unsigned char	*map_1 = (unsigned char*)"   1    ";
// 	// unsigned char	*map_2 = (unsigned char*)"  101    ";
// 	// unsigned char	*map_3 = (unsigned char*)"  101    ";
// 	// unsigned char	*map_4 = (unsigned char*)"11101111";
// 	// unsigned char	*map_5 = (unsigned char*)"10000001";
// 	// unsigned char	*map_6 = (unsigned char*)"10000001";
// 	// unsigned char	*map_7 = (unsigned char*)"1001100111111";
// 	// unsigned char	*map_8 = (unsigned char*)"10000000000001";
// 	// unsigned char	*map_9 = (unsigned char*)"1000000111111";
// 	// unsigned char	*map_10 = (unsigned char*)"10000001";
// 	// unsigned char	*map_11 = (unsigned char*)"11111111";

// 	unsigned char	*map_1 = (unsigned char*)"111111111111111111111111";
// 	unsigned char	*map_2 = (unsigned char*)"100010000000000000000001";
// 	unsigned char	*map_3 = (unsigned char*)"100000100000000000000001";
// 	unsigned char	*map_4 = (unsigned char*)"100000000100000000000001";
// 	unsigned char	*map_5 = (unsigned char*)"100000000100000000000001";
// 	unsigned char	*map_6 = (unsigned char*)"100000000100000000000001";
// 	unsigned char	*map_7 = (unsigned char*)"100010000100000000000001";
// 	unsigned char	*map_8 = (unsigned char*)"100000000000000000000001";
// 	unsigned char	*map_9 = (unsigned char*)"100000000000000000000001";
// 	unsigned char	*map_10 = (unsigned char*)"100000000000000000000001";
// 	unsigned char	*map_11 = (unsigned char*)"111111111111111111111111";

// 	unsigned char	*map[12];
// 	map[0] = map_1;
// 	map[1] = map_2;
// 	map[2] = map_3;
// 	map[3] = map_4;
// 	map[4] = map_5;
// 	map[5] = map_6;
// 	map[6] = map_7;
// 	map[7] = map_8;
// 	map[8] = map_9;
// 	map[9] = map_10;
// 	map[10] = map_11;
// 	map[11] = (unsigned char*)NULL;

// 	for (int i = 0; i < ft_unstrlen_plus(map) ; i++)
// 		printf("%s\n", map[i]);
// 	// printf("\n");
// 	// printf("%d\n", ft_unstrlen_plus(map));
// 	// printf("\n");
// 	// for (int i = 0; i < ft_unstrlen_plus(map) ; i++)
// 	// {
// 	// 	for (int j = 0; j < ft_unstrlen(map[i]) ; j++)
// 	// 		printf("%d;", map[i][j]);
// 	// 	printf("\n");
// 	// }
// 	// char	*no;
// 	// char	*so;
// 	// char	*we;
// 	// char	*ea;
// 	// int		floor[3] = {220, 100, 0};
// 	// int		cieling[3] = {225, 30, 0};

// 	create_window(map);
// 	return (0);
// }
