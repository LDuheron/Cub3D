/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_management.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduheron <lduheron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 15:04:48 by lduheron          #+#    #+#             */
/*   Updated: 2023/09/21 22:22:23 by lduheron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_putstr_fd(char *s, int fd)
{
	if (!s || !fd)
		return ;
	write(fd, s, ft_strlen(s));
}

int	error_message_first_reading(int code)
{
	if (code == M_TEXTURE)
		ft_putstr_fd("Error: Missing texture.\n", 2);
	else if (code == EMPTY_LINE_IN_MAP)
		ft_putstr_fd("Error: No empty lines in map.\n", 2);
	else if (code == TOO_BIG)
		ft_putstr_fd("Error: Map too big.\n", 2);
	else if (code == MAP_OPEN)
		ft_putstr_fd("Error: Map is open, it should be surrounded by walls.\n", 2);
	else if (EMPTY_MAP)
		ft_putstr_fd("Error: The map is empty.\n", 2);
	return (ERROR);
}

int	error_parsing_message(int code)
{
	if (code == ERROR_TEXTURE)
		ft_putstr_fd("Error: Please enter the texture in the correct order and without spaces in front of it.\n", 2);
	else if (code == ERROR_EXTENSION)
		ft_putstr_fd("Error: all textures should be .xpm format.\n", 2);
	else if (code == ERROR_T_OPEN)
		ft_putstr_fd("Error: texture cannot be open.\n", 2);
	else if (code == ERROR_MAP)
		ft_putstr_fd("Error: map format invalid, no empty line in map.\n", 2);
	else if (code == TOO_MUCH_PLAYER)
		ft_putstr_fd("Error: The game can only generate one player.\n", 2);
	else if (code == HIDDEN_FILE)
		ft_putstr_fd("Error: Hidden file.\n", 2);
	else if (code == COLOR)
		ft_putstr_fd("Error: colors should be between 0 and 250.\n", 2);
	return (ERROR);
}

int	error_message(int code)
{
	if (code == ERROR_ARG)
		ft_putstr_fd("Error: please insert 2 arguments.\n", 2);
	else if (code == ERROR_CHAR)
		ft_putstr_fd("Error: Map can only contain \" 01NSEW\".\n", 2);
	else if (code == ERROR_CLOSE)
		ft_putstr_fd("Error: Error occured when closing fd.\n", 2);
	else if (code == ERROR_FD)
		ft_putstr_fd("Error: an error occured when opening fd.\n", 2);
	else if (code == ERROR_MALLOC)
		ft_putstr_fd("Error: Malloc failed.\n", 2);
	else if (code == ERROR_EXTENSION)
		ft_putstr_fd("Error: map should be .cub format.\n", 2);
	return (ERROR);
}
