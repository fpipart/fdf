/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpipart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/15 16:39:00 by fpipart           #+#    #+#             */
/*   Updated: 2017/02/15 17:28:36 by fpipart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		error(char *error)
{
	if (ft_strequ("line length", error))
		ft_putendl("Found wrong line length. Exiting.");
	if (ft_strequ("no data", error))
		ft_putendl("No data found.");
	if (ft_strequ("usage", error))
		ft_putendl("Usage : ./fdf <filename> [ case_size z_size ]");
	return (-1);
}
