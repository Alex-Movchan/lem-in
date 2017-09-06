/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amovchan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/09 16:08:44 by amovchan          #+#    #+#             */
/*   Updated: 2017/06/10 17:17:44 by amovchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_ant	*strukt_ant(t_ant *ant)
{
	ant = (t_ant*)malloc(sizeof(t_ant));
	ant->count = 0;
	ant->end = NULL;
	ant->start = NULL;
	ant->room = NULL;
	return (ant);
}

int		main(void)
{
	t_ant		*ant;
	char		**links;
	t_params	*params;

	ant = NULL;
	links = NULL;
	ant = strukt_ant(ant);
	if (!ft_read_params(&ant, &links, 0, &params))
	{
		ft_printf("{red}ERROR{eoc}\n");
		return (0);
	}
	print_params(params);
	ft_search_links(links, ant);
	return (0);
}
