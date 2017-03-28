/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpipart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/15 12:18:54 by fpipart           #+#    #+#             */
/*   Updated: 2017/03/28 11:54:23 by fpipart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef FDF_H
# define FDF_H

#include <fcntl.h>
#include "mlx.h"
#include "../libft/libft.h"
#include <math.h>

typedef struct		s_store
{
	void			*mlx;
	void			*win;
	void			*img;
	char			*data_img;
	int				larg;
	int				lg;
	int				dim;
	int				zoom;
	int				offset_x;
	int				offset_y;
	int				**tab;
	int				z_max;
	int				z_min;
	int				bpp;
	int				s_l;
	int				endian;
	float			theta;
	float			alpha;
	float			beta;
}					t_store;

typedef struct		s_rgb
{
	unsigned char	r1;
	unsigned char	g1;
	unsigned char	b1;
	unsigned char	r2;
	unsigned char	g2;
	unsigned char	b2;
}					t_rgb;

typedef	struct		s_line
{
	double			dx;
	double			dy;
	double			dir_x;
	double			dir_y;
	double			e;
	int				i;
	double			x;
	double			y;
	t_rgb			c;
}					t_line;

typedef struct		s_point
{
	double			x;
	double			y;
	double			z;
}					t_point;

/*
**		read_map.c
*/
int				read_map(char **argv, t_store *store);
/*
**		error.c
*/
int				error(char *error);
/*
**		print_map.c
*/
//void			print_map(t_store store);
void			print_line(t_rgb *clr, t_store *s, t_point p1, t_point p2);
void			print(t_store *store);
void			put_pixel(t_store *store, int x, int y, t_rgb color);
void			print_vline(int i, int j, t_store *s, t_rgb *color);
void			print_hline(int i, int j, t_store *s, t_rgb *color);
/*
**		bresenham.c
*/
void			print_line(t_rgb *c, t_store *s, t_point p1, t_point p2);

# endif
