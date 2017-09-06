/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grafik.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amovchan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/09 17:09:32 by amovchan          #+#    #+#             */
/*   Updated: 2017/06/09 17:38:03 by amovchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRAFIK_H
# define GRAFIK_H

# include <mlx.h>
# include "../libft/libft.h"
# include <math.h>

typedef struct		s_room
{
	char			*nam;
	int				x;
	int				y;
	struct s_room	*next;
	struct s_room	*previous;
}					t_room;

typedef struct		s_links
{
	char			*forst;
	char			*last;
	struct s_links	*next;
}					t_links;

typedef struct		s_mov
{
	int				nb;
	char			*nam;
	struct s_mov	*next;
}					t_mov;

typedef struct		s_course
{
	t_mov			*mov;
	struct s_course	*previous;
	struct s_course	*next;
}					t_course;

typedef struct		s_grafik
{
	void			*mlx;
	void			*win;
	void			*image;
	void			*image2;
	int				height;
	int				width;
	int				con;
	void			*ing_buf;
}					t_grafik;

typedef struct		s_ant
{
	int				count;
	char			*start;
	char			*end;
	t_links			*links;
	t_room			*room;
	t_grafik		*grafik;
	t_course		*course;
}					t_ant;

int					my_key_funct(int key, t_ant	*ant);
void				brezenhem(int *xy, t_grafik	*graf, int color);
long int			ft_atoilong(char *str);
int					ft_atoin(char *str, int *i);
t_room				*ft_room(char *str);
void				ft_isroom(char *lin, t_ant **ant, int start_end);
int					ft_valid_room(char *str);
int					ft_valid_links(char *str, t_ant **ant);
void				ft_links(char *lin, t_ant **ant);
void				mov_ant(char *str, t_ant **ant);
t_ant				*read_params(t_ant *ant);
int					max_y(t_room *room);
int					max_x(t_room *room);
t_room				*ft_beginroom(t_room *room);
void				put_links(t_ant *ant, t_grafik *graf);
void				mov_in_map(t_grafik *grafik, t_ant	*ant, t_course *cor);
void				ft_dellarrey(char **s);

#endif
