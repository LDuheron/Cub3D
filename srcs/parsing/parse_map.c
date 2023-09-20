/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduheron <lduheron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 14:42:02 by lduheron          #+#    #+#             */
/*   Updated: 2023/09/20 15:49:52 by lduheron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
