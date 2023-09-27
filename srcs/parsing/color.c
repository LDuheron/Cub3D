/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduheron <lduheron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 14:59:01 by lduheron          #+#    #+#             */
/*   Updated: 2023/09/27 15:45:45 by lduheron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	ft_count_comma(char *line)
{
	int	cpt_comma;
	int	i;

	cpt_comma = 0;
	i = 0;
	while (line && line[i])
	{
		if (ft_strncmp(&line[i], ",", 1) == 0)
			cpt_comma += 1;
		i++;
	}
	if (cpt_comma != 2)
		return (error_parsing_message(COLOR));
	return (SUCCESS);
}

static int	is_color_code(char *line, int start, int len)
{
	int	nb;
	int	i;

	printf("color is checked !\n");
	i = start;
	if (len == 0 || len > 3)
		return (error_parsing_message(COLOR));
	while (i < len)
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

int	is_valid_color(char *line)
{
	int		cpt_color;
	int		i;
	int		len;
	int		start;

	printf("%s\n", line);
	cpt_color = 0;
	i = 0;
	len = ft_strlen(line);
	if (ft_count_comma(line) == ERROR)
		return (ERROR);
	while (cpt_color < 2)
	{
		start = i;
		while (ft_strncmp(&line[i], ",", 1) != 0)
			i++;
		if (is_color_code(line, start, i - start) == ERROR)
			return (ERROR);
		cpt_color++;
		i++;
	}
	start = i;
	if (is_color_code(line, start, len - start) == ERROR)
		return (ERROR);
	return (SUCCESS);
}
