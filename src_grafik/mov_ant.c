/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mov_ant.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amovchan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/08 18:34:33 by amovchan          #+#    #+#             */
/*   Updated: 2017/06/08 18:34:34 by amovchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "grafik.h"

int		len_nam(char *str, int *i)
{
	int j;

	if (str[*i] == '-')
		(*i)++;
	j = *i;
	while (str[j] && str[j] != ' ')
		j++;
	return (j);
}

char	*strcpy_len(char *src, char *dst, int *i)
{
	int	j;

	j = -1;
	while (dst[(*i)] && dst[(*i)] != ' ')
	{
		src[++j] = dst[(*i)];
		(*i)++;
	}
	while (dst[(*i)] && dst[(*i)] < 33)
		(*i)++;
	src[++j] = '\0';
	return (src);
}

t_mov	*ft_mov(char *str, t_mov *mov)
{
	t_mov	*lst;
	int		i;

	i = 0;
	mov = (t_mov*)malloc(sizeof(t_mov));
	mov->next = NULL;
	lst = mov;
	while (str[i])
	{
		lst->nb = ft_atoin(str, &i);
		lst->nam = strcpy_len(ft_strnew((size_t)len_nam(str, &i)), str, &i);
		if (str[i])
		{
			lst->next = (t_mov*)malloc(sizeof(t_mov));
			lst = lst->next;
			lst->next = NULL;
		}
	}
	return (mov);
}

void	mov_ant(char *str, t_ant **ant)
{
	t_course	*course;

	if (!(*ant)->course)
	{
		(*ant)->course = (t_course*)malloc(sizeof(t_course));
		(*ant)->course->next = NULL;
		(*ant)->course->previous = NULL;
		course = (*ant)->course;
	}
	else
	{
		course = (*ant)->course;
		while (course->next)
			course = course->next;
		course->next = (t_course*)malloc(sizeof(t_course));
		course->next->previous = course;
		course = course->next;
		course->next = NULL;
	}
	course->mov = ft_mov(str, NULL);
}
