/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max_params.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amovchan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/08 18:32:35 by amovchan          #+#    #+#             */
/*   Updated: 2017/06/08 18:32:38 by amovchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "grafik.h"

int		max_x(t_room *room)
{
	t_room	*lst;
	int		max;

	max = 0;
	lst = room;
	while (lst)
	{
		if (max < lst->x)
			max = lst->x;
		lst = lst->next;
	}
	return (max + 2);
}

int		max_y(t_room *room)
{
	t_room	*lst;
	int		max;

	max = 0;
	lst = room;
	while (lst)
	{
		if (max < lst->y)
			max = lst->y;
		lst = lst->next;
	}
	return (max + 2);
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
