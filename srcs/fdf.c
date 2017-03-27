/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpipart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/15 12:12:51 by fpipart           #+#    #+#             */
/*   Updated: 2017/03/27 16:44:57 by fpipart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	my_key_function(int keycode, void *param)
{
	t_store *store;

	store = param;
//	ft_printf("Nombre de la touche : %d\n", keycode);
	if (keycode == 53)
		exit(0);
	if (keycode >= 69 || keycode == 15 || keycode == 17)
	{
		if (keycode == 15 && store->beta < M_PI / 2 - M_PI / 24)
			store->beta += M_PI / 24;
		if (keycode == 17 && store->beta > M_PI / 24)
			store->beta -= M_PI / 24;
		if (keycode == 69)
			store->zoom++;
		if (keycode == 78)
		{
			if (store->zoom > 0)
				store->zoom--;
		}
		if (keycode == 124 && store->offset_x < 2147483642)
			store->offset_x += 5;
		if (keycode == 126 && store->offset_y > -2147483643)
			store->offset_y -= 5;
		if (keycode == 123 && store->offset_x > -2147483643)
			store->offset_x -= 5;
		if (keycode == 125 && store->offset_y < 2147483647)
			store->offset_y += 5;
		if (keycode == 69 || keycode == 78 || keycode == 15 || keycode == 17 ||
				(keycode >= 123 && keycode <= 126))
			print(store);
	}
	return (1);
}

int main(int argc, char **argv)
{
	t_store store;

	if (argc == 2)
	{
		if (read_map(argv, &store))
			return (0);
		store.dim = 1000;
		store.zoom = (8 < store.dim / (2 * store.larg) ?
				store.dim / (2 * store.larg) : 8);
		store.offset_x = 0;
		store.offset_y = 0;
		store.beta = M_PI / 4;
		store.mlx = mlx_init();
		store.win = mlx_new_window(store.mlx, store.dim, store.dim, "mlx 42");
		print(&store);
		mlx_key_hook(store.win, my_key_function, &store);
		mlx_loop(store.mlx);
	}
	else
		error("usage");
	return (0);
}
