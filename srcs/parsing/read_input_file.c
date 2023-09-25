/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_input_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduheron <lduheron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 16:30:56 by lduheron          #+#    #+#             */
/*   Updated: 2023/09/21 16:31:29 by lduheron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// READ_INPUT_FILE : This function reads the input and stores
// it in the parsing structure under the variable map.
int	read_input_file(t_parsing_data *parsing, char *argv)
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