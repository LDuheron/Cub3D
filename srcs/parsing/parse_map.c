/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduheron <lduheron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 14:42:02 by lduheron          #+#    #+#             */
/*   Updated: 2023/09/29 16:57:37 by lduheron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	fill_player_information(t_parsing_data *parsing, int i, int j)
{
	parsing->pos_p_x = i;
	parsing->pos_p_y = j;
	parsing->pos_type = parsing->map[i][j];
	parsing->map[i][j] = '0';
}

static int	error_player(int i)
{
	if (i == 0)
		return (error_message_initial_reading(EMPTY_MAP));
	return (error_parsing_message(NO_PLAYER));
}

static int	find_player_position(t_parsing_data *parsing)
{
	int	i;
	int	j;
	int	cpt;

	i = 0;
	cpt = 0;
	while (parsing->map && parsing->map[i])
	{
		j = 0;
		while (parsing->map && parsing->map[i][j])
		{
			if (ft_strchr("NSEW\n", parsing->map[i][j]) != NULL)
			{
				cpt += 1;
				if (cpt > 1)
					return (error_parsing_message(TOO_MUCH_PLAYER));
				fill_player_information(parsing, i, j);
			}
			j++;
		}
		i++;
	}
	if (cpt == 0)
		return (error_player(i));
	return (SUCCESS);
}

// RETRIEVE_MAP: This function extracts from parsing->file the lines
// corresponding to the map and allocates it in parsing->map.
static int	retrieve_map(t_parsing_data *parsing)
{
	int	i;
	int	start;
	int	end;

	i = 0;
	start = parsing->line_last_texture + 1;
	while (parsing->file[start] && is_empty_line(parsing->file[start]))
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

int	map_management(t_parsing_data *parsing)
{
	if (retrieve_map(parsing) == SUCCESS)
		if (find_player_position(parsing) == SUCCESS)
			if (is_surrounded_by_walls(parsing) == SUCCESS)
				return (SUCCESS);
	return (ERROR);
}
