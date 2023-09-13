/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_extension.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduheron <lduheron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 12:48:28 by lduheron          #+#    #+#             */
/*   Updated: 2023/09/13 15:21:04 by lduheron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// A OPTI AVEC STRCMP
int	check_extension(char *file)
{
	int	len;

	len = ft_strlen(file) - 1;
	if (len < 3)
		return (0);
	// if (ft_strcmp())
	if (file[len - 3] == '.')
	{
		if (file[len - 2] == 'c')
		{
			if (file[len - 1] == 'u')
			{
				if (file[len] == 'b')
					return (1);
			}
		}
	}
	return (0);
}
