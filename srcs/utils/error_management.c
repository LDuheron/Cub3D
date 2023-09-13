/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_management.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduheron <lduheron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 15:04:48 by lduheron          #+#    #+#             */
/*   Updated: 2023/09/13 18:30:55 by lduheron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_putstr_fd(char *s, int fd)
{
	if (!s || !fd)
		return ;
	write(fd, s, ft_strlen(s));
}

int	error_message(int code)
{
	if (code == ERROR_ARG)
		ft_putstr_fd("Error: Malloc failed.\n", 2);
	if (code == ERROR_CHAR)
		ft_putstr_fd("Error: Map can only contain \" 01PSNW\".\n", 2);
	else if (code == ERROR_FD)
		ft_putstr_fd("Error: an error occured when opening fd.\n", 2);
	else if (code == ERROR_MALLOC)
		ft_putstr_fd("Error: please insert 2 arguments.\n", 2);
	return (ERROR);
}
