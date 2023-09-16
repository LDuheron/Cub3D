/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduheron <lduheron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 13:04:21 by lduheron          #+#    #+#             */
/*   Updated: 2023/09/16 18:05:12 by lduheron         ###   ########.fr       */
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

// ERROR TEXTURE
# define ERROR_T_INCOMPLETE_PATH -1
# define ERROR_T_MISSING_PATH -2
# define ERROR_T_MISSING_TEXTURE -3
# define ERROR_T_WRONG_ORDER -4
# define ERROR_TEXTURE -5

# define ERROR_ARG -1
# define ERROR_CHAR -2
# define ERROR_MALLOC -3
# define ERROR_FD -4

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
	int		cpt_line;
}	t_parsing_data;

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

// Check_extension.c
int		check_extension(char *file);

// Is_something.c
int		is_space(char c);
int		is_empty_line(char *line);
int		is_valid_char(t_parsing_data *parsing);

// Parse_map.c

// Parse_texture.c
int		retrieve_texture(t_parsing_data *parsing);

// Parsing.c
void	init_parsing_data(t_parsing_data *parsing);
void	free_parsing_data(t_parsing_data *parsing);
int		parsing(char *map);

// Read_input.c
int		sort_input_file(t_parsing_data *parsing);
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
int		error_texture_message(int code);
void	ft_putstr_fd(char *s, int fd);

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

// Ft_strdup.c
char	**ft_split(char *s, char c);

// Ft_strdup.c
char	*ft_strdup(char *src);

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