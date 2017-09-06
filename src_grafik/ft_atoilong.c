/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoilong.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amovchan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/08 18:28:23 by amovchan          #+#    #+#             */
/*   Updated: 2017/06/08 18:28:25 by amovchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "grafik.h"

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

	nbr = 0;
	while (str[(*i)] == 'L' || str[(*i)] == ' ')
		(*i)++;
	while (str[(*i)] >= '0' && str[(*i)] <= '9')
	{
		if (str[(*i)] < 33)
			break ;
		nbr *= 10;
		nbr += ((int)str[(*i)] - 48);
		(*i)++;
	}
	return (nbr);
}
