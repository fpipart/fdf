/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpipart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/15 12:12:51 by fpipart           #+#    #+#             */
/*   Updated: 2017/02/15 17:33:54 by fpipart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	my_key_function(int keycode, void *param)
{
	t_store *store;

	store = param;
	ft_printf("Nombre de la touche : %d\n", keycode);
	if (keycode == 53)
	{
		mlx_destroy_window(store->mlx, store->win);
		exit(0);
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
		print_map(&store);
		store.mlx = mlx_init();
		store.win = mlx_new_window(store.mlx, 400, 400, "mlx 42");
		mlx_pixel_put(store.mlx, store.win, 200, 200, 0x00FFFFFF);
		mlx_key_hook(store.win, my_key_function, &store);
		mlx_loop(store.mlx);
	}
	else
		error("usage");
	return (0);
}
