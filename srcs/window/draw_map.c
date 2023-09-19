/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbernaze <cbernaze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 15:53:03 by cbernaze          #+#    #+#             */
/*   Updated: 2023/09/19 16:27:24 by cbernaze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graph.h"

void	draw_rect(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < WIN_HEIGHT)
	{
		j = 0;
		while (j < WIN_WIDTH)
		{
			img_pix_put(&data->img, j, i, BLACK_PIXEL);
			j++;
		}
		i++;
	}
}

int	player_pos(t_data data)
{
	double	sizeX = data.player.posX + 8;
	double	sizeY = data.player.posY + 8;

	while (data.player.posX < sizeX)
	{
		while (data.player.posY < sizeY)
		{
			img_pix_put(&data.img, data.player.posX, data.player.posY, RED_PIXEL);
			data.player.posY += 1;
		}
		data.player.posY -= 8;
		data.player.posX += 1;
	}
	return (SUCCESS);
}

int	draw_map(t_data data)
{
	int	ix;
	int	iy;
	int	color;
	int	size_map;
	int	size_line;

	iy = 0;
	color = 0;
	size_map = ft_unstrlen_plus(data.map);
	while (iy < size_map)
	{
		size_line = ft_unstrlen(data.map[iy]);
		ix = 0;
		while (ix < size_line)
		{
			if (data.map[iy][ix] != 32)
			{
					if (data.map[iy][ix] == 48)
						color = WHITE_PIXEL;
					if (data.map[iy][ix] == 49)
						color = RED_PIXEL;
					ft_dda(&data, ix, iy, color);
			}
			ix++;
		}
		iy++;
	}
	player_pos(data);
	mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, data.img.ptr, 0, 0);
	return (SUCCESS);
}
