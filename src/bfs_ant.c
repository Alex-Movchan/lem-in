/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs_ant.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amovchan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/08 17:22:55 by amovchan          #+#    #+#             */
/*   Updated: 2017/06/08 17:22:56 by amovchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	ft_elemlink(int elems, t_links **links)
{
	t_elem	*lst;
	t_links	*l;

	l = *links;
	if (l->next)
	{
		while (l->next)
			l = l->next;
	}
	if (!l->elem)
	{
		l->elem = (t_elem*)malloc(sizeof(t_elem));
		l->elem->elem = elems;
		l->elem->next = NULL;
		return ;
	}
	lst = l->elem;
	while (lst->next)
		lst = lst->next;
	lst->next = (t_elem*)malloc(sizeof(t_elem));
	lst = lst->next;
	lst->elem = elems;
	lst->next = NULL;
}

int		ft_search_link(t_links *link, int end)
{
	t_elem	*lst;
	t_links	*s;

	s = link;
	if (s->next)
	{
		while (s->next)
			s = s->next;
	}
	lst = s->elem;
	while (lst)
	{
		if (lst->elem == end)
			return (1);
		lst = lst->next;
	}
	return (0);
}

t_links	*next_link(t_links *link)
{
	t_links	*lst;
	int		nbr;

	nbr = 1;
	if (!link)
	{
		link = (t_links*)malloc(sizeof(t_links));
		link->next = NULL;
		link->elem = NULL;
		ft_elemlink(0, &link);
		return (link);
	}
	lst = link;
	while (lst->next)
	{
		nbr++;
		lst = lst->next;
	}
	lst->next = (t_links*)malloc(sizeof(t_links));
	lst = lst->next;
	lst->next = NULL;
	lst->elem = NULL;
	ft_elemlink(0, &link);
	return (link);
}

t_links	*ft_bfs_ant(char **links, int i, t_links *link, int end)
{
	int		j;
	int		nbr;

	if (ft_search_link(link, end))
		return (next_link(link));
	if (links[0][end] == '1')
	{
		ft_elemlink(end, &link);
		return (link);
	}
	j = 0;
	while (links[i][j])
	{
		if (links[i][j] == '1' && !ft_search_link(link, j))
		{
			nbr = j;
			ft_elemlink(nbr, &link);
			ft_bfs_ant(links, nbr, link, end);
			ft_ncpylink(nbr, &link);
		}
		j++;
	}
	return (link);
}
