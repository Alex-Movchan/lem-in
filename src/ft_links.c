/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_links.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amovchan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/08 20:05:30 by amovchan          #+#    #+#             */
/*   Updated: 2017/06/10 22:29:56 by amovchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

char	**newmap(t_room *room)
{
	char	**map;
	int		i;
	int		j;
	int		size;

	size = count_room(room);
	map = (char**)malloc(sizeof(char*) * (size + 1));
	i = -1;
	while (++i < size)
	{
		map[i] = (char *)malloc(sizeof(char) * (size + 1));
		j = -1;
		while (++j < size)
			map[i][j] = '0';
		map[i][j] = '\0';
	}
	map[i] = NULL;
	return (map);
}

int		ft_linksroom(char *str, t_room *room)
{
	int	i;

	i = 0;
	while (room)
	{
		if (!ft_strcmp(str, room->nam))
			break ;
		i++;
		room = room->next;
	}
	return (i);
}

char	**ft_links(char *str, t_ant **ant, char **map)
{
	char	**links;
	int		i;
	int		j;

	if (!ft_valid_links(str, ant))
		return (NULL);
	(*ant)->room = good_room(ant);
	if (map == NULL)
		map = newmap((*ant)->room);
	links = ft_strsplit(str, '-');
	i = ft_linksroom(links[0], (*ant)->room);
	j = ft_linksroom(links[1], (*ant)->room);
	ft_dellarrey(links);
	map[i][j] = '1';
	map[j][i] = '1';
	return (map);
}

int		start_room(char **lin, int *start_end, t_ant **ant, t_params **params)
{
	if (!ft_strcmp(*lin, "##start"))
	{
		if ((*ant)->start != NULL)
		{
			ft_strdel(lin);
			return (1);
		}
		(*start_end) = 1;
		get_params(*lin, params);
		get_next_line(0, lin);
		if (!ft_valid_room(*lin))
		{
			ft_strdel(lin);
			return (1);
		}
	}
	return (0);
}

int		end_room(char **lin, int *start_end, t_ant **ant, t_params **params)
{
	if (!ft_strcmp(*lin, "##end"))
	{
		if ((*ant)->end != NULL)
		{
			ft_strdel(lin);
			return (1);
		}
		(*start_end) = 2;
		get_params(*lin, params);
		get_next_line(0, lin);
		if (!ft_valid_room(*lin))
		{
			ft_strdel(lin);
			return (1);
		}
	}
	return (0);
}
