/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduheron <lduheron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 14:59:01 by lduheron          #+#    #+#             */
/*   Updated: 2023/10/05 14:49:17 by lduheron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// IS_VALID_COLOR_CODE: This function checks that the given code contains only
// digits and precisely two commas.
static int	is_valid_color_code(char *line)
{
	int	cpt_comma;
	int	i;

	cpt_comma = 0;
	i = 0;
	while (line && line[i])
	{
		if (ft_strncmp(&line[i], ",", 1) == 0)
			cpt_comma += 1;
		else if (ft_isdigit(line[i]) == 0)
			return (error_parsing_message(COLOR));
		i++;
	}
	if (cpt_comma != 2)
		return (error_parsing_message(COLOR));
	return (SUCCESS);
}

// IS_RGB_FORMAT: This function ensures that the given number is within the 
// range [0,250] as requested by the RGB format.
static int	is_rgb_format(char *line, int start, int len)
{
	int		nb;
	int		i;
	char	*nb_tmp;

	nb_tmp = NULL;
	i = start;
	if (len == 0 || len > 3)
		return (error_parsing_message(COLOR));
	while (i < start + len)
	{
		if (ft_isdigit(line[i]) != 1)
			return (error_parsing_message(COLOR));
		i++;
	}
	nb_tmp = ft_substr(line, start, len);
	nb = ft_atoi(nb_tmp);
	free(nb_tmp);
	if (nb >= 0 && nb <= 255)
		return (SUCCESS);
	return (error_parsing_message(COLOR));
}

int	is_valid_color(char *line)
{
	int		cpt_color;
	int		i;
	int		len;
	int		start;

	cpt_color = 0;
	i = 0;
	len = ft_strlen(line);
	if (is_valid_color_code(line) == ERROR)
		return (ERROR);
	while (cpt_color < 2)
	{
		start = i;
		while (ft_strncmp(&line[i], ",", 1) != 0)
			i++;
		if (is_rgb_format(line, start, i - start) == ERROR)
			return (ERROR);
		cpt_color++;
		i++;
	}
	start = i;
	if (is_rgb_format(line, start, len - start) == ERROR)
		return (ERROR);
	return (SUCCESS);
}

int	find_line_to_code_color(t_parsing_data *parsing, int code)
{
	char	*indicator;
	int		i;

	i = 0;
	if (code == 4)
		indicator = "F ";
	else if (code == 5)
		indicator = "C ";
	while (parsing->file[i] && ft_strncmp(parsing->file[i], indicator, 2) != 0)
		i++;
	if (parsing->file[i] && ft_strncmp(parsing->file[i], indicator, 2) == 0)
		return (i);
	return (ERROR_TEXTURE);
}
