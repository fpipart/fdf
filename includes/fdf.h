/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpipart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/15 12:18:54 by fpipart           #+#    #+#             */
/*   Updated: 2017/03/24 16:49:32 by fpipart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef FDF_H
# define FDF_H

#include <fcntl.h>
#include "mlx.h"
#include "../libft/libft.h"
#include <math.h>

#define H 1000
#define W 1000

#define Z 10

#define ESC 53

typedef struct		s_store
{
	void			*mlx;
	void			*win;
	void			*img;
	char			*data_img;
	int				larg;
	int				lg;
	int				**tab;
	int				bpp;
	int				s_l;
	int				endian;
	float			theta;
}					t_store;

typedef struct		s_rgb
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
}					t_rgb;

typedef struct	s_point
{
	int			x;
	int			y;
	int			z;
}				t_point;

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
//void			print_line(t_point p1, t_point p2, t_store store);
void			print(t_store *store);
//void			put_pixel(t_store *store, int x, int y, t_rgb color);

# endif
