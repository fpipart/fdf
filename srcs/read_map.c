/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpipart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/15 15:20:41 by fpipart           #+#    #+#             */
/*   Updated: 2017/03/22 10:05:06 by fpipart          ###   ########.fr       */
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

static void	fill_line(int **tab_int, char *line)
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
		fill_line(&store->tab[i], line);
		i++;
	}
	return (0);
}
