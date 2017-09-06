/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ant_on_links.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amovchan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/08 17:17:39 by amovchan          #+#    #+#             */
/*   Updated: 2017/06/08 17:17:41 by amovchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_links	*ant_on_links(t_links *links)
{
	t_links	*link;
	t_elem	*ant;

	link = links;
	while (link)
	{
		ant = link->elem;
		ant->previous = NULL;
		ant->next->previous = ant;
		ant = ant->next;
		ant->ant = 0;
		while (ant)
		{
			ant->ant = 0;
			if (ant->next)
				ant->next->previous = ant;
			ant = ant->next;
		}
		link = link->next;
	}
	return (links);
}

void	mov_ant(t_links *links, t_ant *ant)
{
	t_links	*begin;
	t_links	*link;

	link = links;
	begin = link;
	while (link)
	{
		link->elem = lastelems(link->elem);
		while (link->elem->previous)
		{
			if (link->elem->ant == 0 && link->elem->previous->ant != 0)
			{
				link->elem->ant = link->elem->previous->ant;
				link->elem->previous->ant = 0;
			}
			link->elem = link->elem->previous;
		}
		link = link->next;
	}
	printmov(begin, ant);
}

int		put_forst(t_links *links, int ant, int max)
{
	while (links)
	{
		ant++;
		if (ant > max)
			break ;
		if (max - ant < links->stop)
		{
			ant--;
			break ;
		}
		links->elem->ant = ant;
		links = links->next;
	}
	return (ant);
}

int		lastant(t_links *links)
{
	t_links	*lst;
	t_elem	*list;

	lst = links;
	while (lst)
	{
		list = lst->elem;
		while (list->next)
		{
			if (list->ant != 0)
				return (1);
			list = list->next;
		}
		lst = lst->next;
	}
	return (0);
}

void	ant_on_map(t_links *links, t_ant *ant)
{
	int		count;
	t_links	*link;

	if (lenlinks(links) == 1)
		return (fastmov(ant));
	link = goodlinks(links, ant->count);
	count = put_forst(link, 0, ant->count);
	while (lastant(link))
	{
		mov_ant(link, ant);
		count = put_forst(link, count, ant->count);
	}
}
