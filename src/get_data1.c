/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myarovoy <myarovoy@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 12:42:26 by myarovoy          #+#    #+#             */
/*   Updated: 2018/10/29 12:42:27 by myarovoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	ft_add_room(t_link *link, int ind)
{
	t_link *curr;

	curr = link;
	while (curr->next != NULL)
		curr = curr->next;
	curr->next = malloc(sizeof(t_link));
	curr->next->room = ind;
	curr->next->next = NULL;
}

void	ft_fill_first_link(t_lemin *lemin, int i, int ind)
{
	lemin->rooms[i].link = malloc(sizeof(t_link));
	lemin->rooms[i].link->room = ind;
	lemin->rooms[i].link->next = NULL;
}

void	ft_fill_links(t_lemin *lemin)
{
	int		i;
	char	**room;
	int		l;
	int		ind;

	i = 0;
	while (i < lemin->room_cnt)
		lemin->rooms[i++].link = NULL;
	i = -1;
	while (++i < lemin->room_cnt)
	{
		l = -1;
		while (lemin->links[++l])
		{
			room = ft_strsplit(lemin->links[l], '-');
			if ((ind = ft_fill_indexes(lemin->rooms[i], room, lemin)) != -1)
			{
				if (lemin->rooms[i].link == NULL)
					ft_fill_first_link(lemin, i, ind);
				else
					ft_add_room(lemin->rooms[i].link, ind);
			}
			ft_free_mem(room);
		}
	}
}

int		ft_get_cnt_of_links(t_lemin *lemin)
{
	int		i;
	int		cnt;

	cnt = 0;
	i = -1;
	while (lemin->input_data[++i])
	{
		if (ft_strchr(lemin->input_data[i], '-') &&
			lemin->input_data[i][0] != '#')
			cnt++;
	}
	return (cnt);
}

int		ft_get_links(t_lemin *lemin)
{
	int		k;
	int		cnt;

	k = -1;
	cnt = ft_get_cnt_of_links(lemin);
	lemin->links = malloc(sizeof(char*) * cnt);
	cnt = 0;
	while (lemin->input_data[++k])
	{
		if (ft_strchr(lemin->input_data[k], '-') &&
			lemin->input_data[k][0] != '#')
		{
			lemin->links[cnt] = ft_strdup(lemin->input_data[k]);
			cnt++;
		}
	}
	ft_exclude_same_links(lemin, cnt);
	ft_fill_links(lemin);
	return (1);
}
