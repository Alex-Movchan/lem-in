/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mov_in_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amovchan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/08 19:24:30 by amovchan          #+#    #+#             */
/*   Updated: 2017/06/08 19:24:31 by amovchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "grafik.h"

t_room	*theroom_ant(t_room *room, t_ant *ant)
{
	t_room	*lst;

	lst = room;
	while (lst)
	{
		if (!ft_strcmp(lst->nam, ant->start))
			return (lst);
		lst = lst->next;
	}
	return (0);
}

int		room_is_clos(t_room *room, t_mov *moov)
{
	t_mov	*lst;

	lst = moov;
	while (lst)
	{
		if (!ft_strcmp(room->nam, lst->nam))
			return (1);
		lst = lst->next;
	}
	return (0);
}

int		last_ant(t_mov *mov, int count)
{
	t_mov	*lst;

	lst = mov;
	while (lst)
	{
		if (lst->nb == count)
			return (1);
		lst = lst->next;
	}
	return (0);
}

void	put_mov_ant(t_grafik *g, t_ant *ant, t_course *cor, t_room *r)
{
	t_mov	*mov;

	mov = cor->mov;
	while (r)
	{
		if (mov && !ft_strcmp(r->nam, mov->nam))
		{
			mlx_put_image_to_window(g->mlx, g->win, g->image2,
				(r->x * g->con) + 25, (r->y * g->con) + 25);
			mlx_string_put(g->mlx, g->win, r->x * g->con + 25,
				r->y * g->con + 25, 0x00FF, ft_itoa(mov->nb));
			mov = mov->next;
			r = ft_beginroom(ant->room);
			continue;
		}
		else if (!room_is_clos(r, cor->mov) &&
		(ft_strcmp(r->nam, ant->start) || last_ant(cor->mov, ant->count)))
		{
			mlx_put_image_to_window(g->mlx, g->win, g->image,
					(r->x * g->con), (r->y * g->con));
			mlx_string_put(g->mlx, g->win, r->x * g->con + 50,
					r->y * g->con, 0xFF0000, r->nam);
		}
		r = r->next;
	}
}

void	mov_in_map(t_grafik *grafik, t_ant *ant, t_course *cor)
{
	t_room	*room;
	int		height;
	int		width;

	grafik->image2 = mlx_xpm_file_to_image(grafik->mlx,
						"tank.xpm", &width, &height);
	room = theroom_ant(ft_beginroom(ant->room), ant);
	mlx_put_image_to_window(grafik->mlx, grafik->win, grafik->image2,
			(room->x * grafik->con) + 25,
			(room->y * grafik->con) + 25);
	put_mov_ant(grafik, ant, cor, ft_beginroom(ant->room));
}
