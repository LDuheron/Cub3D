/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbernaze <cbernaze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 15:53:03 by cbernaze          #+#    #+#             */
/*   Updated: 2023/09/18 17:30:03 by cbernaze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

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

int	draw_map(t_data data)
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
	mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, data.img.ptr, 0, 0);
	return (SUCCESS);
}