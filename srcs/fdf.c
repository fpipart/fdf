/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpipart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/15 12:12:51 by fpipart           #+#    #+#             */
/*   Updated: 2017/03/28 16:52:04 by fpipart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	my_key_function(int key, void *param)
{
	t_store *store;

	store = param;
	ft_printf("Nombre de la touche : %d\n", key);
	if (key == 53)
		exit(0);
	if (key >= 69 || key == 15 || key == 17 || key == 3 || key == 5)
	{
		if (key == 15 && store->beta < M_PI / 2.0 - M_PI / 24.0)
			store->beta += M_PI / 24.0;
		if (key == 17 && store->beta > M_PI / 24.0)
			store->beta -= M_PI / 24.0;
		if (key == 3 && store->theta < M_PI / 2.0 - M_PI / 24.0)
			store->theta += M_PI / 24.0;
		if (key == 5 && store->theta > M_PI / 24.0)
			store->theta -= M_PI / 24.0;
		if (key == 69)
			store->zoom++;
		if (key == 78)
		{
			if (store->zoom > 0)
				store->zoom--;
		}
		if (key == 124 && store->offset_x < 2147483642)
			store->offset_x += 5;
		if (key == 126 && store->offset_y > -2147483643)
			store->offset_y -= 5;
		if (key == 123 && store->offset_x > -2147483643)
			store->offset_x -= 5;
		if (key == 125 && store->offset_y < 2147483647)
			store->offset_y += 5;
		if (key == 69 || key == 78 || key == 15 || key == 17 || key == 3 
				|| key == 5 || (key >= 123 && key <= 126))
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
		store.beta = M_PI / 4.0;
		store.theta = M_PI / 3.7;
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
