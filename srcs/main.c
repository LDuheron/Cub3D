/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbernaze <cbernaze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 13:05:50 by lduheron          #+#    #+#             */
/*   Updated: 2023/10/02 16:07:10 by cbernaze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_parsing_data	parsing_data;

	if (argc == 2)
	{
		if (parsing(&parsing_data, argv[1]) == SUCCESS)
		{
			printf("Great map !\n");
			create_window(parsing_data);
		}
		free_parsing_data(&parsing_data);
	}
	else
		error_message(ERROR_ARG);
	return (0);
}

// mlx_get_addr -> recuperer et stocker
//  dans une variable les pixels de couleurs.