/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_reading.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduheron <lduheron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 14:50:32 by lduheron          #+#    #+#             */
/*   Updated: 2023/09/20 15:54:08 by lduheron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	error_message_first_reading(int code)
{
	if (code == M_TEXTURE)
		ft_putstr_fd("Missing texture\n", 2);
	else if (code == EMPTY_LINE_IN_MAP)
		ft_putstr_fd("No empty lines in map\n", 2);
	return (ERROR);
}

static void	init_parsing_first_r(t_parsing_first_r *data)
{
	data->cpt_texture = 0;
	data->is_map = 0; // si > 0 on est sur la map
}

static int	is_valid_line(t_parsing_first_r *data, char *line)
{
	if (data->cpt_texture < 6)
	{
		if (ft_isalpha(line[0]) == 1)
			data->cpt_texture += 1;
		else if (is_empty_line(line) == NOT_EMPTY)
			return (error_message_first_reading(M_TEXTURE));
	}
	else if (is_empty_line(line) == NOT_EMPTY)
		data->is_map += 1;
	else if (is_empty_line(line) == EMPTY && data->is_map > 0)
		return (error_message_first_reading(EMPTY_LINE_IN_MAP));
	return (SUCCESS);
}

int	first_reading(char *argv)
{
	t_parsing_first_r	data;
	char				*line;
	int					fd;

	init_parsing_first_r(&data);
	fd = open(argv, O_RDONLY);
	if (fd == -1)
		return (error_message(ERROR_FD));
	line = get_next_line(fd);
	while (line)
	{
		if (is_valid_line(&data, line) == ERROR)
		{
			while (line)
			{
				free(line);
				line = get_next_line(fd);
			}
			return (ERROR);
		}
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	return (SUCCESS);
}
