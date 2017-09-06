/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection_way.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amovchan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/09 14:58:15 by amovchan          #+#    #+#             */
/*   Updated: 2017/06/09 14:58:17 by amovchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		cmpelem(t_elem *s1, t_elem *s2)
{
	while (s1 && s2)
	{
		if (s1->elem != s2->elem)
			return (1);
		s1 = s1->next;
		s2 = s2->next;
	}
	if (s1 || s2)
		return (1);
	return (0);
}

int		nova_links(t_elem *s2, t_elem *s1)
{
	int		i;
	int		j;
	t_elem	*s;

	i = 0;
	j = 0;
	if (!cmpelem(s1, s2))
		return (0);
	while (s1->next)
	{
		s = s2;
		while (s->next)
		{
			if (s1->elem == s->elem)
			{
				i++;
				break ;
			}
			s = s->next;
		}
		j++;
		s1 = s1->next;
	}
	return (i);
}

void	dell_t_links(t_links *lst)
{
	t_elem	*leaks;

	if (!lst)
		return ;
	while (lst->elem)
	{
		leaks = lst->elem;
		lst->elem = lst->elem->next;
		leaks->next = NULL;
		free(leaks);
	}
	free(lst);
}

t_links	*dellinks(t_links *links, t_elem *dublikat)
{
	t_links	*leaks;
	t_links	*begin;

	begin = links;
	leaks = NULL;
	while (links->next)
	{
		if (!nova_links(links->next->elem, dublikat))
		{
			leaks = links->next;
			links->next = links->next->next;
			leaks->next = NULL;
			break ;
		}
		links = links->next;
	}
	if (leaks == NULL && !nova_links(begin->elem, dublikat))
	{
		leaks = begin;
		begin = begin->next;
		leaks->next = NULL;
	}
	dell_t_links(leaks);
	return (begin);
}

t_room	*ft_beginroom(t_room *room)
{
	t_room	*lst;

	lst = room;
	while (lst->previous != NULL)
		lst = lst->previous;
	return (lst);
}
