/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_something.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduheron <lduheron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 15:00:01 by lduheron          #+#    #+#             */
/*   Updated: 2023/09/16 15:57:35 by lduheron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	is_space(char c)
{
	return (c == ' ' || c == '\t' || c == '\r' || c == '\n' || c == '\v');
}

int	is_empty_line(char *line)
{
	int	i;

	i = 0;
	while (line && line[i])
	{
		if (is_space(line[i]) == 0)
			return (NOT_EMPTY);
		i++;
	}	
	return (EMPTY);
}

// PB CAR SPACE DANS LA MAP ? RETIRER
int	is_valid_char(t_parsing_data *parsing)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (parsing->map && parsing->map[i])
	{
		j = 0;
		while (parsing->map[i] && parsing->map[i][j])
		{
			if (ft_strchr(" 01NSEW", parsing->map[i][j]) == NULL)
				return (error_message(ERROR_CHAR));
			j++;
		}
		i++;
	}
	return (SUCCESS);
}
