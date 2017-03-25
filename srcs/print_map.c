/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpipart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/15 17:10:48 by fpipart           #+#    #+#             */
/*   Updated: 2017/03/25 17:07:11 by fpipart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
//
#include <stdio.h>

static void	put_pixel(t_store *store, int x, int y, t_rgb c)
{
	store->data_img = mlx_get_data_addr(store->img, &(store->bpp), &(store->s_l), &(store->endian));
	store->data_img[x * store->bpp / 8 + y * store->s_l] = c.b1;
	store->data_img[x * store->bpp / 8 + 1 + y * store->s_l] = c.g1;
	store->data_img[x * store->bpp / 8 + 2 + y * store->s_l] = c.r1;
}

static void	print_line(t_rgb *color, t_store *store, t_point p1, t_point p2)
{
	t_point p;
	t_rgb	c;
	float	z_c;
	float	f;
	float	df;
	float	dcolor;

	z_c = store->z_max;
	df = (1.0 / ft_max_float((float)ft_abs(p1.x - p2.x), (float)ft_abs(p1.y - p2.y)));
	f = 0.0;
	dcolor = 0;
	if (store->z_max - store->z_min != 0)
		dcolor = (1.0 / (store->z_max - store->z_min));
	while (f <= 1)
	{
		p.x = p1.x + f * (p2.x - p1.x);
		p.y = p1.y + f * (p2.y - p1.y);
		z_c = (1 - f) * p1.z + f * p2.z;
		printf("z_c = %f, p1.z = %d, p2.z = %d, f = %f, p2.z-p1.z = %d\n", z_c, p1.z, p2.z, f, (p2.z - p1.z));
		c.r1 = color->r1;
		c.g1 = (z_c - store->z_min) * dcolor * 255;
		c.b1 = (z_c - store->z_min) * dcolor * 255;
		if (p.y < H  && p.x < W)
			put_pixel(store, p.x, p.y, c);
		f = f + df;
	}
}

static void	print_vline(int i, int j, t_store *store, t_rgb *color)
{
	t_point p1;
	t_point p2;

	p1.x = W / 2 + (j - i) * Z;
	p1.y = (j + i) * Z - store->tab[i][j] * Z / 6.0;
	p1.z = store->tab[i][j];
	p2.x = W / 2 + (j - (i + 1)) * Z ;
	p2.y = (j + 1 + i) * Z - store->tab[i + 1][j] * Z / 6.0;
	p2.z = store->tab[i][j];
	if (store->tab[i][j] > store->z_max)
	{
		ft_putendl("error");
		exit(0);
	}
	print_line(color, store, p1, p2);
}

static void	print_hline(int i, int j, t_store *store, t_rgb *color)
{
	t_point p1;
	t_point p2;

	p1.x = W / 2 + (j - i) * Z;
	p1.y = (j + i) * Z - store->tab[i][j] * Z / 6.0;
	p1.z = store->tab[i][j];
	p2.x = W / 2 + (j + 1 - i) * Z;
	p2.y = (j + i + 1) * Z - store->tab[i][j + 1] * Z / 6.0;
	p2.z = store->tab[i][j];
	print_line(color, store, p1, p2);
}

static void	print_map(t_store *store, t_rgb *color)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	store->theta = 0.5;
	while (i < store->lg)
	{
		j = 0;
		while (j < store->larg)
		{
			if (j < store->larg && i < store->lg - 1) 
				print_vline(i, j, store, color);
			if (j < store->larg - 1 && i < store->lg)
				print_hline(i, j, store, color);
			j++;
		}
		i++;
	}
}

void	print(t_store *store)
{
	t_rgb	color;

	store->bpp = 2;
	store->s_l = 2;
	store->endian = 0;
	color.r1 = 0xFF;
	color.g1 = 0xFF;
	color.b1 = 0xFF;
	color.r2 = 0xFF;
	color.g2 = 0x0;
	color.b2 = 0x0;
	store->img = mlx_new_image(store->mlx, W, H);
	print_map(store, &color);
	mlx_put_image_to_window(store->mlx, store->win, store->img, 0, 0);
	//	mlx_string_put(store->mlx, store->img, 20, 20, 0x00FFFFFF, "Coucou");
	mlx_destroy_image(store->mlx, store->img);
}
