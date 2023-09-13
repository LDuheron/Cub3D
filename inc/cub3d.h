/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduheron <lduheron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 13:04:21 by lduheron          #+#    #+#             */
/*   Updated: 2023/09/13 12:25:33 by lduheron         ###   ########.fr       */
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

# define ERROR_MALLOC -3
# define ERROR_SYNTAX -2
# define ERROR_FD -1
# define ERROR 0
# define SUCCESS 1

//////////////////////////////////////////////////////////////////
//																//
//																//
//							STRUCTURES							//
//																//
//																//
//////////////////////////////////////////////////////////////////

typedef struct s_parsing_data
{
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

// Parsing.c
void	init_parsing_data(t_parsing_data *parsing);
int		get_map(t_parsing_data *parsing, char *argv);
int		parsing(char *map);


//////////////////////////////////////////////////////////////////
//																//
//                 	 	 	IN GNL DIR  	 	  	            //
//																//
//////////////////////////////////////////////////////////////////

char	*get_next_line(int fd);
char	*cut_after_end_line(char *remains, int end_line);
char	*cut_before_end_line(char *remains, int end_line);
char	*ft_read(int fd, char *remains);


//////////////////////////////////////////////////////////////////
//																//
//						  IN LIBFT DIR		      				//
//																//
//////////////////////////////////////////////////////////////////

// ft_strdup.c
char	**ft_split(char *s, char c);

// ft_strdup.c
char	*ft_strdup(char *src);

// libft_utils.c // A RENOMMER
char	*ft_strchr(char *s, int c);
char	*ft_strjoin(char *s1, char *s2);
int		ft_strlen(char *str);



/// Debug_function.c
void	print_tab(char **tab);

#endif