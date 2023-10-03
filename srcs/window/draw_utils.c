/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbernaze <cbernaze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 15:53:03 by cbernaze          #+#    #+#             */
/*   Updated: 2023/10/03 17:01:41 by cbernaze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
		while (j < WIN_HEIGHT/2)
		{
			img_pix_put(&data->img, i, j, CEILING);
			j++;
		}
		i++;
	}
	i = 0;
	while (i < WIN_WIDTH)
	{
		j = WIN_HEIGHT;
		while (j >= WIN_HEIGHT/2)
		{
			img_pix_put(&data->img, i, j, FLOOR);
			j--;
		}
		i++;
	}
}
