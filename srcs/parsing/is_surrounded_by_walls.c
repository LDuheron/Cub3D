/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_surrounded_by_walls.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduheron <lduheron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 18:59:56 by lduheron          #+#    #+#             */
/*   Updated: 2023/09/21 16:11:17 by lduheron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	is_correct_extreme_line(char *line)
{
	int	i;

	i = 0;
	while (line && line[i])
	{
		if (ft_strchr(" 1\n", line[i]) == NULL)
			return (error_message_first_reading(MAP_OPEN));
		i++;
	}
	return (SUCCESS);
}

static int	is_zero_next_to_space(char **map, int i, int j)
{
	int	previous_len;
	int	len;
	int	next_len;

	previous_len = ft_strlen(map[i - 1]);
	len = ft_strlen(map[i]);
	next_len = ft_strlen(map[i + 1]);
	// haut
	if (j < previous_len && map[i - 1][j] && map[i - 1][j] == '0')
		return (error_message_first_reading(MAP_OPEN));
	// bas
	if (j < next_len && map[i + 1][j] && map[i + 1][j] == '0')
		return (error_message_first_reading(MAP_OPEN));
	// gauche
	if (j != 0 && map[i][j - 1] && map[i][j - 1] == '0')
		return (error_message_first_reading(MAP_OPEN));
	// droite
	if ((j + 1) <= len && map[i][j + 1] && map[i][j + 1] == '0')
		return (error_message_first_reading(MAP_OPEN));
	return (SUCCESS);
}

int	is_surrounded_by_walls(t_parsing_data *parsing)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	if (is_correct_extreme_line(parsing->map[0]) == ERROR)
		return (ERROR);
	while (parsing->map && parsing->map[i])
	{
		j = 0;
		while (parsing->map && parsing->map[i][j])
		{
			if (parsing->map[i][j] == ' ')
				if (is_zero_next_to_space(parsing->map, i, j) == ERROR)
					return (ERROR);
			j++;
		}
		i++;
	}
	if (is_correct_extreme_line(parsing->map[i - 1]) == ERROR)
		return (ERROR);
	return (SUCCESS);
}
