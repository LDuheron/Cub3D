/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduheron <lduheron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 14:43:04 by lduheron          #+#    #+#             */
/*   Updated: 2023/09/15 19:47:07 by lduheron         ###   ########.fr       */
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
int	extract_texture_path(t_parsing_data *parsing, int code)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (parsing->file[i] && is_empty_line(parsing->file[i]) == EMPTY)
		i++;
	while (is_space(parsing->file[i][j]) == 1)
		j++;
	if (code == 0 && ft_strncmp(parsing->file[i], "NO", j + 3) == 1)
		return (i);
	else if (code == 1 && ft_strncmp(parsing->file[i], "SO", j + 3))
		return (i);
	else if (code == 2 && ft_strncmp(parsing->file[i], "WE", j + 3))
		return (i);
	else if (code == 3 && ft_strncmp(parsing->file[i], "SE", j + 3))
		return (i);
	else if (code == 4 && ft_strncmp(parsing->file[i], "F", j + 3))
		return (i);
	else if (code == 5 && ft_strncmp(parsing->file[i], "C", j + 3))
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
	int	line;

	i = 0;
	line = 0;
	parsing->texture = ft_calloc(sizeof(char *), 6);
	if (!parsing->texture)
		return (error_message(ERROR_MALLOC));
	while (parsing->file[i] && i < 6)
	{
		line = extract_texture_path(parsing, i);
		if (line != ERROR_TEXTURE)
			parsing->texture[i] = ft_strdup(parsing->file[line]);
		i++;
	}
	return (SUCCESS);
}
