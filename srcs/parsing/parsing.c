/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduheron <lduheron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 13:19:22 by lduheron          #+#    #+#             */
/*   Updated: 2023/09/18 14:56:39 by lduheron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	init_parsing_data(t_parsing_data *parsing)
{
	parsing->file = NULL;
	parsing->map = NULL;
	parsing->texture = NULL;
}

static void	free_parsing_data(t_parsing_data *parsing)
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

int	parsing(char *argv)
{
	t_parsing_data	parsing;

	init_parsing_data(&parsing);
	if (read_input_file(&parsing, argv) == SUCCESS)
	{
		if (sort_input_file(&parsing) == SUCCESS)
		{
			free_parsing_data(&parsing);
			return (SUCCESS);
		}
	}
	free_parsing_data(&parsing);
	return (ERROR);
}
