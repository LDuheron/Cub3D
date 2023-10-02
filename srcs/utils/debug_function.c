/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_function.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduheron <lduheron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 12:20:36 by lduheron          #+#    #+#             */
/*   Updated: 2023/09/16 17:06:09 by lduheron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_char_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	if (tab)
	{
		free(tab);
		tab = NULL;
	}
}

void	free_tab(char **str)
{
	int	i;

	if (!str)
		return ;
	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
	str = NULL;
}

// static void	free_int_tab(int **tab)
// {
// 	int	i;

// 	i = 0;
// 	while (tab && tab[i])
// 	{
// 		if (tab[i])
// 		{
// 			free(tab[i]);
// 			tab[i] = NULL;
// 		}
// 		i++;
// 	}
// 	if (tab[i])
// 	{
// 		free(tab[i]);
// 		tab = NULL;
// 	}
// 	if (tab)
// 	{
// 		free(tab);
// 		tab = NULL;
// 	}
// }

void	print_tab(char **str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str && str[i])
	{
		j = 0;
		while (str && str[i] && str[i][j])
		{
			printf("%c", str[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}

void	print_int_tab(int **str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str && str[i])
	{
		j = 0;
		while (str && str[i] && str[i][j])
		{
			printf("%c", str[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}
