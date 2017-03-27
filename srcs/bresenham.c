/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpipart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/27 18:30:31 by fpipart           #+#    #+#             */
/*   Updated: 2017/03/27 18:53:50 by fpipart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static	void	horiz(t_store s, t_line l, t_point p1, t_point p2)
{
	l.e = l.dx / 2;
	l.i = 1;
	while (l.i <= l.dx)
	{
		p1.x += l.dir_x;
		l.e += l.dy;
		if (l.e >= l.dx)
		{
			l.e -= l.dx;
			p1.y += l.dir_y;
		}
		put_pixel(&s, l);
		l.i++;
	}
}
/*
static	void	vertic(t_store s, t_line l)
{
	l.e = l.dy / 2;
	l.i = 1;
	while (l.i <= l.dy)
	{
		s.y += l.dir_y;
		l.e += l.dx;
		if (l.e >= s[d)
		{
			l.e -= l.dy;
			s.dx += l.dir_x;
		}
		put_pixel(&s, s);
		l.i++;
	}
}
*/
void	print_line(t_store	s, t_point p1, t_point p2)
{
	t_line	l;

	l.x = p1.x;
	l.y = p1.y;
	
	l.dx = p2.x - p1.x;
	l.dy = p2.y - p1.y;
	l.dir_x = (l.dx > 0) ? 1 : -1;
	l.dir_y = (l.dy > 0) ? 1 : -1;
	l.dx = abs(l.dx);
	l.dy = abs(l.dy);
	s.r = 255;
	s.g = 255;
	s.b = 255;
	if (l.dx > l.dy)
		horiz(s, s);
	else
		vertic(s, s);
}
