/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpipart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/15 12:18:54 by fpipart           #+#    #+#             */
/*   Updated: 2017/02/15 17:14:46 by fpipart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef FDF_H
# define FDF_H

#include <fcntl.h>
#include "mlx.h"
#include "../libft/libft.h"

typedef struct	s_store
{
	void		*mlx;
	void		*win;
	int			larg;
	int			lg;
	int			**tab;
}				t_store;

/*
**		read_map.c
*/
int			read_map(char **argv, t_store *store);
/*
**		error.c
*/
int				error(char *error);
/*
**		print_map.c
*/
void			print_map(t_store *store);

# endif
