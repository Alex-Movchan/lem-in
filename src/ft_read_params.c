/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amovchan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/08 20:07:36 by amovchan          #+#    #+#             */
/*   Updated: 2017/06/10 17:19:27 by amovchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		ft_countant(char *str, t_ant **ant, char **map)
{
	int		i;

	i = -1;
	while (str[++i])
		if (!ft_isdigit((int)str[i]))
			return (0);
	if (ft_atoilong(str) <= 0 || ft_atoilong(str) > 2147483647)
		return (0);
	if ((*ant)->room || map != NULL || (*ant)->start || (*ant)->end)
		return (0);
	if ((*ant)->count != 0)
		return (0);
	else
		(*ant)->count = ft_atoi(str);
	return (1);
}

int		ft_valid(char *lin, t_ant **ant, int start_end, char **map)
{
	if (lin[0] == '\0')
		return (0);
	else if (ft_countant(lin, ant, map))
		return (1);
	else if (ft_valid_room(lin) && (*ant)->count != 0 && map == NULL)
		if (ft_isroom(lin, ant, start_end) == 1)
			return (1);
	return (0);
}

int		ft_valid_params(char *lin, t_ant **ant, int start_end, char ***links)
{
	char	**map;

	if (!ft_valid(lin, ant, start_end, *links))
	{
		map = *links;
		if (!(*links = ft_links(lin, ant, *links)))
		{
			*links = map;
			return (0);
		}
	}
	return (1);
}

int		ft_read_params(t_ant **ant, char ***links, int start_end, t_params **p)
{
	char	*lin;

	lin = NULL;
	while ((get_next_line(0, &lin)) > 0)
	{
		if (lin[0] == 'L' || lin[0] == '\0' || !lin)
			break ;
		else if (end_room(&lin, &start_end, ant, p) ||
				start_room(&lin, &start_end, ant, p))
			break ;
		else if (lin[0] == '#')
		{
			get_params(lin, p);
			continue ;
		}
		if (!ft_valid_params(lin, ant, start_end, links))
			break ;
		start_end = 0;
		get_params(lin, p);
	}
	if (lin && lin[0] != '\0')
		ft_strdel(&lin);
	if (!valid_finish_params(*links))
		return (0);
	return (1);
}

void	fastmov(t_ant *ant)
{
	int count;

	count = 1;
	while (count <= ant->count)
	{
		ft_printf("L%d-%s ", count, ant->end);
		count++;
	}
	ft_printf("\n");
}
