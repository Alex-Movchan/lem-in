/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoilong.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amovchan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/08 17:28:20 by amovchan          #+#    #+#             */
/*   Updated: 2017/06/08 17:28:22 by amovchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

long int	ft_atoilong(char *str)
{
	long int	nbr;
	long int	negativ;
	int			i;

	i = 0;
	negativ = 1;
	nbr = 0;
	if (str[i] == '-')
		negativ = -1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		nbr *= 10;
		nbr += ((long int)str[i] - 48);
		i++;
	}
	return (nbr * negativ);
}

int			ft_atoin(char *str, int *i)
{
	int		nbr;
	int		negativ;

	negativ = 1;
	nbr = 0;
	if (str[(*i)] == ' ')
		(*i)++;
	if (str[(*i)] == '-')
		negativ = -1;
	if (str[(*i)] == '+' || str[(*i)] == '-')
		(*i)++;
	while (str[(*i)] >= '0' && str[(*i)] <= '9')
	{
		if (str[(*i)] < 33)
			break ;
		nbr *= 10;
		nbr += ((int)str[(*i)] - 48);
		(*i)++;
	}
	return (nbr * negativ);
}

int			ft_serch_free(int elem, t_elem *src, t_links *link)
{
	t_elem	*leaks;

	while (link->elem->next)
	{
		if (src->next->elem == elem)
		{
			leaks = src->next;
			src->next = NULL;
			free(leaks);
			return (0);
		}
		src = src->next;
	}
	return (1);
}

void		ft_overelem(t_elem *src, int elem, t_links *link, t_links **links)
{
	while (src)
	{
		if (src->elem == elem)
			break ;
		if (!ft_search_link(link, src->elem))
			ft_elemlink(src->elem, links);
		src = src->next;
	}
}

void		ft_ncpylink(int elem, t_links **links)
{
	t_elem	*src;
	t_links	*link;

	link = *links;
	if (!link->next)
	{
		src = link->elem;
		if (!ft_serch_free(elem, src, link))
			return ;
	}
	if (ft_search_link(*links, elem) && elem != 0)
	{
		while (link->next)
			link = link->next;
		src = link->elem;
		if (!ft_serch_free(elem, src, link))
			return ;
	}
	while (link->next->next)
		link = link->next;
	src = link->elem;
	return (ft_overelem(src, elem, link, links));
}
