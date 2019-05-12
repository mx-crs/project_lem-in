/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_links1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myarovoy <myarovoy@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 12:55:37 by myarovoy          #+#    #+#             */
/*   Updated: 2018/10/29 12:55:38 by myarovoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	ft_free_mem(char **str)
{
	int i;

	if (str == NULL)
		return ;
	i = 0;
	while (str[i])
		free(str[i++]);
	free(str);
}

int		ft_fill_rooms(t_lemin *lemin)
{
	int		i;
	int		r;
	char	**str;

	r = 0;
	i = -1;
	lemin->rooms = malloc(sizeof(t_route) * lemin->room_cnt);
	while (lemin->input_data[++i])
	{
		if (lemin->input_data[i][0] == '#')
			continue ;
		if (ft_strchr(lemin->input_data[i], '-'))
			break ;
		str = ft_strsplit(lemin->input_data[i], ' ');
		if (ft_take_str_cnt(str) == 3 && str[0][0] != '#')
		{
			lemin->rooms[r].room = ft_strdup(str[0]);
			r++;
		}
		ft_free_mem(str);
	}
	ft_fill_with_tips(lemin);
	return (1);
}

int		ft_fill_indexes(t_route rooms, char **room, t_lemin *lemin)
{
	int		i;
	int		ind;

	ind = 0;
	i = 0;
	if (ft_strcmp(room[0], rooms.room) && ft_strcmp(room[1], rooms.room))
		i = -1;
	if (i == 0)
		i = (!ft_strcmp(room[0], rooms.room)) ? 1 : 0;
	if (i == -1)
		return (-1);
	while (ind < lemin->room_cnt)
	{
		if (!ft_strcmp(room[i], lemin->rooms[ind].room))
			break ;
		ind++;
	}
	return (ind);
}
