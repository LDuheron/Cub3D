/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_and_sort_map.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduheron <lduheron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 12:47:50 by lduheron          #+#    #+#             */
/*   Updated: 2023/09/13 15:41:41 by lduheron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (s1[i] && s2[i] && s1[i] == s2[i] && i < (n - 1))
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

*/

// SORT_TEXTURE : Retrieves from parsing->file the path of textures 
// and stores it the following way :
// texture[0] = NO
// texture[1] = SO
// texture[2] = WE
// texture[3] = SE
// texture[4] = F
// texture[5] = C

int	retrieve_texture(t_parsing_data *parsing)
{
	int	i;

	i = 0;
	parsing->texture = malloc(sizeof(char **) * 6);
	if (!parsing->texture)
		return (error_message(ERROR_MALLOC));
	while (parsing->map[i] && i < 6)
	{
		parsing->texture[i] = parsing->map[i];
		i++;
	}
	
	// parsing->texture[i] = ft_strdup("\0");
	// printf("\n");
	// print_tab(parsing->texture);
	return (SUCCESS);
}

// SORT_INPUT_FILE : Once the map input has been retrieved, this
// function sort the information related to texture and stored it
// in **texture, and the map in **map.

int	sort_input_file(t_parsing_data *parsing)
{
	// put texture in texture.
	// retrieve_texture(parsing);
	// put map in map.
	(void) parsing;
	return (SUCCESS);
}

// read_input_file : This function reads the input and stores
// it in the parsing structure under the variable map.

int	read_input_file(t_parsing_data *parsing, char *argv)
{
	char	*file_tmp;
	char	*line;
	char	*backup;
	int		fd;

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
	parsing->map = ft_split(file_tmp, '\n');
	free(file_tmp);
	close(fd);
	return (SUCCESS);
}
