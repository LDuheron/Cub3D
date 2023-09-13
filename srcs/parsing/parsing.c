/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduheron <lduheron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 13:19:22 by lduheron          #+#    #+#             */
/*   Updated: 2023/09/13 12:27:20 by lduheron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "cub3d.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (s1[i] && s2[i] && s1[i] == s2[i] && i < (n - 1))
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

// A OPTI AVEC STRCMP
int	check_extension(char *file)
{
	int	len;

	len = ft_strlen(file) - 1;
	if (len < 3)
		return (0);
	// if (ft_strcmp())
	if (file[len - 3] == '.')
	{
		if (file[len - 2] == 'c')
		{
			if (file[len - 1] == 'u')
			{
				if (file[len] == 'b')
					return (1);
			}
		}
	}
	return (0);
}

void	init_parsing_data(t_parsing_data *parsing)
{
	parsing->map = NULL;
	parsing->cpt_line = 0;
}

// GET_MAP : This function reads the input and stores
// it in the parsing structure under the variable map.

int	get_map(t_parsing_data *parsing, char *argv)
{
	char	*map_tmp;
	char	*line;
	char	*backup;
	int		fd;

	fd = open(argv, O_RDONLY);
	if (fd == -1)
		return (ERROR);
	map_tmp = ft_strdup("");
	line = get_next_line(fd);
	while (line)
	{
		backup = map_tmp;
		map_tmp = ft_strjoin(backup, line);
		free(line);
		line = get_next_line(fd);
	}
	parsing->map = ft_split(map_tmp, '\n');
	free(map_tmp);
	close(fd);
	return (SUCCESS);
}

// PARSING : The parsing function retrieves the argument given 
// by the user, copies it in the parsing_data structure through
// the get_map function then check if the map is valid.

int	parsing(char *argv)
{
	t_parsing_data	parsing;

	init_parsing_data(&parsing);
	if (get_map(&parsing, argv) == SUCCESS)
	{
		print_tab(parsing.map);
		return (SUCCESS);
	}
	return (ERROR);
}
