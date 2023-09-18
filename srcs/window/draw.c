/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbernaze <cbernaze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 15:40:57 by cbernaze          #+#    #+#             */
/*   Updated: 2023/09/18 15:45:50 by cbernaze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

int	ft_abs(int nb)
{
	if (nb < 0)
		nb *= -1;
	return (nb);
}

void	img_pix_put(t_img *img, int x, int y, int color)
{
	char	*pixel;

	pixel = img->addr + (y * img->line_len + x * (img->bpp / 8));
	*(int *)pixel = color;
}

void	set_line_coordinates(t_data *data, int ix, int iy, int status)
{
	if (status == 1)
	{
		data->line.x1 = ix;
		data->line.x2 = ix;
		data->line.y1 = iy;
		data->line.y2 = iy + 1;
		data->line.z1 = data->map[iy][ix];
		data->line.z2 = data->map[iy + 1][ix];
	}
	if (status == 2)
	{
		data->line.x1 = ix;
		data->line.x2 = ix + 1;
		data->line.y1 = iy;
		data->line.y2 = iy;
		data->line.z1 = data->map[iy][ix];
		data->line.z2 = data->map[iy][ix + 1];
	}
}

void	draw_line(t_data *data)
{
	int	shift_x = 0;
	int	shift_y = 0;

	// set_shift(data, &shift_x, &shift_y);
	if ((shift_x + data->line.x1 < WIN_WIDTH)
		&& (shift_y + data->line.y1 < WIN_HEIGHT)
		&& (shift_x + data->line.x1 > 0)
		&& (shift_y + data->line.y1 > 0))
	{
		if (data->line.z1 != 0 || data->line.z2 != 0)
			img_pix_put(&data->img, shift_x + data->line.x1,
				shift_y + data->line.y1, RED_PIXEL);
		else
			img_pix_put(&data->img, shift_x + data->line.x1,
				shift_y + data->line.y1, WHITE_PIXEL);
	}
}

void	ft_dda(t_data *data, int ix, int iy, int status)
{
	int		dx;
	int		dy;
	int		steps;
	float	inc_x;
	float	inc_y;

	set_line_coordinates(data, ix, iy, status);
	steps = 0;
	// calculate_iso(data);
	dx = data->line.x2 - data->line.x1;
	dy = data->line.y2 - data->line.y1;
	calculate_steps(&steps, dx, dy);
	inc_x = dx / (float)steps;
	inc_y = dy / (float)steps;
	while (steps >= 0)
	{
		draw_line(data);
		data->line.x1 += inc_x;
		data->line.y1 += inc_y;
		steps--;
	}
}

void	calculate_steps(int *steps, int dx, int dy)
{
	if (ft_abs(dx) > ft_abs(dy))
		*steps = ft_abs(dx);
	else
		*steps = ft_abs(dy);
}
