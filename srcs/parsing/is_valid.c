/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduheron <lduheron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 15:17:06 by lduheron          #+#    #+#             */
/*   Updated: 2023/09/18 15:17:08 by lduheron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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

int	is_valid_extension(char *file, char *format)
{
	int	len;

	len = ft_strlen(file) - 1;
	if (len < 3)
		return (0);
	if (file[len - 3] == format[0])
	{
		if (file[len - 2] == format[1])
		{
			if (file[len - 1] == format[2])
			{
				if (file[len] == format[3])
					return (SUCCESS);
			}
		}
	}
	return (ERROR);
}
