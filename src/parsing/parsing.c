/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduheron <lduheron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 13:19:22 by lduheron          #+#    #+#             */
/*   Updated: 2023/09/12 14:23:54 by lduheron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_parsing_data(t_parsing_data parsing)
{
	parsing->map = NULL;
	parsing->cpt_line = 0;

}

// GET_MAP : This function reads the input and stores
// it in the parsing structure under the variable map.

int	get_map(t_parsing_data parsing, char *argv)
{
	char	*map_tmp;
	char	*line;
	int		fd;

	fd = open(argv, O_RDONLY);
	if (fd == -1)
		return (ERROR);
	line = get_next_line(fd);
	while (line)
	{
		ft_strjoin
		free(line);
		line = get_next_line(fd);
	}
	parsing->map = ft_split();
	return (SUCCESS);
}


// PARSING : The parsing function retrieves the argument given 
// by the user, copies it in the parsing_data structure through
// the get_map function then check if the map is valid.

int	parsing(char *argv)
{
	t_parsing_data	parsing;

	init_parsing_data(parsing);
	if (get_map(parsing, argv) == SUCCESS)
		return (SUCCESS);
	return (ERROR);
}
