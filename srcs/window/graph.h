/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbernaze <cbernaze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 13:45:21 by cbernaze          #+#    #+#             */
/*   Updated: 2023/09/20 17:32:24 by cbernaze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRAPH_H
# define GRAPH_H

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
# include "../../mlx/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <math.h>

# define ERROR 0
# define SUCCESS 1

# define WIN_WIDTH 1280
# define WIN_HEIGHT 720

# define RED_PIXEL 0x8A0B0B
# define BLUE_PIXEL 0x155DDB
# define GREEN_PIXEL 0x77FF00
# define WHITE_PIXEL 0xEBE9CD
# define BLACK_PIXEL 0x000000

# define	X_SIDE 0
# define	Y_SIDE 1

//////////////////////////////////////////////////////////////////
//																//
//							STRUCTURES							//
//																//
//////////////////////////////////////////////////////////////////

typedef struct s_img
{
	void	*ptr;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}			t_img;

typedef struct s_player
{
	double	posX;
	double	posY;
}			t_player;

typedef struct s_dda
{
	float	x1;
	float	y1;
	float	x2;
	float	y2;
}	t_dda;

typedef struct s_raycasting
{
	int		xMax;
	double	posX; // posX & posY are the player vector
	double	posY;
	double	dirX; // dirX & dirY are the direction vector
	double	dirY;
	double	planeX; //planeX & planeY are the camera plane
	double	planeY;
	double	time;
	double	oldTime;
	double	cameraX;
	double	rayDirX;
	double	rayDirY;
	//
	int		mapX;
	int		mapY;
	double	sideDistX;
	double	sideDistY;
	double	deltaDistX;
	double	deltaDistY;
	double	perpWallDist;
	int		stepX;
	int		stepY;
	int		hit;
	int		side;
	//
	int		lineHeight;
	int		drawStart;
	int		drawEnd;
}			t_raycasting;

typedef struct s_data
{
	void			*mlx_ptr;
	void			*win_ptr;
	unsigned char	**map;
	t_img			img;
	t_dda			line;
	t_player		player;
}					t_data;

//////////////////////////////////////////////////////////////////
//																//
//							STRUCTURES							//
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

// ft_strlen.c
int		ft_unstrlen(unsigned char* str);
int		ft_unstrlen_plus(unsigned char** str);

// draw_utils.c
int		ft_abs(int nb);
void	set_line_coordinates(t_data *data, int ix, int iy);
void	draw_line(t_data *data, int color);
void	ft_dda(t_data *data, int ix, int iy, int color);
void	calculate_steps(int *steps, int dx, int dy);

#endif