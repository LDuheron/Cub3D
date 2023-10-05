/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduheron <lduheron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 14:43:04 by lduheron          #+#    #+#             */
/*   Updated: 2023/10/05 14:20:59 by lduheron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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

static int	find_line_to_code_texture(t_parsing_data *parsing, int code)
{
	char	*indicator;
	int		i;

	i = 0;
	if (code == 0)
		indicator = "NO ";
	else if (code == 1)
		indicator = "SO ";
	else if (code == 2)
		indicator = "WE ";
	else if (code == 3)
		indicator = "EA ";
	while (parsing->file[i] && ft_strncmp(parsing->file[i], indicator, 3) != 0)
		i++;
	if (ft_strncmp(parsing->file[i], indicator, 3) == 0)
		return (i);
	return (ERROR_TEXTURE);
}

// FIND_LINE_TO_EXTRACT: This function returns the line number in parsing->file 
// from which to extract the paths of textures or color codes.
static int	find_line_to_extract(t_parsing_data *parsing, int code)
{
	if (code < 4)
		return (find_line_to_code_texture(parsing, code));
	return (find_line_to_code_color(parsing, code));
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
	int	line;

	i = 0;
	line = 0;
	parsing->texture = ft_calloc(sizeof(char *), 7);
	if (!parsing->texture)
		return (error_message(ERROR_MALLOC));
	while (parsing->file[i] && i < 6)
	{
		line = find_line_to_extract(parsing, i);
		if (line > parsing->line_last_texture)
			parsing->line_last_texture = line;
		if (line == ERROR_TEXTURE)
			return (error_parsing_message(line));
		if (extract_texture_path(parsing, line, i) == ERROR)
			return (ERROR);
		i++;
	}
	return (SUCCESS);
}
