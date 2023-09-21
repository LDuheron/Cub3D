/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduheron <lduheron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 13:19:22 by lduheron          #+#    #+#             */
/*   Updated: 2023/09/21 16:42:24 by lduheron         ###   ########.fr       */
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

// PARSING : The parsing function retrieves the argument given 
// by the user, copies it in the parsing_data structure through
// the read_input_file function then check if the map is valid.

int	parsing(t_parsing_data *parsing, char *argv)
{
	init_parsing_data(parsing);
	if (first_reading(argv) == SUCCESS)
		if (read_input_file(parsing, argv) == SUCCESS)
			if (retrieve_texture(parsing) == SUCCESS)
				if (map_management(parsing) == SUCCESS)
					return (SUCCESS);
	return (ERROR);
}
