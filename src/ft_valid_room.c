/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_valid_room.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amovchan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/09 16:08:06 by amovchan          #+#    #+#             */
/*   Updated: 2017/06/09 17:30:57 by amovchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_room	*ft_room(char *str)
{
	t_room	*room;
	int		j;
	int		i;

	i = -1;
	j = -1;
	room = (t_room*)malloc(sizeof(t_room));
	while (str[++i] > 33)
		;
	room->nam = (char*)malloc(sizeof(char) * i);
	i = -1;
	while (str[++i] > 33)
		room->nam[++j] = str[i];
	room->nam[++j] = '\0';
	i++;
	room->x = ft_atoin(str, &i);
	room->y = ft_atoin(str, &i);
	room->previous = NULL;
	room->next = NULL;
	return (room);
}

int		ft_valid_room(char *str)
{
	int	i;

	i = -1;
	while (str[++i] > 33)
		if (!ft_isalnum((int)str[i]))
			return (0);
	if (!str[i])
		return (0);
	while (str[++i] > 33)
		if (!ft_isdigit((int)str[i]))
			return (0);
	if (!str[i])
		return (0);
	while (str[++i])
		if (!ft_isdigit((int)str[i]))
			return (0);
	return (1);
}

int		ft_repeat_room(t_room *room)
{
	t_room	*lst;
	t_room	*lst2;
	int		i[2];

	i[0] = 0;
	lst = room;
	if (!room)
		return (0);
	while (lst)
	{
		lst2 = room;
		i[1] = 0;
		while (lst2)
		{
			if (!ft_strcmp(lst->nam, lst2->nam) && i[0] != i[1])
				return (0);
			else if (lst->x == lst2->x && lst->y == lst2->y && i[0] != i[1])
				return (0);
			i[1]++;
			lst2 = lst2->next;
		}
		i[0]++;
		lst = lst->next;
	}
	return (1);
}

int		ft_isroom(char *lin, t_ant **ant, int start_end)
{
	if ((*ant)->room == NULL)
		(*ant)->room = ft_room(lin);
	else
	{
		(*ant)->room->next = ft_room(lin);
		(*ant)->room->next->previous = (*ant)->room;
		(*ant)->room = (*ant)->room->next;
	}
	if (start_end == 1)
		(*ant)->start = (*ant)->room->nam;
	else if (start_end == 2)
		(*ant)->end = (*ant)->room->nam;
	if (!ft_repeat_room(ft_beginroom((*ant)->room)))
		return (0);
	return (1);
}
