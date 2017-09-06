/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_search_links.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amovchan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/09 16:10:01 by amovchan          #+#    #+#             */
/*   Updated: 2017/06/09 16:10:02 by amovchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	ft_search_links(char **links, t_ant *ant)
{
	t_links *link;
	t_links	*leaks;

	link = sortlink(ft_bfs_ant(links, 0, next_link(NULL),
					(sizeareey(links) - 1)));
	if (lenlinks(link) == 0)
	{
		leaks = link;
		link = link->next;
		leaks->next = NULL;
		dell_t_links(leaks);
	}
	link = stop_links(sortlink((intersection_way2((link)))));
	link = ant_on_links(link);
	ant_on_map(link, ant);
}

int		lenlinks(t_links *links)
{
	int		i;
	t_elem	*lst;

	i = 0;
	lst = links->elem;
	while (lst->next)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

int		counllinks(t_elem *lst)
{
	int i;

	i = 0;
	while (lst->next)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}
