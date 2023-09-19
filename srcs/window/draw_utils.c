/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbernaze <cbernaze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 15:40:57 by cbernaze          #+#    #+#             */
/*   Updated: 2023/09/19 17:38:16 by cbernaze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graph.h"

void	set_shift(int *shift_x, int *shift_y)
{
	*shift_x = 1;
	*shift_y = 1;
}

int	ft_abs(int nb)
{
	if (nb < 0)
		nb *= -1;
	return (nb);
}

void	set_line_coordinates(t_data *data, int ix, int iy)
{
	int	zoom;

	zoom = 50;
	data->line.x1 = ix * zoom;
	data->line.x2 = ix + 1;
	data->line.x2 *= zoom;
	data->line.y1 = iy * zoom;
	data->line.y2 = iy;
	data->line.y2 *= zoom;
}

void	calculate_steps(int *steps, int dx, int dy)
{
	if (ft_abs(dx) > ft_abs(dy))
		*steps = ft_abs(dx);
	else
		*steps = ft_abs(dy);
}

void	draw_line(t_data *data, int color)
{
	int	shift_x;
	int	shift_y;

	set_shift(&shift_x, &shift_y);
	if ((shift_x + data->line.x1 < WIN_WIDTH)
		&& (shift_y + data->line.y1 < WIN_HEIGHT)
		&& (shift_x + data->line.x1 > 0)
		&& (shift_y + data->line.y1 > 0))
	{
		img_pix_put(&data->img, shift_x + data->line.x1, shift_y + data->line.y1, color);
	}
}

void	ft_dda(t_data *data, int ix, int iy, int color)
{
	int		dx;
	int		dy;
	int		steps;
	float	inc_x;
	float	inc_y;

	set_line_coordinates(data, ix, iy);
	steps = 0;
	dx = data->line.x2 - data->line.x1;
	dy = data->line.y2 - data->line.y1;
	inc_x = data->line.x1;
	inc_y = 0;
	while (inc_y < 49)
	{
		calculate_steps(&steps, dx, dy);
		while (steps >= 2)
		{
			draw_line(data, color);
			data->line.x1++;
			steps--;
		}
		data->line.x1 = inc_x;
		data->line.y1++;
		inc_y++;
	}
}
