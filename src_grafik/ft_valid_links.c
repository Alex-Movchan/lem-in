/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_valid_links.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amovchan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/08 17:53:36 by amovchan          #+#    #+#             */
/*   Updated: 2017/06/08 17:53:42 by amovchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "grafik.h"

int		ft_ishyphen(char *str)
{
	int i;

	i = -1;
	while (str[++i])
		if (str[i] == '-')
			return (1);
	return (0);
}

int		sizeareey(char **av)
{
	int	i;

	i = 0;
	while (av[i])
		i++;
	return (i);
}

int		ft_namroom(char *str, t_room *room)
{
	t_room	*lst;

	lst = room;
	while (lst)
	{
		if (!ft_strcmp(str, lst->nam))
			return (1);
		lst = lst->next;
	}
	return (0);
}

t_room	*ft_beginroom(t_room *room)
{
	t_room	*lst;

	lst = room;
	while (lst->previous != NULL)
		lst = lst->previous;
	return (lst);
}

int		ft_valid_links(char *str, t_ant **ant)
{
	char	**s1;

	if (!ft_ishyphen(str) || str[0] == 'L')
		return (0);
	s1 = ft_strsplit(str, '-');
	if (sizeareey(s1) != 2)
		return (0);
	if (!ft_namroom(s1[0], ft_beginroom((*ant)->room)) ||
			!ft_namroom(s1[1], ft_beginroom((*ant)->room)))
	{
		ft_dellarrey(s1);
		return (0);
	}
	ft_dellarrey(s1);
	return (1);
}
