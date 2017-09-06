/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_finish_params.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amovchan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/09 16:07:44 by amovchan          #+#    #+#             */
/*   Updated: 2017/06/09 16:07:45 by amovchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

char	*ft_dd_links2(char **map, char *str, int *i)
{
	int		j;
	char	c;

	if (ft_strchr(str, ((char)i[2] + 48)) && ft_strchr(str, '0'))
		return (str);
	j = -1;
	while (map[++j])
	{
		c = (char)(j + 48);
		if (map[j][i[0]] == '1' && !ft_strchr(str, c))
		{
			str[i[1]++] = c;
			str[i[1]] = '\0';
			if (j == 0)
				continue ;
			i[0] = j;
			str = ft_dd_links2(map, str, i);
			if ((!ft_strchr(str, ((char)i[2] + 48)) ||
					!ft_strchr(str, '0')) && j > 0)
				str = ft_dd_links(map, str, i);
		}
	}
	return (str);
}

char	*ft_dd_links(char **map, char *str, int *i)
{
	int		j;
	char	c;

	if (ft_strchr(str, ((char)i[2] + 48)) && ft_strchr(str, '0'))
		return (str);
	j = -1;
	while (map[i[0]][++j])
	{
		c = (char)(j + 48);
		if (map[i[0]][j] == '1' && !ft_strchr(str, c))
		{
			str[i[1]++] = c;
			str[i[1]] = '\0';
			i[0] = j > 0 ? j : i[0];
			str = ft_dd_links(map, str, i);
			i[0] = j;
			if (ft_strchr(str, ((char)i[2] + 48)) == NULL ||
					!ft_strchr(str, '0'))
				str = ft_dd_links2(map, str, i);
		}
	}
	return (str);
}

int		valid_finish_params(char **links)
{
	char	*str;
	int		i[3];

	if (!links)
		return (0);
	i[2] = sizeareey(links);
	str = (char *)malloc(sizeof(char) * i[2]);
	i[2]--;
	i[0] = 0;
	i[1] = 0;
	str = ft_dd_links(links, str, i);
	if (ft_strchr(str, ((char)i[2] + 48)) && ft_strchr(str, '0'))
	{
		ft_strdel(&str);
		return (1);
	}
	ft_strdel(&str);
	return (0);
}
