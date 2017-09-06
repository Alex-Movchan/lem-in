/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amovchan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/08 17:56:51 by amovchan          #+#    #+#             */
/*   Updated: 2017/06/08 17:56:53 by amovchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "grafik.h"

t_ant	*strukt_ant(t_ant *ant)
{
	ant = (t_ant*)malloc(sizeof(t_ant));
	ant->count = 0;
	ant->end = NULL;
	ant->start = NULL;
	ant->room = NULL;
	ant->links = NULL;
	ant->course = NULL;
	return (ant);
}

int		my_key_funct(int key, t_ant *ant)
{
	if (key == 53)
		exit(0);
	if (key == 124)
	{
		if (ant->course)
		{
			mov_in_map(ant->grafik, ant, ant->course);
			if (ant->course->next)
				ant->course = ant->course->next;
		}
		return (1);
	}
	else if (key == 123)
	{
		if (ant->course)
		{
			if (ant->course->previous)
				ant->course = ant->course->previous;
			mov_in_map(ant->grafik, ant, ant->course);
		}
		return (1);
	}
	else
		return (0);
}

int		lenwindiw(int len)
{
	if (len > 0 && len <= 10)
		return (100);
	else if (len > 10 && len <= 400)
		return (10);
	else
		return (1);
}

void	room_inmap(t_room *lst, t_grafik *grafik, t_ant *ant)
{
	put_links(ant, grafik);
	while (lst)
	{
		mlx_put_image_to_window(grafik->mlx, grafik->win, grafik->image,
			(lst->x * grafik->con), (lst->y * grafik->con));
		mlx_string_put(grafik->mlx, grafik->win, lst->x * grafik->con + 50,
				lst->y * grafik->con, 0xFF0000, lst->nam);
		lst = lst->next;
	}
}

int		main(void)
{
	t_grafik	*grafik;
	t_ant		*ant;
	int			x;
	int			y;

	ant = read_params(strukt_ant(NULL));
	if (!ant->count || !ant->room || !ant->course)
		return (0);
	grafik = (t_grafik*)malloc(sizeof(t_grafik));
	grafik->mlx = mlx_init();
	ant->grafik = grafik;
	x = lenwindiw(max_x(ft_beginroom(ant->room)));
	y = lenwindiw(max_y(ft_beginroom(ant->room)));
	grafik->con = x > y ? x : y;
	grafik->win = mlx_new_window(grafik->mlx, (max_x(ft_beginroom(ant->room)) +
			10) * grafik->con, (max_y(ft_beginroom(ant->room)) + 10)
				* grafik->con, "MLX TEST");
	grafik->image = mlx_xpm_file_to_image(grafik->mlx,
			"kyct.xpm", &grafik->width, &grafik->height);
	room_inmap(ft_beginroom(ant->room), grafik, ant);
	mlx_key_hook(grafik->win, my_key_funct, ant);
	mlx_loop(grafik->mlx);
	return (0);
}
