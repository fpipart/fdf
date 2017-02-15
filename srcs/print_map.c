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
