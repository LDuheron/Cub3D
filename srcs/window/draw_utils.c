/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbernaze <cbernaze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 15:53:03 by cbernaze          #+#    #+#             */
/*   Updated: 2023/10/05 16:51:04 by cbernaze         ###   ########.fr       */
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

int	rgb_to_hex(char **color)
{
	int	r;
	int	g;
	int	b;

	r = ft_atoi(color[0]);
	g = ft_atoi(color[1]);
	b = ft_atoi(color[2]);
	return (r << 16 | g << 8 | b);
}

void	init_colors(t_graph *data)
{
	char	**color_f;
	char	**color_c;
	int		i;

	color_f = ft_split(data->pars.texture[4], ',');
	if (color_f == NULL)
		return ;
	color_c = ft_split(data->pars.texture[5], ',');
	if (color_c == NULL)
	{
		i = -1;
		while (color_f[++i])
			free(color_f[i]);
		free(color_f);
		return ;
	}
	data->color[0] = rgb_to_hex(color_f);
	data->color[1] = rgb_to_hex(color_c);
	i = -1;
	while (color_f[++i])
		free(color_f[i]);
	i = -1;
	while (color_c[++i])
		free(color_c[i]);
	(free(color_f), free(color_c));
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
