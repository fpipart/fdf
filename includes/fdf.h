/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpipart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/15 12:18:54 by fpipart           #+#    #+#             */
/*   Updated: 2017/03/28 17:48:20 by fpipart          ###   ########.fr       */
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
	float			zoom;
	int				offset_x;
	int				offset_y;
	int				**tab;
	int				z_max;
	int				z_min;
	int				bpp;
	int				s_l;
	int				endian;
	float			beta;
	float			theta;
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
	int				dx;
	int				dy;
	int				dir_x;
	int				dir_y;
	int				e;
	int				i;
	int				x;
	int				y;
	int				z;
	int				zi;
	int				zf;
	t_rgb			c;
}					t_line;

typedef struct		s_point
{
	float			x;
	float			y;
	float			z;
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
