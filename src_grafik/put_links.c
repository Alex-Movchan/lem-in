/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_links.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amovchan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/08 19:25:47 by amovchan          #+#    #+#             */
/*   Updated: 2017/06/08 19:25:48 by amovchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "grafik.h"

int		*add_xy(t_room *room, t_links *link, t_grafik *grafik)
{
	int		*xy;

	xy = (int*)malloc(sizeof(int) * 4);
	while (room)
	{
		if (!ft_strcmp(link->forst, room->nam))
		{
			xy[0] = (room->x) * grafik->con + 50;
			xy[1] = (room->y) * grafik->con + 50;
		}
		else if (!ft_strcmp(link->last, room->nam))
		{
			xy[2] = (room->x) * grafik->con + 50;
			xy[3] = (room->y) * grafik->con + 50;
		}
		room = room->next;
	}
	return (xy);
}

void	put_links(t_ant *ant, t_grafik *graf)
{
	t_links	*links;
	int		*xy;
	int		color;

	color = 0xFFFFFF;
	links = ant->links;
	while (links)
	{
		xy = add_xy(ft_beginroom(ant->room), links, graf);
		brezenhem(xy, graf, color);
		free(xy);
		color += 0xFF000F;
		color -= 0x0FFFF0;
		links = links->next;
	}
}
