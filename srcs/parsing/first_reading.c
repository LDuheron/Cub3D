/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_reading.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduheron <lduheron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 14:50:32 by lduheron          #+#    #+#             */
/*   Updated: 2023/09/21 16:45:25 by lduheron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	init_parsing_first_r(t_parsing_first_r *data, char *argv)
{
	data->cpt_texture = 0;
	data->belong_to_map = 0;
	data->size = 0;
	data->fd = open(argv, O_RDONLY);
	if (data->fd == -1)
		return (error_message(ERROR_FD));
	return (SUCCESS);
}

static int	is_valid_line(t_parsing_first_r *data, char *line)
{
	data->size += 1;
	if (data->size >= 1000)
		return (error_message_first_reading(TOO_BIG));
	if (data->cpt_texture < 6)
	{
		if (ft_isalpha(line[0]) == 1)
			data->cpt_texture += 1;
		else if (is_empty_line(line) == NOT_EMPTY)
			return (error_message_first_reading(M_TEXTURE));
	}
	else if (is_empty_line(line) == NOT_EMPTY)
	{
		data->belong_to_map += 1;
		if (is_valid_char(line) == ERROR)
			return (ERROR);
	}
	else if (is_empty_line(line) == EMPTY && data->belong_to_map > 0)
		return (error_message_first_reading(EMPTY_LINE_IN_MAP));
	return (SUCCESS);
}

int	first_reading(char *argv)
{
	t_parsing_first_r	data;

	if (init_parsing_first_r(&data, argv) == ERROR)
		return (ERROR);
	data.line = get_next_line(data.fd);
	if (!data.line)
		return (error_message_first_reading(EMPTY_MAP));
	while (data.line)
	{
		if (is_valid_line(&data, data.line) == ERROR)
		{
			while (data.line)
			{
				free(data.line);
				data.line = get_next_line(data.fd);
			}
			return (ERROR);
		}
		free(data.line);
		data.line = get_next_line(data.fd);
	}
	free(data.line);
	close(data.fd);
	return (SUCCESS);
}
