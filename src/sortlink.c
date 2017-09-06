/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortlink.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amovchan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/09 16:07:16 by amovchan          #+#    #+#             */
/*   Updated: 2017/06/09 16:07:18 by amovchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_links	*sortlink(t_links *links)
{
	t_links	*begin;
	t_links	*lst;
	t_elem	*elems;

	begin = links;
	lst = begin;
	while (lst->next)
	{
		if (lenlinks(lst) > lenlinks(lst->next))
		{
			elems = lst->elem;
			lst->elem = lst->next->elem;
			lst->next->elem = elems;
			lst = begin;
		}
		else
			lst = lst->next;
	}
	return (begin);
}

void	ft_dellarrey(char **s)
{
	int		i;

	if (!s)
		return ;
	i = -1;
	while (s[++i])
		free(s[i]);
	free(s);
}
