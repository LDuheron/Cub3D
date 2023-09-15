/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduheron <lduheron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 14:43:04 by lduheron          #+#    #+#             */
/*   Updated: 2023/09/15 14:43:24 by lduheron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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

	i = 0;
	parsing->texture = malloc(sizeof(char *) * 6);
	if (!parsing->texture)
		return (error_message(ERROR_MALLOC));
	while (parsing->file[i] && i < 5)
	{
		parsing->texture[i] = ft_strdup(parsing->file[i]);
		i++;
	}
	parsing->texture[i] = NULL;
	return (SUCCESS);
}
