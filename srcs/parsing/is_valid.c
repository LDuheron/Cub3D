/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduheron <lduheron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 15:17:06 by lduheron          #+#    #+#             */
/*   Updated: 2023/09/21 14:32:18 by lduheron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	is_valid_char(char *line)
{
	int	i;

	i = 0;
	while (line && line[i])
	{
		if (ft_strchr(" 01NSEW\n", line[i]) == NULL)
			return (error_message(ERROR_CHAR));
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
