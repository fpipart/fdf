/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpipart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/15 15:20:41 by fpipart           #+#    #+#             */
/*   Updated: 2017/03/25 15:31:21 by fpipart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static int	find_dim(char **argv, t_store *store)
{
	char	*line;
	int		i;
	int		j;
	int		fd;

	fd = open(argv[1], O_RDWR);
	if (fd <= 0)
		return (error("no data"));
	i = 0;
	j = 0;
	while (get_next_line(fd, &line))
	{
		if (j == 0)
			i = ft_wordcount(line, ' ');
		else if (i != ft_wordcount(line, ' '))
			return (error("line length"));
		j++;
	}
	close(fd);
	store->larg = i;
	store->lg = j;
	return (0);
}

static void	fill_line(int **tab_int, char *line, t_store *store)
{
	char	**tab;
	int		i;
	int		max;

	tab = ft_strsplit(line, ' ');
	i = 0;
	max = ft_wordcount(line, ' ');
	if (tab)
	{
		while (i < max)
		{
			(*tab_int)[i] = ft_atoi(tab[i]);
			if (store->z_max < (*tab_int)[i])
				store->z_max = (*tab_int)[i];
			if (store->z_min > (*tab_int)[i])
				store->z_min = (*tab_int)[i];
			free(tab[i]);
			i++;
		}
		free(tab);
	}
}

int			read_map(char **argv, t_store *store)
{
	char	*line;
	int		fd;
	int		i;

	store->z_max = -2147483648;
	store->z_min = 2147483647;
	if (find_dim(argv, store))
		return (-1);
	if (!(store->tab = (int**)malloc(sizeof(int*) * store->lg)))
		return (-1);
	fd = open(argv[1], O_RDWR);
	i = 0;
	while (get_next_line(fd, &line))
	{
		if (!(store->tab[i] = (int*)malloc(sizeof(int) * store->larg)))
			return (-1);
		fill_line(&store->tab[i], line, store);
		i++;
	}
	return (0);
}
