/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpipart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/15 17:10:48 by fpipart           #+#    #+#             */
/*   Updated: 2017/03/24 17:29:13 by fpipart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
//
#include <stdio.h>

static void	put_pixel(t_store *store, int x, int y, t_rgb *color)
{
	store->data_img = mlx_get_data_addr(store->img, &(store->bpp), &(store->s_l), &(store->endian));
	store->data_img[x * store->bpp / 8 + y * store->s_l] = color->b;
	store->data_img[x * store->bpp / 8 + 1 + y * store->s_l] = color->g;
	store->data_img[x * store->bpp / 8 + 2 + y * store->s_l] = color->r;
}

static void	print_line(t_rgb *color, t_store *store, t_point p1, t_point p2)
{
	t_point p;
	float	f;
	float	df;

	df = (1.0 / ft_max_float((float)ft_abs(p1.x - p2.x), (float)ft_abs(p1.y - p2.y)));
	f = 0.0;
	while (f <= 1)
	{
		p.x = p1.x + f * (p2.x - p1.x);
		p.y = p1.y + f * (p2.y - p1.y);
		printf("x = %d, y = %d, f = %f\n", p.x, p.y, f);
		if (p.y < H  && p.x < W)
			put_pixel(store, p.y, p.x, color);
		f = f + df;
	}
}

static void	print_hline(int i, int j, t_store *store, t_rgb *color)
{
	t_point p1;
	t_point p2;

	p1.x = W / 2 + (i - j) * Z * cos(store->theta);
	p1.y = H / 2 + (j + i) * Z * sin(store->theta) - store->tab[i][j] * Z;
	p2.x = W / 2 + (i - (j + 1)) * Z * cos(store->theta);
	p2.y = H / 2 + (j + 1 + i) * Z * sin(store->theta) - store->tab[i][j + 1] * Z;
	print_line(color, store, p1, p2);
}

static void	print_vline(int i, int j, t_store *store, t_rgb *color)
{
	t_point p1;
	t_point p2;

	p1.x = W / 2 + (i - j) * Z * cos(store->theta);
	p1.y = H / 2 + (j + i) * Z * sin(store->theta) - store->tab[i][j] * Z;
	p2.x = W / 2 + (i + 1 - j) * Z * cos(store->theta);
	p2.y = H / 2 + (j + i + 1) * Z * sin(store->theta) - store->tab[i + 1][j] * Z;
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
//			printf("i = %d, j = %d\n", i, j);
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
	color.r = 0xFF;
	color.g = 0xFF;
	color.b = 0xFF;
	store->img = mlx_new_image(store->mlx, W, H);
	print_map(store, &color);
	mlx_put_image_to_window(store->mlx, store->win, store->img, 0, 0);
//	mlx_string_put(store->mlx, store->img, 20, 20, 0x00FFFFFF, "Coucou");
	mlx_destroy_image(store->mlx, store->img);
}
