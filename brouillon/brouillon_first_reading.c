
// int	check_map_empty(t_parsing_data *parsing, char *argv)
// {
// 	char	*line;
// 	int		i;
// 	int		fd;

// 	i = 0;
// 	fd = open(argv, O_RDONLY);
// 	if (fd == -1)
// 		return (error_message(ERROR_FD));
// 	line = get_next_line(fd);
// 	while (i <= parsing->line_last_texture)
// 	{
// 		free(line);
// 		line = get_next_line(fd);
// 		i++;
// 	}
// 	while (is_empty_line(line) == EMPTY)
// 	{
// 		free(line);
// 		line = get_next_line(fd);
// 	}
// 	while (is_empty_line(line) != EMPTY)
// 	{
// 		free(line);
// 		line = get_next_line(fd); // lost of 4bytes when ERROR
// 	}
// 	if (line != NULL)
// 	{
// 		while (line)
// 		{
// 			free(line);
// 			line = get_next_line(fd);
// 		}
// 		free(line);
// 		close(fd);
// 		return (error_parsing_message(ERROR_MAP));
// 	}
// 	free(line);
// 	return (SUCCESS);
// }

// int	begin_map(t_parsing_data *parsing, char *argv)
// {
// 	char	*line;
// 	int		fd;
// 	int		i;

// 	i = 0;
// 	fd = open(argv, O_RDONLY);
// 	if (fd == -1)
// 		return (error_message(ERROR_FD));
// 	line = get_next_line(fd);
// 	while (i <= parsing->line_last_texture)
// 	{
// 		free(line);
// 		line = get_next_line(fd);
// 		i++;
// 	}
// 	while (is_empty_line(line) == EMPTY)
// 	{
// 		i++;
// 		free(line);
// 		line = get_next_line(fd);
// 	}
// 	while (is_empty_line(line) != EMPTY)
// 	{
// 		free(line);
// 		line = get_next_line(fd);
// 	}
// 	while (line)
// 	{
// 		free(line);
// 		line = get_next_line(fd);
// 	}
// 	free(line);
// 	close(fd);
// 	return (i);
// }

// int	check_map_empty(t_parsing_data *parsing, char *argv)
// {
// 	char	*line;
// 	int		fd;
// 	int		i;
// 	int		start;

// 	i = 0;
// 	start = begin_map(parsing, argv);
// 	fd = open(argv, O_RDONLY);
// 	if (fd == -1)
// 		return (error_message(ERROR_FD));
// 	line = get_next_line(fd);
// 	while (i <= start)
// 	{
// 		free(line);
// 		line = get_next_line(fd);
// 		i++;
// 	}
// 	if (line != NULL)
// 	{
// 		while (line)
// 		{
// 			free(line);
// 			line = get_next_line(fd);
// 		}
// 		free(line);
// 		close(fd);
// 		return (error_parsing_message(ERROR_MAP));
// 	}
// 	free(line);
// 	return (SUCCESS);
// }