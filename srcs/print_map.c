/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpipart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/15 17:10:48 by fpipart           #+#    #+#             */
/*   Updated: 2017/02/15 17:13:50 by fpipart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
//
#include <stdio.h>

void	print_map(t_store *store)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < store->lg)
	{
		j = 0;
		while (j < store->larg)
		{
			ft_putnbr(store->tab[i][j]);
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}

void	print_line(t_point p1, t_point p2, t_store store)
{
	float	f;
	float	i;
	int		color;
	t_point p;

	(void)store;
	(void)p;
	f = (1.0 / ft_max_float((float)ft_abs(p1.x - p2.x), (float)ft_abs(p1.y - p2.y)));
	i = 0.0;
	color = 0x00FFFFFF;
	while (i <= 1)
	{
		p.x = p1.x + i * (p2.x - p1.x);
		p.y = p1.y + i * (p2.y - p1.x);
		mlx_pixel_put(store.mlx, store.win, p.x, p.y, color);
		i += f;
	}
}
