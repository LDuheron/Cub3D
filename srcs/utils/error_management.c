/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_management.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduheron <lduheron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 15:04:48 by lduheron          #+#    #+#             */
/*   Updated: 2023/09/16 18:10:52 by lduheron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_putstr_fd(char *s, int fd)
{
	if (!s || !fd)
		return ;
	write(fd, s, ft_strlen(s));
}

int	error_texture_message(int code)
{
	if (code == ERROR_TEXTURE)
		ft_putstr_fd("Please enter the texture in the correct order and without spaces in front of it.\n", 2);
	else if (code == ERROR_T_INCOMPLETE_PATH)
		ft_putstr_fd("Error: incomplete path.\n", 2);
	else if (code == ERROR_T_MISSING_PATH)
		ft_putstr_fd("Error: missing path.\n", 2);
	else if (code == ERROR_T_MISSING_TEXTURE)
		ft_putstr_fd("Error: missing texture.\n", 2);
	else if (code == ERROR_T_WRONG_ORDER)
		ft_putstr_fd("Error: texture written in the wrong order.\n", 2);
	return (ERROR);
}

int	error_message(int code)
{
	if (code == ERROR_ARG)
		ft_putstr_fd("Error: Malloc failed.\n", 2);
	else if (code == ERROR_CHAR)
		ft_putstr_fd("Error: Map can only contain \" 01NSEW\".\n", 2);
	else if (code == ERROR_FD)
		ft_putstr_fd("Error: an error occured when opening fd.\n", 2);
	else if (code == ERROR_MALLOC)
		ft_putstr_fd("Error: please insert 2 arguments.\n", 2);
	return (ERROR);
}
