/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection_way2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amovchan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/09 14:58:27 by amovchan          #+#    #+#             */
/*   Updated: 2017/06/09 14:58:28 by amovchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		intersection2(t_links *way, t_links *el)
{
	int		i;
	t_links	*links;
	int		count;

	links = way;
	count = 0;
	while (links)
	{
		if ((i = nova_links(links->elem->next, el->elem->next)) != 0)
			count++;
		links = links->next;
	}
	return (count);
}

t_elem	*ft_bedewey(t_links *lst, t_links *links, int nb)
{
	t_elem	*elem;
	int		nbr;

	elem = NULL;
	while (lst)
	{
		if ((nbr = intersection2(links, lst)) >= nb)
		{
			if (nb == nbr && elem && counllinks(elem) > lenlinks(lst))
				continue ;
			else
				elem = lst->elem;
			nb = nbr;
		}
		lst = lst->next;
	}
	return (elem);
}

t_links	*intersection_way2(t_links *way)
{
	t_links	*links;
	t_links	*lst;
	t_elem	*elem;
	int		nb;

	nb = 1;
	lst = way;
	links = way;
	elem = NULL;
	while (links->next)
	{
		lst = way;
		if ((elem = ft_bedewey(lst, links, nb)) != NULL)
		{
			way = dellinks(way, elem);
			elem = NULL;
			links = way;
			nb = 1;
		}
		else
			links = links->next;
	}
	return (way);
}
