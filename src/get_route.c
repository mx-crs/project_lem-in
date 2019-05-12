/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_route.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myarovoy <myarovoy@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 12:40:08 by myarovoy          #+#    #+#             */
/*   Updated: 2018/10/29 12:40:09 by myarovoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	ft_fill_shortest_route(int i, int *path, t_lemin *lemin)
{
	int		c;

	c = 0;
	lemin->s_route = malloc(sizeof(t_lem_move) * i + 1);
	lemin->s_room_cnt = i + 1;
	while (i >= 0)
	{
		lemin->s_route[c].lem = 0;
		lemin->s_route[c].room = lemin->rooms[path[i]].room;
		c++;
		i--;
	}
}

void	ft_trace_backpath(int *rooms, int p, t_lemin *lemin)
{
	int		path[lemin->room_cnt];
	int		i_n[2];
	int		room;
	t_link	*tmp;

	i_n[0] = 0;
	i_n[1] = -1;
	path[0] = lemin->end_ind;
	while (++(i_n[1]) < p)
	{
		tmp = lemin->rooms[rooms[i_n[1]]].link;
		room = rooms[i_n[1]];
		while (tmp)
		{
			if (tmp->room == path[i_n[0]])
			{
				path[++(i_n[0])] = room;
				p = i_n[1];
				i_n[1] = -1;
				break ;
			}
			tmp = tmp->next;
		}
	}
	ft_fill_shortest_route(i_n[0], path, lemin);
}

t_link	*ft_visit_rooms_init(t_lemin *lemin, char *visited,
							int *rooms, int *st_en)
{
	int		i;
	t_link	*curr;

	i = 0;
	st_en[0] = 0;
	st_en[1] = 1;
	while (i < lemin->room_cnt)
		visited[i++] = 0;
	rooms[0] = lemin->start_ind;
	visited[lemin->start_ind] = 1;
	curr = lemin->rooms[lemin->start_ind].link;
	return (curr);
}

t_link	*ft_curr_init(t_lemin *lemin, int *st_en, int *rooms)
{
	t_link *curr;

	curr = NULL;
	if ((st_en[0])++ < st_en[1])
		curr = lemin->rooms[rooms[(st_en[0]) - 1]].link;
	return (curr);
}

int		ft_take_route(t_lemin *lemin)
{
	char	visited[lemin->room_cnt];
	int		rooms[lemin->room_cnt];
	int		st_en[2];
	t_link	*curr;

	curr = ft_visit_rooms_init(lemin, visited, rooms, st_en);
	while (st_en[0] <= st_en[1])
	{
		while (curr)
		{
			if (visited[curr->room] != 1)
			{
				if (curr->room == lemin->end_ind)
				{
					ft_trace_backpath(rooms, st_en[1], lemin);
					return (1);
				}
				visited[curr->room] = 1;
				rooms[(st_en[1])++] = curr->room;
			}
			curr = curr->next;
		}
		curr = ft_curr_init(lemin, st_en, rooms);
	}
	return (0);
}
