/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekoljone <ekoljone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 15:24:40 by ekoljone          #+#    #+#             */
/*   Updated: 2023/04/07 12:28:28 by ekoljone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# define MALLOC_ERROR "Malloc failed\n"
# define OPEN_ERROR "Open failed\n"
# define INVALID_MAP "Invalid map\n"
# define MLX_ERROR "MLX Initialization failed\n"
# include <math.h>
# include "minilibx_macos/mlx.h"
# include <fcntl.h>
# include "libft/libft.h"

/*
**	necessary data for minilibx
*/

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	void	*mlx;
	void	*mlx_win;
}				t_data;

/*
**	struct for vectors
*/

typedef struct s_vec
{
	int	x;
	int	y;
	int	z;
	int	color;
}				t_vec;

/*
**	map struct that countains 2d map array and 2d
**	2d color array
*/

typedef struct s_map
{
	int	**map_arr;
	int	**clr_arr;
	int	width;
	int	height;
	int	allocated_rows;
}					t_map;

/*
**	struct for bresenham's line drawing algo
*/

typedef struct s_bres
{
	int	dx;
	int	dy;
	int	sx;
	int	sy;
	int	error[2];
}				t_bres;

/*
**	camera struct to manipulate vectors
*/

typedef struct s_camera
{
	int					proj;
	int					zoom;
	double				alpha;
	double				beta;
	double				gamma;
	float				z_divisor;
	int					x_offset;
	int					y_offset;
}				t_camera;

/*
**	struct that points to all structs
*/

typedef struct s_fdf
{
	t_map		map;
	t_camera	*camera;
	t_data		img;
	t_bres		bres;
}				t_fdf;

/*
**	draw
*/
void	draw(t_fdf *fdf);
void	plotline(t_fdf *fdf, t_vec v1, t_vec v2);
void	print_instructions(t_fdf *fdf);
int		ft_abs(int num);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
/*
**	utils
*/
int		ft_is_number(char *s);
t_vec	new_vec(t_fdf *fdf, int x, int y);
/*
**	rotate
*/
void	rotate_z(int *x, int *y, double gamma);
void	rotate_x(int *y, int *z, double alpha);
void	rotate_y(int *x, int *z, double beta);
/*	projection	*/
t_vec	project(t_fdf *fdf, t_vec vec);
void	iso_projection(int *x, int *y, int z);
void	cabinet_projection(int *x, int *y, int z);
/*
**	controls
*/
int		key_handle(int keycode, t_fdf *fdf);
void	controls(t_fdf *fdf);
void	rotate(t_fdf *fdf, int keycode);
void	flatten(t_fdf *fdf, int keycode);
void	change_proj(t_fdf *fdf);
void	move_picture(t_fdf *fdf, int keycode);
void	zoom_picture(t_fdf *fdf, int keycode);
int		close_window(t_fdf *fdf);
/*
**	parsing
*/
void	read_map(char *arg, t_fdf *fdf);
int		get_height(int fd, char *row);
void	get_size(int fd, t_fdf *fdf);
void	fill_arrays(t_fdf *fdf, int fd);
void	fill(t_fdf *fdf, char **info);
/*
**	free
*/
void	free_everything(t_fdf *fdf);
void	free_arrays(t_map map);
void	free_string_array(char **args);
void	error_exit(char *s, t_fdf *fdf);
/*
**	init
*/
void	init_mlx(t_fdf *fdf);
void	init_camera(t_fdf *fdf);
t_fdf	*init_fdf(void);
/*
**	ft_atoi_base
*/
int		atoi_b16(char *string);
int		hexa_strlen(char *string);
int		convert_atof(char atof);

#endif