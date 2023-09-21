/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduheron <lduheron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 14:42:02 by lduheron          #+#    #+#             */
/*   Updated: 2023/09/21 16:32:31 by lduheron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	retrieve_map(t_parsing_data *parsing)
{
	int	i;
	int	start;
	int	end;

	i = 0;
	start = parsing->line_last_texture + 1;
	while (is_empty_line(parsing->file[start]))
		start++;
	end = start;
	while (parsing->file[end])
		end++;
	parsing->map = ft_calloc(sizeof(char *), (end - start + 1));
	if (!parsing->map)
		return (error_message(ERROR_MALLOC));
	while (parsing->file[start])
	{
		parsing->map[i] = ft_strdup(parsing->file[start]);
		if (parsing->map[i] == NULL)
			return (error_message(ERROR_MALLOC));
		i++;
		start++;
	}
	return (SUCCESS);
}

// check character
int	map_management(t_parsing_data *parsing)
{
	if (retrieve_map(parsing) == SUCCESS)
		if (is_surrounded_by_walls(parsing) == SUCCESS)
			// if (find_player_position(parisng) == SUCCESS)
			return (SUCCESS);
	return (ERROR);
}
