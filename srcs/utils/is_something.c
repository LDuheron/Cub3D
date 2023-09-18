/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_something.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduheron <lduheron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 15:00:01 by lduheron          #+#    #+#             */
/*   Updated: 2023/09/18 14:58:28 by lduheron         ###   ########.fr       */
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
