/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_surrounded_by_walls.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduheron <lduheron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 18:59:56 by lduheron          #+#    #+#             */
/*   Updated: 2023/09/28 19:34:16 by lduheron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// IS_CORRECT_EXTREME_LINE: This function checks the validity of the top and
// bottom lines of the map, which can only contain 1 and spaces.
static int	is_correct_extreme_line(char *line)
{
	int	i;

	i = 0;
	while (line && line[i])
	{
		if (ft_strchr(" 1\n", line[i]) == NULL)
			return (error_message_initial_reading(MAP_OPEN));
		i++;
	}
	return (SUCCESS);
}

// IS_ZERO_NEXT_TO_SPACE: This function receives the position of a zero in the
// map and checks if the characters surrounding it are spaces. If they are,
// it returns the error message indicating that the map is open and, therefore,
// returns false.
static int	is_zero_next_to_space(char **map, int i, int j)
{
	int	previous_len;
	int	len;
	int	next_len;

	previous_len = ft_strlen(map[i - 1]);
	len = ft_strlen(map[i]);
	next_len = ft_strlen(map[i + 1]);
	if ((!map[i - 1][j]) || (j < previous_len && map[i - 1][j] && is_space(map[i - 1][j])) == 1)
		return (error_message_initial_reading(MAP_OPEN));
	if ((!map[i + 1][j]) || (j < next_len && map[i + 1][j] && is_space(map[i + 1][j]) == 1))
		return (error_message_initial_reading(MAP_OPEN));
	if ((!map[i][j - 1]) || (j != 0 && map[i][j - 1] && is_space(map[i][j - 1]) == 1))
		return (error_message_initial_reading(MAP_OPEN));
	if ((!map[i][j + 1]) || ((j + 1) <= len && map[i][j + 1] && is_space(map[i][j + 1]) == 1))
		return (error_message_initial_reading(MAP_OPEN));
	return (SUCCESS);
}

// IS_SURROUNDED_BY_WALLS: This function checks if the map is correctly closed
// by being surrounded by walls (1) by making sure that the first and last line
// of the map only contains 1 and spaces and then searches for all the character
// 0 in the map and check if they are next to a space through the function
// IS_ZERO_NEXT_TO_SPACE.
int	is_surrounded_by_walls(t_parsing_data *parsing)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	if (is_correct_extreme_line(parsing->map[0]) == ERROR)
		return (ERROR);
	while (parsing->map && parsing->map[i + 1])
	{
		j = 0;
		while (parsing->map && parsing->map[i][j])
		{
			if (parsing->map[i][j] == '0')
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
