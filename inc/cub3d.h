/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduheron <lduheron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 13:04:21 by lduheron          #+#    #+#             */
/*   Updated: 2023/09/21 16:58:06 by lduheron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include <string.h>
# include <stddef.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>
# include <stdint.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

//////////////////////////////////////////////////////////////////
//																//
//																//
//							DEFINE								//
//																//
//																//
//////////////////////////////////////////////////////////////////

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# define N 0
# define S 1
# define E 2
# define W 3 

// FIRST READING STATUS
# define TEXTURE -12
# define EMPTY_L -11
# define MAP -10
# define TOO_BIG -9

# define MAP_OPEN -8
# define EMPTY_MAP -7

# define M_TEXTURE -11
# define EMPTY_LINE_IN_MAP -10
// ERROR TEXTURE

# define ERROR_EXTENSION -9

# define ERROR_TEXTURE -5
# define ERROR_T_OPEN -6
# define ERROR_MAP -7
# define TOO_MUCH_PLAYER -3

# define ERROR_ARG -1
# define ERROR_CHAR -2
# define ERROR_CLOSE -3
# define ERROR_MALLOC -4
# define ERROR_FD -5

# define ERROR 0
# define SUCCESS 1

# define NOT_EMPTY 0
# define EMPTY 1

//////////////////////////////////////////////////////////////////
//																//
//																//
//							STRUCTURES							//
//																//
//																//
//////////////////////////////////////////////////////////////////

typedef struct s_parsing_data
{
	char	**file;
	char	**texture;
	char	**map;
	int		pos_type;
	int		pos_p_x;
	int		pos_p_y;
	int		line_last_texture;
}	t_parsing_data;

typedef struct s_parsing_first_r
{
	int		belong_to_map;
	int		cpt_texture;
	int		fd;
	int		size;
	char	*line;
}	t_parsing_first_r;

//////////////////////////////////////////////////////////////////
//																//
//																//
//							PROTOTYPES 							//
//																//
//																//
//////////////////////////////////////////////////////////////////

// Main.c
int		main(int argc, char **argv);

//////////////////////////////////////////////////////////////////
//																//
//                 	  	IN PARSING DIR   	  		            //
//																//
//////////////////////////////////////////////////////////////////

// First_reading.c
int		first_reading(char *argv);

// Is_surrounded_by_walls.c
int		is_surrounded_by_walls(t_parsing_data *parsing);

// is_valid.c
int		is_valid_char(char *line);
int		is_valid_extension(char *file, char *format);

// Parse_map.c
int		map_management(t_parsing_data *data);

// Parse_texture.c
int		retrieve_texture(t_parsing_data *parsing);

// Parsing.c
void	free_parsing_data(t_parsing_data *parsing);
int		parsing(t_parsing_data *parsing, char *argv);

// Read_input_file.c
int		read_input_file(t_parsing_data *parsing, char *argv);

//////////////////////////////////////////////////////////////////
//																//
//																//
//                 	 	 IN UTILS DIR  	 		  	            //
//																//
//																//
//////////////////////////////////////////////////////////////////

// Error_management.c
int		error_message(int code);
int		error_message_first_reading(int code);
int		error_parsing_message(int code);
void	ft_putstr_fd(char *s, int fd);

// Is_something.c
int		ft_isalpha(int c);
int		is_space(char c);
int		is_empty_line(char *line);

//////////////////////////////////////////////////////////////////
//																//
//                 	 	 	IN GNL DIR  	 	  	            //
//																//
//////////////////////////////////////////////////////////////////

// Get_next_line.c
char	*get_next_line(int fd);
char	*cut_after_end_line(char *remains, int end_line);
char	*cut_before_end_line(char *remains, int end_line);
char	*ft_read(int fd, char *remains);

//////////////////////////////////////////////////////////////////
//																//
//						  IN LIBFT DIR		      				//
//																//
//////////////////////////////////////////////////////////////////

// Ft_calloc.c
void	*ft_calloc(size_t nmemb, size_t size);

// Ft_split.c
char	**ft_split(char *s, char c);

// Ft_strdup.c
char	*ft_strdup(char *src);

// Ft_substr.c
char	*ft_substr(char *s, unsigned int start, size_t len);

// Libft_utils.c
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strchr(char *s, int c);
char	*ft_strjoin(char *s1, char *s2);
int		ft_strlen(char *str);

//////////////////////////////////////////////////////////////////

// Debug_function.c
void	free_tab(char **str);
void	free_char_tab(char **tab);
void	print_tab(char **tab);
void	print_int(int **tab);

//////////////////////////////////////////////////////////////////

#endif