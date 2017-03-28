/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpipart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/27 18:30:31 by fpipart           #+#    #+#             */
/*   Updated: 2017/03/28 19:05:29 by fpipart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
//
#include <stdio.h>

static	void	horiz(t_store s, t_line l)
{
	float i;

	i = 0;
	l.e = l.dx / 2.0;
	l.i = 1;
	while (l.i <= l.dx)
	{
		l.x += l.dir_x;
		l.e += l.dy;
		if (l.e >= l.dx)
		{
			l.e -= l.dx;
			l.y += l.dir_y;
		}
		if (s.z_min != s.z_max && l.zf != l.zi && l.dx != 0)
		{
			i = l.zi + (l.i / (float)l.dx) * (l.zf - l.zi);
			l.c.g1 = roundf(((i - s.z_min) / (float)(s.z_max - s.z_min)) * 255);
		}
		put_pixel(&s, l.x, l.y, l.c);
		l.i++;
	}
}

static	void	vertic(t_store s, t_line l)
{
	float i;

	i = 0;
	l.e = l.dy / 2.0;
	l.i = 1;
	while (l.i <= l.dy)
	{
		l.y += l.dir_y;
		l.e += l.dx;
		if (l.e >= l.dy)
		{
			l.e -= l.dy;
			l.x += l.dir_x;
		}
		if (s.z_min != s.z_max && l.zf != l.zi && l.dy != 0)
		{
			i = l.zi + (l.i / (float)l.dy) * (l.zf - l.zi);
			l.c.g1 = roundf(((i - s.z_min) / (float)(s.z_max - s.z_min)) * 255);
		}
		put_pixel(&s, l.x, l.y, l.c);
		l.i++;
	}
}

void	print_line(t_rgb *c, t_store *s, t_point p1, t_point p2)
{
	t_line	l;

	l.x = roundf(p1.x);
	l.y = roundf(p1.y);
	l.z = p1.z;
	l.zi = p1.z;
	l.zf = p2.z;
	l.dx = roundf(p2.x) - l.x;
	l.dy = roundf(p2.y) - l.y;
	l.dir_x = (l.dx >= 0) ? 1 : -1;
	l.dir_y = (l.dy >= 0) ? 1 : -1;
	l.dx = (l.dx >= 0 ? l.dx : -l.dx);
	l.dy = (l.dy >= 0 ? l.dy : -l.dy);
	l.c = *c;
	if (s->z_max != s->z_min)
		l.c.g1 = roundf(((l.z - s->z_min) / (float)(s->z_max - s->z_min)) * 255);
	printf("g1 = %d\n", l.c.g1);
	put_pixel(s, l.x, l.y, l.c);
	if (l.dx > l.dy)
		horiz(*s, l);
	else
		vertic(*s, l);
}
