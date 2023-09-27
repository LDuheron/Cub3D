/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduheron <lduheron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 13:19:22 by lduheron          #+#    #+#             */
/*   Updated: 2023/09/27 14:34:33 by lduheron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	init_parsing_data(t_parsing_data *parsing)
{
	parsing->file = NULL;
	parsing->map = NULL;
	parsing->texture = NULL;
	parsing->line_last_texture = 0;
	parsing->pos_p_x = 0;
	parsing->pos_p_y = 0;
}

void	free_parsing_data(t_parsing_data *parsing)
{
	if (parsing->file)
		free_char_tab(parsing->file);
	if (parsing->map)
		free_char_tab(parsing->map);
	if (parsing->texture)
		free_char_tab(parsing->texture);
}

// PARSING: This function reads the map to check if the initial map format
// requirements are met. It then stores the map in parsing->file, which is 
// further divided into parsing->texture and parsing->map.
int	parsing(t_parsing_data *parsing, char *argv)
{
	init_parsing_data(parsing);
	if (initial_reading(argv) == SUCCESS)
		if (store_input_file(parsing, argv) == SUCCESS)
			if (retrieve_texture(parsing) == SUCCESS)
				if (map_management(parsing) == SUCCESS)
					return (SUCCESS);
	return (ERROR);
}
