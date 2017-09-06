/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brezenhem.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amovchan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/08 18:10:53 by amovchan          #+#    #+#             */
/*   Updated: 2017/06/08 18:10:54 by amovchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "grafik.h"

void	put_pixel_brezenhem(int **tab, t_grafik *graf,
					int color, double **dx_error)
{
	while (1)
	{
		if (tab[1][0] == tab[0][2] && tab[1][1] == tab[0][3])
			break ;
		mlx_pixel_put(graf->mlx, graf->win, tab[1][0], tab[1][1], color);
		dx_error[1][1] = dx_error[1][0];
		if (dx_error[1][1] > -dx_error[0][0])
		{
			dx_error[1][0] -= dx_error[0][1];
			tab[1][0] += tab[2][0];
		}
		if (dx_error[1][1] < dx_error[0][1])
		{
			dx_error[1][0] += dx_error[0][0];
			tab[1][1] += tab[2][1];
		}
	}
	free(tab);
}

void	brezenhem(int *xy, t_grafik *graf, int color)
{
	int		sign[2];
	int		yx[2];
	double	**dx_eror;
	int		**tab;

	dx_eror = (double**)malloc(sizeof(double*) * 2);
	dx_eror[0] = (double*)malloc(sizeof(double) * 2);
	dx_eror[1] = (double*)malloc(sizeof(double) * 2);
	dx_eror[0][0] = abs(xy[2] - xy[0]);
	dx_eror[0][1] = abs(xy[3] - xy[1]);
	sign[0] = (xy[0] < xy[2]) ? 1 : -1;
	sign[1] = (xy[1] < xy[3]) ? 1 : -1;
	yx[0] = xy[0];
	yx[1] = xy[1];
	tab = (int**)malloc(sizeof(int*) * 3);
	tab[0] = xy;
	tab[1] = yx;
	tab[2] = sign;
	dx_eror[1][0] = (dx_eror[0][0] >
						dx_eror[0][1] ? dx_eror[0][0] : -dx_eror[0][1]) / 2;
	put_pixel_brezenhem(tab, graf, color, dx_eror);
	free(dx_eror[0]);
	free(dx_eror[1]);
	free(dx_eror);
}
