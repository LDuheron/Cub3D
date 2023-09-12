/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduheron <lduheron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 13:04:21 by lduheron          #+#    #+#             */
/*   Updated: 2023/09/12 14:34:00 by lduheron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>
# include <sys/stat.h>
# include <fcntl.h>

//////////////////////////////////////////////////////////////////
//																//
//																//
//							DEFINE								//
//																//
//																//
//////////////////////////////////////////////////////////////////

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
void	init_parsing_data(t_parsing_data parsing);
int		get_map(t_parsing_data parsing, char *argv);
int		parsing(char *map);


char	**ft_split(char *s, char c)

//////////////////////////////////////////////////////////////////
//																//
//                 	  	IN LIBFT DIR  	 	  		            //
//																//
//////////////////////////////////////////////////////////////////

// ft_strdup.c
char	**ft_split(char *s, char c);

// ft_strjoin.c
char	*ft_strdup(char *src);

#endif