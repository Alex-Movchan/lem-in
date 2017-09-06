/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_good_room.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amovchan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/08 19:46:19 by amovchan          #+#    #+#             */
/*   Updated: 2017/06/08 19:46:20 by amovchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_room	*start_endroom(t_room *lst, char *str)
{
	t_room	*room;
	t_room	*start;

	room = lst;
	start = NULL;
	while (room->next)
	{
		if (!ft_strcmp(str, room->next->nam))
		{
			start = room->next;
			if (room->next->next)
				room->next->next->previous = room;
			room->next = room->next->next;
			start->next = NULL;
			start->previous = NULL;
			return (start);
		}
		room = room->next;
	}
	return (start);
}

t_room	*nbrroom(t_room *room)
{
	t_room	*lst;
	int		i;

	i = 0;
	lst = room;
	while (lst->next)
	{
		lst->nbr = i;
		lst->ant = 0;
		i++;
		lst = lst->next;
	}
	lst->nbr = i;
	lst->ant = 0;
	return (ft_beginroom(lst));
}

t_room	*ft_isgoodroom(t_room *begin, t_room *start, t_room *end)
{
	t_room	*room;

	room = begin;
	if (ft_strcmp(begin->nam, start->nam))
	{
		start->next = room;
		room->previous = start;
	}
	while (room->next)
		room = room->next;
	room->next = end;
	end->previous = room;
	return (nbrroom(ft_beginroom(room)));
}

t_room	*good_room(t_ant **ant)
{
	t_room	*start;
	t_room	*end;
	t_room	*room;

	room = ft_beginroom((*ant)->room);
	if (!ft_strcmp((*ant)->end, room->nam))
	{
		end = room;
		room = room->next;
		room->previous = NULL;
		end->next = NULL;
	}
	else
		end = start_endroom(room, (*ant)->end);
	if (!ft_strcmp((*ant)->start, room->nam))
		start = room;
	else
		start = start_endroom(room, (*ant)->start);
	return (ft_isgoodroom(room, start, end));
}

int		count_room(t_room *room)
{
	int		count;
	t_room	*lst;

	count = 0;
	lst = room;
	while (lst)
	{
		count++;
		lst = lst->next;
	}
	return (count);
}
