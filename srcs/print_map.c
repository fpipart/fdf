/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpipart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/15 17:10:48 by fpipart           #+#    #+#             */
/*   Updated: 2017/03/28 11:48:46 by fpipart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
//
#include <stdio.h>

void	put_pixel(t_store *s, int x, int y, t_rgb c)
{
	if (x >= 0 && y > 0 && y < s->dim  && x < s->dim)
	{
		s->data_img = mlx_get_data_addr(s->img, &(s->bpp),
				&(s->s_l), &(s->endian));
		s->data_img[x * s->bpp / 8 + y * s->s_l] = c.b1;
		s->data_img[x * s->bpp / 8 + 1 + y * s->s_l] = c.g1;
		s->data_img[x * s->bpp / 8 + 2 + y * s->s_l] = c.r1;
	}
}
/*
void	print_line(t_rgb *color, t_store *s, t_point p1, t_point p2)
{
	int		dx;
	int		dy;
	t_line	l;

	dy = abs(p2.y - p1.y);
	dx = abs(p2.x - p1.x);
	l.dir_x = (p1.x < p2.x ? 1 : -1);
	l.dir_y = (p1.y < p2.y ? 1 : -1);
	l.e = (dx > dy ? dx / 2 : - dy / 2);
	put_pixel(s, p1.x, p1.y, *color);
	while ((p1.x != p2.x || p1.y != p2.y))
	{
		l.ei = l.e;
		if (l.ei > -dx)
		{
			l.e = l.e - dy;
			p1.x = p1.x + l.dir_x;
		}
		if (l.ei < dy)
		{
			l.e = l.e + dx;
			p1.y = p1.y + l.dir_y;
		}
		put_pixel(s, p1.x, p1.y, *color);
	}
}
*/
void	print_vline(int i, int j, t_store *s, t_rgb *color)
{
	t_point p1;
	t_point p2;
	float	sbeta;
	float	cbeta;
	
	sbeta = sin(s->beta) / sin(M_PI / 4);
	cbeta = cos(s->beta) / cos(M_PI / 4);
	p1.x = s->dim / 2 + (j * cbeta - i * sbeta) * s->zoom	+ s->offset_x;
	p1.y = (j * cbeta + i * sbeta) * s->zoom - s->tab[i][j] * s->zoom / 8.0
		+ s->offset_y;
	p2.x = s->dim / 2 + (j * cbeta - (i + 1) * sbeta) * s->zoom	+ s->offset_x;
	p2.y = ((j) * cbeta + (i + 1) * sbeta) * s->zoom
		- s->tab[i + 1][j] * s->zoom / 8.0 + s->offset_y;
	p1.z = s->tab[i][j];
	p2.z = s->tab[i + 1][j];
	print_line(color, s, p1, p2);
}

void	print_hline(int i, int j, t_store *s, t_rgb *color)
{
	t_point p1;
	t_point p2;
	float	sbeta;
	float	cbeta;
	
	sbeta = sin(s->beta) / sin(M_PI / 4);
	cbeta = cos(s->beta) / cos(M_PI / 4);
	p1.x = s->dim / 2 + (j * cbeta - i * sbeta) * s->zoom	+ s->offset_x;
	p1.y = (j * cbeta + i * sbeta) * s->zoom - s->tab[i][j] * s->zoom / 8.0
		+ s->offset_y;
	p2.x = s->dim / 2 + ((j + 1) * cbeta - i * sbeta) * s->zoom	+ s->offset_x;
	p2.y = ((j + 1) * cbeta + i * sbeta) * s->zoom
		- s->tab[i][j + 1] * s->zoom / 8.0 + s->offset_y;
	p1.z = s->tab[i][j];
	p2.z = s->tab[i][j + 1];
	print_line(color, s, p1, p2);
}

static void	print_map(t_store *s, t_rgb *color)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i < s->lg)
	{
		j = 0;
		while (j < s->larg)
		{
			if (i < s->lg - 1) 
				print_vline(i, j, s, color);
			if (j < s->larg - 1)
				print_hline(i, j, s, color);
			j++;
		}
		i++;
	}
}

void	print(t_store *store)
{
	t_rgb	color;

	store->bpp = 0;
	store->s_l = 0;
	store->endian = 0;
	color.r1 = 0xFF;
	color.g1 = 0xFF;
	color.b1 = 0xFF;
	color.r2 = 0xFF;
	color.g2 = 0x0;
	color.b2 = 0x0;
	store->img = mlx_new_image(store->mlx, store->dim, store->dim);
	mlx_clear_window(store->mlx, store->win);
	print_map(store, &color);
	mlx_put_image_to_window(store->mlx, store->win, store->img, 0, 0);
	mlx_destroy_image(store->mlx, store->img);
}
