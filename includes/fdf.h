/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apintaur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 10:24:18 by apintaur          #+#    #+#             */
/*   Updated: 2025/06/05 19:56:01 by apintaur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# ifndef WIDTH
#  define WIDTH			1920
# endif

# ifndef HEIGHT
#  define HEIGHT		1080
# endif

# define M_PI			3.14159265358979323846
# define LIGHT			0.1
# define SCALE			40.9f
# define ISOMETRIC		1
# define PARALLEL		2

# include <math.h>
# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <errno.h>
# include <X11/Xlib.h>
# include "libft.h"
# include "ft_printf.h"
# include "get_next_line.h"
# include "../mlx_linux/mlx.h"
# include "../mlx_linux/mlx_int.h"
# include "../includes/colors.h"

typedef struct t_utils
{
	int	x;
	int	y;
	int	z;
}	t_utils;

typedef struct s_mm
{
	int		x;
	int		y;
	float	z;
}	t_mm;

typedef struct s_bsm
{
	int		dir;
	int		dx;
	int		dy;
	float	p;
}	t_bsm;

typedef struct s_color
{
	t_cc	t;
	t_cc	r;
	t_cc	g;
	t_cc	b;
}	t_color;

typedef struct s_point
{
	float	x;
	float	y;
	float	z;
	t_cc	color;
}	t_point;

typedef struct s_window
{
	void	*p;
	t_cc	color;
}	t_window;

typedef struct s_image
{
	void	*p;
	char	*addr;
	int		bits_per_pixel;
	int		lenght;
	int		endian;
	t_cc	color;
}	t_image;

typedef struct s_picture
{
	t_window	win;
	t_image		img;
}	t_picture;

typedef struct s_matrix
{
	t_point	*point;
	t_mm	max;
	t_mm	min;
	int		width;
	int		height;
}	t_matrix;

typedef struct s_op
{
	int			projection;
	int			keycode;
	float		height;
	float		scale;
	t_point		rotate;
	t_point		translate;
}	t_op;

typedef struct s_mlx
{
	void		*mlx_p;
	t_matrix	m;
	t_picture	pic;
	t_op		op;
}	t_mlx;

//Atof_base function [atof_base.c]
float	ft_atof_base(t_mlx *data, const char *s);

//Bresenham's algorithm [bresenham_algorithm.c]
void	ft_bresenham_plot(t_mlx *data, t_point m0, t_point p1);

//Character utility functions [char_utility.c]
int		ft_isspace(char c);
int		ft_ishexa(char c);
int		ft_isup(char c);
int		ft_islw(char c);

//I/O management functions [io_manage.c]
void	ft_file_open(int *fd, char *filename);
void	ft_file_close(int fd);
char	*ft_file_getname(t_mlx *data, char *s);

//Map management functions [map.c]
void	ft_map_firstshift(t_mlx *data);
int		ft_map_plot(t_mlx *data);

//Matrix management functions [matrix.c]
void	ft_matrix_create_ff(t_mlx *data, char *filename);
void	ft_matrix_destroy_ff(t_mlx *data);
void	ft_matrix_extrema_xy(t_mlx *data);
void	ft_matrix_extrema_z(t_mlx *data);

//Mlx management functions [mlx.c]
void	mymlx_pixel_put(t_mlx *data, int x, int y, int color);
int		mymlx_switch_keycode(int keycode, t_mlx *data);
int		mymlx_render(t_mlx *data);

//Mlx management functions utility [mlx_utils.c]
void	mymlx_init(t_mlx *data, char *filename);
void	mymlx_init_local(t_mlx *data);
int		mymlx_destroy(t_mlx *data);
int		mymlx_exit(t_mlx *data);

//Point management functions [point.c]
void	ft_point_rotate_x(t_point *p, float angle);
void	ft_point_rotate_y(t_point *p, float angle);
void	ft_point_rotate_z(t_point *p, float angle);
void	ft_point_translate(t_point *p, t_point factor);
void	ft_point_scale(t_point *p, float height, float scale);

//Point management functions utility [point_utils.c]
t_point	ft_point_get(t_mlx *data, int x, int y);
t_point	ft_point_getznorm(t_mlx *data, float x, float y);
float	ft_point_dotscal(t_point p0, t_point p1);
int		ft_point_isvalid(t_mlx *data, int x, int y);

//Check functions [check.c]
void	ft_check_valid_file(t_mlx *data, char *filename);
void	ft_check_valid_mlx(t_mlx *data, const char *signature);
void	ft_check_valid_matrix(t_mlx *data, const char *signature);
//Check additional [check_add.c]
void	ft_check_parameters(t_mlx *data, const char *signature);
void	ft_check_valid_pointer(t_mlx *data, void *p, const char *signature);
void	ft_check_valid_input(int argc, char *argv[], const char *signature);

//Standard projection functions [check_utility.c]
void	ft_std_isometric(t_mlx *data, t_point *p0, t_point *p1);
#endif
