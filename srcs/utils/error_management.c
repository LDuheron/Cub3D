/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_management.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbernaze <cbernaze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 15:04:48 by lduheron          #+#    #+#             */
/*   Updated: 2023/10/04 15:00:58 by cbernaze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	ft_putstr_fd(char *s, int fd)
{
	if (!s || !fd)
		return ;
	write(fd, s, ft_strlen(s));
}

int	error_message_initial_reading(int code)
{
	if (code == M_TEXTURE)
		ft_putstr_fd("Error: Missing texture or color code.\n", 2);
	else if (code == EMPTY_LINE_IN_MAP)
		ft_putstr_fd("Error: No empty lines in map.\n", 2);
	else if (code == TOO_BIG)
		ft_putstr_fd("Error: Map too big.\n", 2);
	else if (code == MAP_OPEN)
		ft_putstr_fd("Error: Map is open, it should be surrounded by \
walls.\n", 2);
	else if (EMPTY_MAP)
		ft_putstr_fd("Error: The map is empty.\n", 2);
	return (ERROR);
}

int	error_parsing_message(int code)
{
	if (code == ERROR_TEXTURE)
		ft_putstr_fd("Error: Texture and color are strictly order : \
NO, SO, WE, EA, F, C.\n", 2);
	else if (code == ERROR_EXTENSION)
		ft_putstr_fd("Error: textures have to be .xpm format\n", 2);
	else if (code == ERROR_T_OPEN)
		ft_putstr_fd("Error: texture cannot be open.\n", 2);
	else if (code == TOO_MUCH_PLAYER)
		ft_putstr_fd("Error: The game can only generate one player.\n", 2);
	else if (code == HIDDEN_FILE)
		ft_putstr_fd("Error: Hidden file.\n", 2);
	else if (code == COLOR)
		ft_putstr_fd("Error: colors should be between 0 and 250, \
format RGB.\n", 2);
	else if (code == NO_PLAYER)
		ft_putstr_fd("Error: No player in map.\n", 2);
	return (ERROR);
}

int	error_message(int code)
{
	if (code == ERROR_ARG)
		ft_putstr_fd("Error: please insert 2 arguments.\n", 2);
	else if (code == ERROR_CHAR)
		ft_putstr_fd("Error: Map is composed by 4 textures, 2 colors \
and a map composed with characters \" 01NSEW\" only.\n", 2);
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
