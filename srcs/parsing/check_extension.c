/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_extension.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduheron <lduheron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 12:48:28 by lduheron          #+#    #+#             */
/*   Updated: 2023/09/13 18:35:50 by lduheron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_char(t_parsing_data *parsing)
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
			// printf("%c", parsing->map[i][j]); // DEBUG
			if (ft_strchr(" 01NSEW", parsing->map[i][j]) == NULL)
				return (error_message(ERROR_CHAR));
			j++;
		}
		// printf("\n"); // DEBUG
		i++;
	}
	return (SUCCESS);
}


// A OPTI AVEC STRCMP
int	check_extension(char *file)
{
	int	len;

	len = ft_strlen(file) - 1;
	if (len < 3)
		return (0);
	if (file[len - 3] == '.')
	{
		if (file[len - 2] == 'c')
		{
			if (file[len - 1] == 'u')
			{
				if (file[len] == 'b')
					return (1);
			}
		}
	}
	return (0);
}
