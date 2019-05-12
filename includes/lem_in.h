/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myarovoy <myarovoy@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/18 17:27:47 by myarovoy          #+#    #+#             */
/*   Updated: 2018/10/18 17:27:48 by myarovoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "../src/libft/includes/libft.h"
# include <stdio.h>

typedef struct		s_link
{
	int				room;
	struct s_link	*next;
}					t_link;

typedef struct		s_route
{
	char			*room;
	t_link			*link;
}					t_route;

typedef struct		s_lem_move
{
	char			*room;
	int				lem;
}					t_lem_move;

typedef struct		s_room_coord
{
	char			*room;
	long long int	x;
	long long int	y;
}					t_room_coord;

typedef struct		s_lemin
{
	int				lem_cnt;
	int				room_cnt;
	t_route			*rooms;
	char			*start;
	int				start_ind;
	int				end_ind;
	char			*end;
	char			*str_links;
	char			*raw_room;
	char			**links;
	char			**input_data;
	char			*data;
	t_lem_move		*s_route;
	int				s_room_cnt;
}					t_lemin;

void				ft_print_filled_rooms(t_lemin *lemin);
void				ft_error(void);
int					ft_fill_struct(t_lemin *lemin, t_room_coord	*r_coord);

void				ft_fill_start_end(t_lemin *lemin, char ***str, int i);
void				ft_fill_with_tips(t_lemin *lemin);
void				ft_free_mem(char **str);
int					ft_take_str_cnt(char **str);
int					ft_cnt_rooms(t_lemin *lemin);
int					ft_get_tips(t_lemin *lemin);

int					ft_fill_rooms(t_lemin *lemin);
int					ft_fill_indexes(t_route rooms, char **room, t_lemin *lemin);

void				ft_clear_links(t_lemin *lemin, int l_cnt);
void				ft_fill_links_mirrored(char **links_mirr);
void				ft_exclude_same_links(t_lemin *lemin, int l_cnt);
void				ft_add_room(t_link *link, int ind);
void				ft_fill_first_link(t_lemin *lemin, int i, int ind);
void				ft_fill_links(t_lemin *lemin);
int					ft_get_task_links(t_lemin *lemin);
int					ft_get_task(t_lemin *lemin);
int					ft_get_cnt_of_links(t_lemin *lemin);
int					ft_get_links(t_lemin *lemin);

void				ft_fill_shortest_route(int i, int *path, t_lemin *lemin);
void				ft_trace_backpath(int *rooms, int p, t_lemin *lemin);
t_link				*ft_visit_rooms_init(t_lemin *lemin, char *visited,
							int *rooms, int *st_en);
t_link				*ft_curr_init(t_lemin *lemin, int *st_en, int *rooms);
int					ft_take_route(t_lemin *lemin);

void				ft_lems_init(t_lemin *lemin, int *lems);
void				ft_move_lem(t_lemin *lemin);
void				ft_get_lem(int *lems, t_lemin *lemin);
void				ft_move_forward(t_lemin *lemin);
int					ft_is_lems_in_heap(int *lems, int lem_cnt);
int					ft_is_lems_in_rooms(t_lemin *lemin);
int					ft_is_next_lem(t_lem_move *s_route, int i);

char				**ft_fill_s_e_tmp(int *cnt, int *s_e, char *data);
void				ft_fill_r_coord(t_room_coord *r_coord, char *room,
						long long int x, long long int y);
void				ft_free_r_coord(t_room_coord *r_coord, int r_num);
int					ft_good_command(int cnt, char **tmp);
int					ft_good_com(char **data);
int					ft_good_rooms(char **data, t_room_coord *r_coord);
int					ft_good_lem_num(char *lem_num);
int					ft_r_c_name(char **room, t_room_coord *r_coord);
int					ft_get_number_of_rooms(char **data);
int					ft_nsame_coord(t_room_coord *r_coord, int r_num);
int					ft_check_data(char *data);
int					ft_good_links_line(char **data, t_room_coord *r_coord);
int					ft_good_links(char **data, t_room_coord *r_coord);
int					ft_is_valid(char **data, t_room_coord *r_coord);
int					ft_iterate_till_link(char **data);
int					ft_rooms_links_aparted(char **data);
int					ft_is_valid_link(char **tmp, t_room_coord *r_coord);
int					ft_mirrored_links(char **rooms);
int					ft_is_good_num_of_lem(char *str);
int					ft_is_good_gnl_line(char *str, char *tmp);

#endif
