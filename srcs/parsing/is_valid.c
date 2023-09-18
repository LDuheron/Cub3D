/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_extension.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduheron <lduheron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 12:48:28 by lduheron          #+#    #+#             */
/*   Updated: 2023/09/18 14:45:44 by lduheron         ###   ########.fr       */
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

static int	is_valid_path(char *path)
{
	int	len;
	int	fd;

	len = ft_strlen(path);
	if (is_valid_extension(path, ".xpm") != SUCCESS)
		return (error_texture_message(ERROR_EXTENSION));
	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (error_texture_message(ERROR_T_OPEN));
	if (close (fd) == -1)
		return (error_message(ERROR_CLOSE));
	return (SUCCESS);
}

int	is_valid_texture(t_parsing_data *parsing)
{
	int	i;

	i = 0;
	while (parsing->texture[i])
	{
		if (is_valid_path(parsing->texture[i]) == ERROR)
			return (ERROR);
		i++;
	}
	return (SUCCESS);
}
