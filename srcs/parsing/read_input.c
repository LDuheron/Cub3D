/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduheron <lduheron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 12:47:50 by lduheron          #+#    #+#             */
/*   Updated: 2023/09/17 17:42:33 by lduheron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/// return error si string = null; /
// idee null 
// int	trim_texture(t_parsing_data *parsing)
// {
// 	int	i;
// 	char	*str_tmp;

// 	i = 0;
// 	while (parsing->texture[i])
// 	{
// 		if (i < 4)
// 			str_tmp = ft_substr(parsing->texture[i], 3, ft_strlen(parsing->texture[i]));
// 		else
// 			str_tmp = ft_substr(parsing->texture[i], 3, ft_strlen(parsing->texture[i]));
// 		if (str_tmp == NULL)
// 			return (ERROR);
// 		free(parsing->texture[i]);
// 		parsing->texture[i] = ft_strdup(parsing->texture[i]);
// 		free(str_tmp);
// 		i++;
// 	}
// 	return (SUCCESS);
// }

int	trim_str(char *path)
{
	int	i;

	i = 0;
	while (path[i] && is_space(path[i]) == 0)
		i++;
	while (path[i] && is_space(path[i]) == 1)
		i++;
	printf("%c", path[i]);
	return (SUCCESS);
}

int	trim_texture(t_parsing_data *parsing)
{
	int	i;

	i = 0;
	while (parsing->texture[i])
	{
		trim_str(parsing->texture[i]);
		i++;
	}
	return (SUCCESS);
}

// SORT_INPUT_FILE : Once the map input has been retrieved, this
// function sort the information related to texture and stored it
// in **texture, and the map in **map.
	// retrieve_map(parsing);
	// put map in map.
	// check_char(parsing);

int	sort_input_file(t_parsing_data *parsing)
{
	if (retrieve_texture(parsing) == SUCCESS)
		if (trim_texture(parsing) == SUCCESS)
			if (is_valid_texture(parsing) == SUCCESS)
				return (SUCCESS);
	return (ERROR);
}

// READ_INPUT_FILE : This function reads the input and stores
// it in the parsing structure under the variable map.
int	read_input_file(t_parsing_data *parsing, char *argv)
{
	char	*file_tmp;
	char	*line;
	char	*backup;
	int		fd;

	if (check_extension(argv, ".cub") != SUCCESS)
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
