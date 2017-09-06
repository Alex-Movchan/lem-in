/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stop_links.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amovchan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/09 16:09:22 by amovchan          #+#    #+#             */
/*   Updated: 2017/06/09 16:09:23 by amovchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_links	*stop_links(t_links *links)
{
	t_links	*begin;
	int		i;
	int		len;

	begin = links;
	i = 0;
	len = lenlinks(links);
	while (links->next)
	{
		i++;
		links->stop = (lenlinks(links) - len + (i - 1));
		links = links->next;
	}
	links->stop = (lenlinks(links) - len + (i - 1));
	return (begin);
}

t_links	*goodlinks(t_links *links, int count)
{
	t_links	*lst;

	lst = links;
	while (lst)
	{
		if (count < lst->stop)
			break ;
		lst = lst->next;
	}
	return (links);
}

t_elem	*lastelems(t_elem *lst)
{
	while (lst->next)
		lst = lst->next;
	return (lst);
}
