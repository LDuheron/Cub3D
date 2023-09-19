/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbernaze <cbernaze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 13:04:21 by lduheron          #+#    #+#             */
/*   Updated: 2023/09/19 13:45:39 by cbernaze         ###   ########.fr       */
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
# include "../mlx/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>

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

# define ERROR_ARG -1
# define ERROR_CHAR -2
# define ERROR_MALLOC -3
# define ERROR_FD -4

# define ERROR 0
# define SUCCESS 1

# define WIN_WIDTH 1280
# define WIN_HEIGHT 720

# define RED_PIXEL 0xFF0000
# define GREEN_PIXEL 0x00FF00
# define WHITE_PIXEL 0xFFFFFF
# define BLACK_PIXEL 0x000000

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
	char	**map;
	char	**texture;
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
// int		main(int argc, char **argv);

//////////////////////////////////////////////////////////////////
//																//
//                 	  	IN PARSING DIR   	  		            //
//																//
//////////////////////////////////////////////////////////////////

// Check_extension.c
int		check_char(t_parsing_data *parsing); /////////////////////////////////////////////////////////////////////////////////////
int		check_extension(char *file);

// Get_and_sort_map.c
int		retrieve_texture(t_parsing_data *parsing);
int		sort_input_file(t_parsing_data *parsing);
int		read_input_file(t_parsing_data *parsing, char *argv);

// Parsing.c
void	init_parsing_data(t_parsing_data *parsing);
int		parsing(char *map);

//////////////////////////////////////////////////////////////////
//																//
//																//
//                 	 	 IN UTILS DIR  	 		  	            //
//																//
//																//
//////////////////////////////////////////////////////////////////

// Error_management.c
int		error_message(int code);
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

// Ft_strdup.c
char	**ft_split(char *s, char c);

// Ft_strdup.c
char	*ft_strdup(char *src);

// Libft_utils.c // A RENOMMER
char	*ft_strchr(char *s, int c);
char	*ft_strjoin(char *s1, char *s2);
int		ft_strlen(char *str);

//////////////////////////////////////////////////////////////////

// Debug_function.c
void	free_tab(char **str);
void	print_tab(char **tab);

//////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////
//																//
//						  IN WINDOW DIR		      				//
//																//
//////////////////////////////////////////////////////////////////

// create_window.c
t_data	get_data_win(unsigned char **map);
void	img_pix_put(t_img *img, int x, int y, int color);
int		create_window(unsigned char **map);

// events.c
void	ft_exit(t_data *data);
int		close_win_key(int keysym, t_data *data);
int		close_win_mouse(t_data *data);
int		handle_no_event(void *data);

// draw_map.c
int		draw_map(t_data data);
void	draw_rect(t_data *data);

// GRAPH_LIB //

// ft_strlen.c
int		ft_unstrlen(unsigned char* str);
int		ft_unstrlen_plus(unsigned char** str);

// draw_utils.c
int		ft_abs(int nb);
void	set_line_coordinates(t_data *data, int ix, int iy, int status);
void	draw_line(t_data *data);
void	ft_dda(t_data *data, int ix, int iy, int status);
void	calculate_steps(int *steps, int dx, int dy);

#endif