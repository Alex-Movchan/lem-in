/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_links.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amovchan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/08 17:53:03 by amovchan          #+#    #+#             */
/*   Updated: 2017/06/08 17:53:05 by amovchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "grafik.h"

void	ft_links(char *lin, t_ant **ant)
{
	char	**s;
	t_links	*links;

	s = ft_strsplit(lin, '-');
	if (!(*ant)->links)
	{
		(*ant)->links = (t_links *)malloc(sizeof(t_links));
		(*ant)->links->next = NULL;
		links = (*ant)->links;
	}
	else
	{
		links = (*ant)->links;
		while (links->next)
			links = links->next;
		links->next = (t_links *)malloc(sizeof(t_links));
		links = links->next;
		links->next = NULL;
	}
	links->forst = ft_strdup(s[0]);
	links->last = ft_strdup(s[1]);
	ft_dellarrey(s);
}
