/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unstrlen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbernaze <cbernaze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 11:54:43 by cbernaze          #+#    #+#             */
/*   Updated: 2023/09/25 15:41:32 by cbernaze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_unstrlen(unsigned char* str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_unstrlen_plus(unsigned char** str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}