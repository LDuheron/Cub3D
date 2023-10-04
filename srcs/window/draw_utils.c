/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbernaze <cbernaze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 15:53:03 by cbernaze          #+#    #+#             */
/*   Updated: 2023/10/04 17:58:02 by cbernaze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*Function that draws a pixel at the coordinates x and y,
with the given color.*/

void	img_pix_put(t_img *img, int x, int y, int color)
{
	char	*pixel;

	pixel = img->addr + (y * img->line_len + x * (img->bpp / 8));
	*(int *)pixel = color;
}

void	free_textures(t_graph *data)
{
	if (data->tx_1.ptr)
		mlx_destroy_image(data->mlx_ptr, data->tx_1.ptr);
	if (data->tx_2.ptr)
		mlx_destroy_image(data->mlx_ptr, data->tx_2.ptr);
	if (data->tx_3.ptr)
		mlx_destroy_image(data->mlx_ptr, data->tx_3.ptr);
	if (data->tx_4.ptr)
		mlx_destroy_image(data->mlx_ptr, data->tx_4.ptr);
}

double	ft_abs(double nb)
{
	if (nb < 0)
		nb *= -1;
	return (nb);
}

void	draw_rect(t_graph *data)
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

void	draw_background(t_graph *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < WIN_WIDTH)
	{
		j = 0;
		while (j < WIN_HEIGHT / 2)
		{
			img_pix_put(&data->img, i, j, data->color[1]);
			j++;
		}
		i++;
	}
	i = 0;
	while (i < WIN_WIDTH)
	{
		j = WIN_HEIGHT;
		while (j >= WIN_HEIGHT / 2)
		{
			img_pix_put(&data->img, i, j, data->color[0]);
			j--;
		}
		i++;
	}
}
