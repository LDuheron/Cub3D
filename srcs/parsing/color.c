/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduheron <lduheron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 14:59:01 by lduheron          #+#    #+#             */
/*   Updated: 2023/09/25 16:57:32 by lduheron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_count_coma(char *line)
{
	int	cpt_coma;
	int	i;

	cpt_coma = 0;
	i = 0;
	while (line && line[i])
	{
		if (ft_strncmp(&line[i], ",", 1) == 0)
		{
			cpt_coma += 1;
			printf("-- virgule : %c --\n", line[i]);
		}
		i++;
	}
	if (cpt_coma != 2)
		return (error_parsing_message(COLOR));
	return (SUCCESS);
}

int	is_valid_color(char *line)
{
	int		cpt_color;
	int		i;
	int		len;
	// int		start;
	// char	*color_code;

	cpt_color = 0;
	i = 0;
	len = ft_strlen(line);
	if (ft_count_coma(line) == ERROR)
		return (ERROR);
	// while (i <= len)
	// {
	// 	start = i;
	// 	while (len[i] && len[i] != ',')
	// 		i++;
	// 	color_code = ft_substr(line, start, i - len);
	// 	if (str[i] == ",")
			
	// 	i++;
	// }
	// if (cpt != 3)
	// 	return (ERROR);
	if (is_color_code(line) == ERROR)
		return (ERROR);
	return (SUCCESS);
}

int	is_color_code(char *line)
{
	int	nb;
	int	i;

	i = 0;
	is_valid_color(line);
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

// SAVE
// int	is_color_code(char *line)
// {
// 	int	nb;
// 	int	i;

// 	i = 0;
// 	if (ft_strlen(line) > 3)
// 		return (error_parsing_message(COLOR));
// 	while (line[i])
// 	{
// 		if (ft_isdigit(line[i]) != 1)
// 			return (error_parsing_message(COLOR));
// 		i++;
// 	}
// 	nb = ft_atoi(line);
// 	if (nb >= 0 && nb <= 250)
// 		return (SUCCESS);
// 	return (error_parsing_message(COLOR));
// }

