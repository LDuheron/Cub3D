/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduheron <lduheron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 13:05:50 by lduheron          #+#    #+#             */
/*   Updated: 2023/09/25 16:23:13 by lduheron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_parsing_data	parsing_data;

	if (argc == 2)
	{
		if (parsing(&parsing_data, argv[1]) == SUCCESS)
			printf("Great map !\n");
		// create_window((unsigned char**)parsing_data.map);
		free_parsing_data(&parsing_data);
	}
	else
		error_message(ERROR_ARG);
	return (0);
}
