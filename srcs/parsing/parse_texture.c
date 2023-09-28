/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduheron <lduheron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 14:43:04 by lduheron          #+#    #+#             */
/*   Updated: 2023/09/28 20:45:20 by lduheron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// FIRST_C_TO_EXTRACT: This function extracts the first path character by
// skipping direction indicators (NO, SO, WE, EA, F, C) and leading spaces.
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

static int	last_c_to_extract(char *path)
{
	int	i;

	i = ft_strlen(path) - 1;
	while (path[i] && is_space(path[i]) == 1)
		i--;
	return (i + 1);
}

// EXTRACT_TEXTURE_PATH: This function extracts the texture path or color 
// code from the given line and stores it in parsing->texture.
// i : indicates the line of parsing->texture we are working on :
// NO, SO, WE, EA, F or C.
// line : indicates the line of parsing->file we are working on.
static int	extract_texture_path(t_parsing_data *parsing, int line, int i)
{
	int		len;
	int		start;
	char	*tmp_path;

	start = first_c_to_extract(parsing->file[line]);
	len = last_c_to_extract(parsing->file[line]) - start;
	tmp_path = ft_substr(parsing->file[line], start, len);
	parsing->texture[i] = ft_strdup(tmp_path);
	free(tmp_path);
	if (i < 4)
		if (is_valid_path(parsing->texture[i]) == ERROR)
			return (ERROR);
	if (i >= 4)
		if (is_valid_color(parsing->texture[i]) == ERROR)
			return (ERROR);
	return (SUCCESS);
}

// FIND_LINE_TO_EXTRACT: This function returns the line number in parsing->file 
// from which to extract the paths of textures or color codes.
static int	find_line_to_extract(t_parsing_data *parsing, int code, int i)
{
	// int	j;

	while (parsing->file[i] && is_empty_line(parsing->file[i]) == EMPTY)
		i++;
	// j = 0;
	// while (parsing->file[i][j] && is_space(parsing->file[i][j]) == 1)
	// 	j++;
	// parsing->file[i] = ft_substr(parsing->file[i], j, ft_strlen(parsing->file[i]));
	// printf("|%s|\n", parsing->file[i]);
	if (code == 0 && ft_strncmp(parsing->file[i], "NO ", 3) == 0)
		return (i);
	else if (code == 1 && ft_strncmp(parsing->file[i], "SO ", 3) == 0)
		return (i);
	else if (code == 2 && ft_strncmp(parsing->file[i], "WE ", 3) == 0)
		return (i);
	else if (code == 3 && ft_strncmp(parsing->file[i], "EA ", 3) == 0)
		return (i);
	else if (code == 4 && ft_strncmp(parsing->file[i], "F ", 2) == 0)
		return (i);
	else if (code == 5 && ft_strncmp(parsing->file[i], "C ", 2) == 0)
		return (i);
	return (ERROR_TEXTURE);
}

// RETRIEVE_TEXTURE: This function extracts the lines corresponding to the 
// texture's path and color code from parsing->file and allocates them in 
// parsing->texture as follows:
// texture[0] = NO
// texture[1] = SO
// texture[2] = WE
// texture[3] = EA
// texture[4] = F
// texture[5] = C

int	retrieve_texture(t_parsing_data *parsing)
{
	int	i;
	int	static_i;
	int	line;

	static_i = 0;
	i = 0;
	line = 0;
	parsing->texture = ft_calloc(sizeof(char *), 7);
	if (!parsing->texture)
		return (error_message(ERROR_MALLOC));
	while (parsing->file[i] && i < 6)
	{
		line = find_line_to_extract(parsing, i, static_i);
		static_i = line + 1;
		if (line == ERROR_TEXTURE)
			return (error_parsing_message(line));
		if (extract_texture_path(parsing, line, i) == ERROR)
			return (ERROR);
		i++;
	}
	parsing->line_last_texture = line;
	return (SUCCESS);
}
