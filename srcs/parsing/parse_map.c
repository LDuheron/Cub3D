/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduheron <lduheron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 14:42:02 by lduheron          #+#    #+#             */
/*   Updated: 2023/09/19 20:11:46 by lduheron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_map_empty(t_parsing_data *parsing, char *argv)
{
	char	*line;
	int		i;
	int		fd;

	i = 0;
	fd = open(argv, O_RDONLY);
	if (fd == -1)
		return (error_message(ERROR_FD));
	line = get_next_line(fd);
	while (i <= parsing->line_last_texture)
	{
		free(line);
		line = get_next_line(fd);
		i++;
	}
	while (is_empty_line(line) == EMPTY)
	{
		free(line);
		line = get_next_line(fd);
	}
	while (is_empty_line(line) != EMPTY)
	{
		free(line);
		line = get_next_line(fd); // lost of 4bytes when ERROR
	}
	if (line != NULL)
	{
		free(line);
		return (error_parsing_message(ERROR_MAP));
	}
	free(line);
	return (SUCCESS);
}

int	retrieve_map(t_parsing_data *parsing)
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
