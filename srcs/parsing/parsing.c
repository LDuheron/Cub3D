/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduheron <lduheron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 13:19:22 by lduheron          #+#    #+#             */
/*   Updated: 2023/09/15 19:35:41 by lduheron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_parsing_data(t_parsing_data *parsing)
{
	parsing->file = NULL;
	parsing->map = NULL;
	parsing->texture = NULL;
	parsing->cpt_line = 0;
}

void	free_parsing_data(t_parsing_data *parsing)
{
	if (parsing->file)
		free_tab(parsing->file);
	if (parsing->map)
		free_tab(parsing->map);
	if (parsing->texture)
		free_tab(parsing->texture);
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
		print_tab(parsing.map);
		if (sort_input_file(&parsing) == SUCCESS)
		{
			free_parsing_data(&parsing);
			return (SUCCESS);
		}
	}
	return (ERROR);
}
