/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduheron <lduheron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 14:43:04 by lduheron          #+#    #+#             */
/*   Updated: 2023/09/16 18:08:02 by lduheron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// while (parsing->file[i] && i < 5)
// 	{
// 		parsing->texture[i] = ft_strdup(parsing->file[i]);
// 		i++;
// 	}
// 	parsing->texture[i] = NULL;

// EXTRACT_TEXTURE_PATH : This function extracts from file the paths of 
// the textures.
// return la ligne d'ou extraire dans le file pour NO etc
static int	extract_texture_path(t_parsing_data *parsing, int code, int i)
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
	else if (code == 4 && ft_strncmp(parsing->file[i], "F", 2) == 0)
		return (i);
	else if (code == 5 && ft_strncmp(parsing->file[i], "C", 2) == 0)
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
		line = extract_texture_path(parsing, i, stat_i);
		stat_i = line + 1;
		if (line == ERROR_TEXTURE)
			return (error_texture_message(line));
		parsing->texture[i] = ft_strdup(parsing->file[line]);
		i++;
	}
	print_tab(parsing->texture);
	return (SUCCESS);
}
