/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduheron <lduheron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 13:19:22 by lduheron          #+#    #+#             */
/*   Updated: 2023/09/20 15:57:22 by lduheron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	init_parsing_data(t_parsing_data *parsing)
{
	parsing->file = NULL;
	parsing->map = NULL;
	parsing->texture = NULL;
	parsing->line_last_texture = 0;
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

// READ_INPUT_FILE : This function reads the input and stores
// it in the parsing structure under the variable map.
static int	read_input_file(t_parsing_data *parsing, char *argv)
{
	char	*file_tmp;
	char	*line;
	char	*backup;
	int		fd;

	if (is_valid_extension(argv, ".cub") != SUCCESS)
		return (error_message(ERROR_EXTENSION));
	fd = open(argv, O_RDONLY);
	if (fd == -1)
		return (error_message(ERROR_FD));
	file_tmp = ft_strdup("");
	line = get_next_line(fd);
	while (line)
	{
		backup = file_tmp;
		file_tmp = ft_strjoin(backup, line);
		free(line);
		line = get_next_line(fd);
	}
	parsing->file = ft_split(file_tmp, '\n');
	free(file_tmp);
	close(fd);
	return (SUCCESS);
}

// PARSING : The parsing function retrieves the argument given 
// by the user, copies it in the parsing_data structure through
// the read_input_file function then check if the map is valid.

int	parsing(char *argv)
{
	t_parsing_data	parsing;

	init_parsing_data(&parsing);
	first_reading(argv);
	if (first_reading(argv) == SUCCESS)
	{
		if (read_input_file(&parsing, argv) == SUCCESS)
		{
			if (retrieve_texture(&parsing) == SUCCESS)
			{
				if (retrieve_map(&parsing) == SUCCESS)
				{
					// printf("\n -- print tab map -- \n");
					// print_tab(parsing.map);
					free_parsing_data(&parsing);
					printf("Great map !\n");
					return (SUCCESS);
				}
			}
		}
	}
	free_parsing_data(&parsing);
	return (ERROR);
}
