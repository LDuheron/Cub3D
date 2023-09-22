/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduheron <lduheron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 15:17:06 by lduheron          #+#    #+#             */
/*   Updated: 2023/09/22 16:27:46 by lduheron         ###   ########.fr       */
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

int	is_valid_color(char *line)
{
	int	nb;
	int	i;

	i = 0;
	if (ft_strlen(line) > 3)
		return (error_parsing_message(COLOR));
	while (line[i])
	{
		if (ft_isdigit(line[i]) != 1)
			return (error_parsing_message(COLOR));
		i++;
	}
	nb = ft_atoi(line);
	if (nb >= 0 && nb <= 250)
		return (SUCCESS);
	return (error_parsing_message(COLOR));
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

int	is_valid_path(char *path)
{
	int	len;
	int	fd;

	len = ft_strlen(path);
	if (len <= 4)
		return (error_parsing_message(HIDDEN_FILE));
	if (is_valid_extension(path, ".xpm") != SUCCESS)
		return (error_parsing_message(ERROR_EXTENSION));
	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (error_parsing_message(ERROR_T_OPEN));
	if (close (fd) == -1)
		return (error_message(ERROR_CLOSE));
	return (SUCCESS);
}
