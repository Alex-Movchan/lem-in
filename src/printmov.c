/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printmov.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amovchan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/09 16:09:06 by amovchan          #+#    #+#             */
/*   Updated: 2017/06/09 16:09:07 by amovchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

char	*thisroom(t_room *room, int nb)
{
	t_room	*lst;

	lst = room;
	while (lst)
	{
		if (lst->nbr == nb)
			break ;
		lst = lst->next;
	}
	return (lst->nam);
}

void	printmov(t_links *link, t_ant *ant)
{
	t_links *lst;
	t_elem	*list;

	lst = link;
	while (lst)
	{
		list = lastelems(lst->elem);
		while (list->previous)
		{
			if (list->ant != 0)
				ft_printf("L%d-%s ", list->ant,
					thisroom(ant->room, list->elem));
			if (!list->next)
				list->ant = 0;
			list = list->previous;
		}
		lst = lst->next;
	}
	ft_printf("\n");
}
