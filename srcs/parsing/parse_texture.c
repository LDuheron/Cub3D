/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduheron <lduheron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 14:43:04 by lduheron          #+#    #+#             */
/*   Updated: 2023/09/18 14:56:07 by lduheron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// FIRST_C_TO_EXTRACT : this function retrieves the first character of 
// the path by passing upon the first characters that are letters 
// (NO, SO, SE, WE, F, C), then by passing upon the spaces that separates
// the direction with the path.
static int	first_c_to_extract(char *path)
{
	int	i;

	i = 0;
	while (path[i] && is_space(path[i]) == 0)
		i++;
	while (path[i] && is_space(path[i]) == 1)
		i++;
	return (i);
}

// EXTRACT_TEXTURE_PATH : This function 
// parsing->texture[i] = ft_strdup(parsing->file[line]);
// i : indicate which direction we are working on.
// line : line number in the file.
static int	extract_texture_path(t_parsing_data *parsing, int line, int i)
{
	int		len;
	int		start;
	char	*tmp_path;

	start = first_c_to_extract(parsing->file[line]);
	len = ft_strlen(parsing->file[line]) - start;
	tmp_path = ft_substr(parsing->file[line], start, len);
	parsing->texture[i] = ft_strdup(tmp_path);
	free(tmp_path);
	return (SUCCESS);
}

// find_line_to_extract : This function extracts from file the paths of 
// the textures.
// return la ligne d'ou extraire dans le file pour NO etc

static int	find_line_to_extract(t_parsing_data *parsing, int code, int i)
{
	while (parsing->file[i] && is_empty_line(parsing->file[i]) == EMPTY)
		i++;
	if (code == 0 && ft_strncmp(parsing->file[i], "NO", 2) == 0)
		return (i);
	else if (code == 1 && ft_strncmp(parsing->file[i], "SO", 2) == 0)
		return (i);
	else if (code == 2 && ft_strncmp(parsing->file[i], "WE", 2) == 0)
		return (i);
	else if (code == 3 && ft_strncmp(parsing->file[i], "SE", 2) == 0)
		return (i);
	else if (code == 4 && ft_strncmp(parsing->file[i], "F", 1) == 0)
		return (i);
	else if (code == 5 && ft_strncmp(parsing->file[i], "C", 1) == 0)
		return (i);
	return (ERROR_TEXTURE);
}

// RETRIEVE_TEXTURE : Retrieves from parsing->file the path of textures 
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
	int	stat_i;
	int	line;

	stat_i = 0;
	i = 0;
	line = 0;
	parsing->texture = ft_calloc(sizeof(char *), 7);
	if (!parsing->texture)
		return (error_message(ERROR_MALLOC));
	while (parsing->file[i] && i < 6)
	{
		line = find_line_to_extract(parsing, i, stat_i);
		stat_i = line + 1;
		if (line == ERROR_TEXTURE)
			return (error_texture_message(line));
		if (extract_texture_path(parsing, line, i) != SUCCESS)
			return (ERROR);
		i++;
	}
	printf("\n -- print tab texture -- \n");
	print_tab(parsing->texture);
	return (SUCCESS);
}
