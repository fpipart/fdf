/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpipart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/27 18:30:31 by fpipart           #+#    #+#             */
/*   Updated: 2017/03/28 11:57:57 by fpipart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
//
#include <stdio.h>

static	void	horiz(t_store s, t_line l)
{
	l.e = l.dx / 2;
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
		put_pixel(&s, l.x, l.y, l.c);
		l.i++;
	}
}

static	void	vertic(t_store s, t_line l)
{
	l.e = l.dy / 2;
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
		put_pixel(&s, l.x, l.y, l.c);
		l.i++;
	}
}

void	print_line(t_rgb *c, t_store *s, t_point p1, t_point p2)
{
	t_line	l;

	l.x = p1.x;
	l.y = p1.y;
	l.dx = p2.x - p1.x;
	l.dy = p2.y - p1.y;
	l.dir_x = (l.dx > 0) ? 1 : -1;
	l.dir_y = (l.dy > 0) ? 1 : -1;
	l.dx = (l.dx >= 0 ? l.dx : - l.dx);
	l.dy = (l.dy >= 0 ? l.dy : - l.dy);
	l.c.r1 = 255;
	l.c.g1 = 255;
	l.c.b1 = 255;
	put_pixel(s, l.x, l.y, l.c);
	if (l.dx > l.dy)
		horiz(*s, l);
	else
		vertic(*s, l);
}
