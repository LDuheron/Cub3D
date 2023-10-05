/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbernaze <cbernaze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 13:04:21 by lduheron          #+#    #+#             */
/*   Updated: 2023/10/05 12:12:29 by cbernaze         ###   ########.fr       */
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
# include <math.h>

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

// ERROR CODE
# define ERROR_ARG -1
# define ERROR_CHAR -2
# define ERROR_CLOSE -3
# define ERROR_MALLOC -4
# define ERROR_FD -5

# define ERROR 0
# define SUCCESS 1

// ERROR CODE PARSING
# define ERROR_EXTENSION -18

# define TOO_BIG -10
# define EMPTY_MAP -11
# define M_TEXTURE -12
# define MAP_OPEN -13
# define EMPTY_LINE_IN_MAP -14

# define COLOR -15
# define ERROR_TEXTURE -16
# define ERROR_T_OPEN -17
# define HIDDEN_FILE -18

# define NO_PLAYER -19
# define TOO_MUCH_PLAYER -20

// RAYCASTING
# define WIN_WIDTH 1280
# define WIN_HEIGHT 720

# define RED_PIXEL 0x8A0B0B
# define BLUE_PIXEL 0x155DDB
# define GREEN_PIXEL 0x77FF00
# define WHITE_PIXEL 0xEBE9CD
# define BLACK_PIXEL 0x000000
# define FLOOR 0xE66F6F
# define CEILING 0xF59090
# define CARPET 0xE34C4C

# define NOT_EMPTY 0
# define EMPTY 1

# define X_SIDE 0
# define Y_SIDE 1

# define MOVE_SPEED 0.060
# define ROT_SPEED 0.0175

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

typedef struct s_parsing_initial_r
{
	int		belong_to_map;
	int		cpt_texture;
	int		fd;
	int		size;
	char	*line;
}	t_parsing_initial_r;

// graph structures

typedef struct s_img
{
	void	*ptr;
	char	*addr;
	int		width;
	int		height;
	int		bpp;
	int		line_len;
	int		endian;
}			t_img;

typedef struct s_raycasting
{
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
	double	camera_x;
	double	ray_dir_x;
	double	ray_dir_y;
	int		map_x;
	int		map_y;
	double	side_dist_x;
	double	side_dist_y;
	double	delta_dist_x;
	double	delta_dist_y;
	double	perp_wall_dist;
	int		step_x;
	int		step_y;
	int		hit;
	int		side;
	int		line_height;
	int		draw_start;
	int		draw_end;
}			t_raycasting;

typedef struct s_ray_utils
{
	int		key_w;
	int		key_s;
	int		key_a;
	int		key_d;
	int		key_left;
	int		key_right;
	double	rot_speed;
	double	move_speed;
}		t_ray_utils;

typedef struct s_graph
{
	void			*mlx_ptr;
	void			*win_ptr;
	char			**map;
	t_img			img;
	t_img			tx[5];
	int				color[2];
	t_raycasting	ray;
	t_parsing_data	pars;
	t_ray_utils		utils;
}					t_graph;

typedef struct s_texture
{
	double	tex_pos;
	double	wall_x;
	double	step;
	char	*color;
	int		tex_x;
	int		tex_y;
}			t_texture;

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

// Colors.c
int				is_valid_color(char *line);

// initial_reading.c
int				initial_reading(char *argv);

// Is_surrounded_by_walls.c
int				is_surrounded_by_walls(t_parsing_data *parsing);

// is_valid.c
int				is_valid_char(char *line);
int				is_valid_extension(char *file, char *format);
int				is_valid_path(char *path);

// Parse_map.c
int				map_management(t_parsing_data *data);

// Parse_texture.c
int				retrieve_texture(t_parsing_data *parsing);

// Parsing.c
void			free_parsing_data(t_parsing_data *parsing);
int				parsing(t_parsing_data *parsing, char *argv);

// store_input_file.c
int				store_input_file(t_parsing_data *parsing, char *argv);

//////////////////////////////////////////////////////////////////
//																//
//																//
//                 	 	 IN UTILS DIR  	 		  	            //
//																//
//																//
//////////////////////////////////////////////////////////////////

// Error_management.c
int				error_message(int code);
int				error_message_initial_reading(int code);
int				error_parsing_message(int code);

// Is_something.c
int				ft_isalpha(int c);
int				ft_isdigit(int c);
int				is_space(char c);
int				is_empty_line(char *line);

//////////////////////////////////////////////////////////////////
//																//
//                 	 	 	IN GNL DIR  	 	  	            //
//																//
//////////////////////////////////////////////////////////////////

// Get_next_line.c
char			*get_next_line(int fd);
char			*cut_after_end_line(char *remains, int end_line);
char			*cut_before_end_line(char *remains, int end_line);
char			*ft_read(int fd, char *remains);

//////////////////////////////////////////////////////////////////
//																//
//						  IN LIBFT DIR		      				//
//																//
//////////////////////////////////////////////////////////////////

// Ft_atoi.c
int				ft_atoi(const char *str);

// Ft_calloc.c
void			*ft_calloc(size_t nmemb, size_t size);

// Ft_split.c
char			**ft_split(char *s, char c);

// Ft_strdup.c
char			*ft_strdup(char *src);

// Ft_substr.c
char			*ft_substr(char *s, unsigned int start, size_t len);

// Libft_utils.c
int				ft_strncmp(const char *s1, const char *s2, size_t n);
char			*ft_strchr(char *s, int c);
char			*ft_strjoin(char *s1, char *s2);
int				ft_strlen(char *str);

//////////////////////////////////////////////////////////////////

// Debug_function.c
void			free_tab(char **str);
void			free_char_tab(char **tab);
void			print_tab(char **tab);
void			print_int(int **tab);

//////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////
//																//
//							    GRAPH							//
//																//
//////////////////////////////////////////////////////////////////

// create_window.c
void			init_data_utils(t_graph *data);
int				init_texture_addrs(t_graph *data);
int				init_textures(t_graph *data);
t_graph			get_data_win(t_parsing_data parsing);
int				create_window(t_parsing_data parsing);

// events.c
void			ft_exit(t_graph *data);
int				key_release(int keysym, t_graph *data);
int				key_press(int keysym, t_graph *data);
int				close_win_mouse(t_graph *data);
int				handle_no_event(void *data);

// moves.c
void			set_moves(t_graph *data, double *vel_x, double *vel_y);
void			moves(t_graph *data);
void			rotations_right(double old_dir_x, double old_plane_x,
					t_graph *data);
int				move_it(t_graph *data);

// draw_utils.c
void			img_pix_put(t_img *img, int x, int y, int color);
void			free_textures(t_graph *data);
int				rgb_to_hex(char **color);
void			init_colors(t_graph *data);
void			draw_background(t_graph *data);

// ray_utils.c
double			ft_abs(double nb);
void			init_data_rc2(t_parsing_data parsing, t_raycasting *ray);
t_raycasting	init_data_rc(t_parsing_data parsing);
void			init_tx2(t_graph data, t_img *tex);
void			init_tx(t_texture *tx, t_graph data, t_img *tex);

// raycasting.c
t_raycasting	init_data_rc(t_parsing_data parsing);
void			nb_steps_n_side_dst(t_raycasting *ray);
void			ray_dda(t_raycasting *ray, char **map);
void			ft_raycasting(t_graph *data);

#endif
