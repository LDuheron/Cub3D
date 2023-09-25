/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduheron <lduheron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 14:59:01 by lduheron          #+#    #+#             */
/*   Updated: 2023/09/25 16:09:41 by lduheron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// int	is_valid_color(char *line)
// {
// 	int		cpt_color;
// 	int		cpt_v;
// 	int		i;
// 	int		len;
// 	char	*color_code;

// 	cpt_color = 0;
// 	cpt_v = 0;
// 	i = 0;
// 	len = ft_strlen(line);
// 	while (i <= len)
// 	{
	// ft_substr;
// 		while (len[i] && len[i] != ',')
// 			i++;
// 		if (str[i] == ',')
		
// 		i++;
// 	}
// 	if (cpt != 3)
// 		return (ERROR);
// 	return (SUCCESS);
// }

int	is_color_code(char *line)
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

