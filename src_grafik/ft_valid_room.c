/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_valid_room.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amovchan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/08 17:55:12 by amovchan          #+#    #+#             */
/*   Updated: 2017/06/09 17:36:10 by amovchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "grafik.h"

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
	int		i;

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

void	ft_isroom(char *lin, t_ant **ant, int start_end)
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
}
