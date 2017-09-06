/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_params.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amovchan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/09 16:08:25 by amovchan          #+#    #+#             */
/*   Updated: 2017/06/09 16:08:26 by amovchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	get_params(char *str, t_params **params)
{
	t_params	*lst;

	if (!*params)
	{
		(*params) = (t_params*)malloc(sizeof(t_params));
		(*params)->next = NULL;
		lst = *params;
	}
	else
	{
		lst = *params;
		while (lst->next)
			lst = lst->next;
		lst->next = (t_params*)malloc(sizeof(t_params));
		lst = lst->next;
		lst->next = NULL;
	}
	lst->str = ft_strdup(str);
	free(str);
}

void	print_params(t_params *params)
{
	while (params)
	{
		ft_printf("%s\n", params->str);
		params = params->next;
	}
	ft_printf("\n");
}
