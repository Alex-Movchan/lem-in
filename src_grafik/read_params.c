/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_params.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amovchan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/08 19:26:52 by amovchan          #+#    #+#             */
/*   Updated: 2017/06/10 17:27:18 by amovchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "grafik.h"

int		ft_countant(char *str, t_ant **ant)
{
	int		i;

	i = -1;
	while (str[++i])
		if (!ft_isdigit((int)str[i]))
			return (0);
	if (ft_atoilong(str) <= 0 || ft_atoilong(str) > 2147483647)
		return (0);
	else
		(*ant)->count = ft_atoi(str);
	return (1);
}

void	ft_valid(char *lin, t_ant **ant, int start_end)
{
	if (ft_countant(lin, ant))
		return (free(lin));
	else if (ft_valid_room(lin))
	{
		ft_isroom(lin, ant, start_end);
		return (free(lin));
	}
	else if (ft_valid_links(lin, ant))
	{
		ft_links(lin, ant);
		return (free(lin));
	}
	else
	{
		mov_ant(lin, ant);
		return (free(lin));
	}
}

int		start_endroom(char *lin, int *start_end)
{
	if (!ft_strcmp(lin, "##start"))
	{
		*start_end = 1;
		free(lin);
		return (1);
	}
	else if (!ft_strcmp(lin, "##end"))
	{
		*start_end = 2;
		free(lin);
		return (1);
	}
	return (0);
}

t_ant	*read_params(t_ant *ant)
{
	char	*lin;
	int		start_end;

	start_end = 0;
	while (get_next_line(0, &lin))
	{
		if (!ft_strcmp(lin, "\033[0;31mERROR\033[0m"))
		{
			ft_printf("{red}ERROR{eoc}\n");
			free(lin);
			exit(0);
		}
		else if (start_endroom(lin, &start_end))
			continue ;
		else if (lin[0] == '#' || lin[0] == '\0')
		{
			free(lin);
			continue ;
		}
		ft_valid(lin, &ant, start_end);
		start_end = 0;
	}
	free(lin);
	return (ant);
}
