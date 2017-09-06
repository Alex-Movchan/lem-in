/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amovchan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/09 17:01:34 by amovchan          #+#    #+#             */
/*   Updated: 2017/06/10 18:19:38 by amovchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "../libft/libft.h"

typedef struct		s_room
{
	int				nbr;
	int				ant;
	char			*nam;
	int				x;
	int				y;
	struct s_room	*next;
	struct s_room	*previous;
}					t_room;

typedef struct		s_ant
{
	int				count;
	char			*start;
	char			*end;
	t_room			*room;
}					t_ant;

typedef struct		s_elem
{
	int				ant;
	int				elem;
	struct s_elem	*previous;
	struct s_elem	*next;
}					t_elem;

typedef struct		s_links
{
	int				stop;
	t_elem			*elem;
	struct s_links	*next;
}					t_links;

typedef struct		s_params
{
	char			*str;
	struct s_params	*next;
}					t_params;

void				fastmov(t_ant *ant);
t_links				*goodlinks(t_links *links, int count);
t_elem				*lastelems(t_elem *lst);
void				ant_on_map(t_links *links, t_ant *ant);
void				printmov(t_links *link, t_ant *ant);
void				get_params(char *str, t_params **params);
void				print_params(t_params *params);
t_links				*ant_on_links(t_links *links);
t_ant				*strukt_ant(t_ant *ant);
int					ft_read_params(t_ant **ant, char ***links,
							int start_end, t_params **params);
long int			ft_atoilong(char *str);
int					ft_valid_room(char *str);
t_room				*ft_room(char *str);
int					ft_atoin(char *str, int *i);
int					ft_isroom(char *lin, t_ant **ant, int start_end);
t_room				*ft_beginroom(t_room *room);
t_room				*good_room(t_ant **ant);
int					ft_valid_links(char *str, t_ant **ant);
int					count_room(t_room *room);
char				**ft_links(char *str, t_ant **ant, char **map);
int					sizeareey(char **av);
int					valid_finish_params(char **links);
t_links				*ft_bfs_ant(char **links, int i, t_links *link, int end);
t_links				*next_link(t_links *link);
void				ft_search_links(char **links, t_ant *ant);
void				ft_elemlink(int elems, t_links **links);
int					ft_search_link(t_links *link, int end);
void				ft_ncpylink(int elem, t_links **links);
char				*ft_dd_links(char **map, char *str, int *i);
int					lenlinks(t_links *links);
int					nova_links(t_elem *s2, t_elem *s1);
t_links				*dellinks(t_links *links, t_elem *dublikat);
t_links				*intersection_way2(t_links *way);
t_links				*stop_links(t_links *links);
int					counllinks(t_elem *lst);
t_links				*sortlink(t_links *links);
void				ft_dellarrey(char **s);
void				dell_t_links(t_links *lst);
int					start_room(char **lin, int *start_end,
						t_ant **ant, t_params **params);
int					end_room(char **lin, int *start_end,
								t_ant **ant, t_params **params);

#endif
