/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myarovoy <myarovoy@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 14:36:00 by myarovoy          #+#    #+#             */
/*   Updated: 2018/10/29 14:36:01 by myarovoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int		ft_iterate_till_link(char **data)
{
	int		i;
	int		cnt;
	char	**tmp;

	i = 0;
	while (data[++i])
	{
		tmp = ft_strsplit(data[i], ' ');
		if (tmp[0][0] != '#' && ft_strchr(tmp[0], '-') &&
			(cnt = ft_take_str_cnt(tmp)) == 1)
		{
			ft_free_mem(tmp);
			break ;
		}
		ft_free_mem(tmp);
	}
	return (i);
}

int		ft_rooms_links_aparted(char **data)
{
	int		i;
	int		cnt;
	char	**tmp;

	i = ft_iterate_till_link(data);
	if (!data[i])
		return (0);
	while (data[++i])
	{
		tmp = ft_strsplit(data[i], ' ');
		if (tmp[0][0] != '#' && (!ft_strchr(tmp[0], '-') ||
					(cnt = ft_take_str_cnt(tmp)) != 1))
		{
			ft_free_mem(tmp);
			return (0);
		}
		ft_free_mem(tmp);
	}
	return (1);
}

int		ft_is_valid_link(char **tmp, t_room_coord *r_coord)
{
	int		i;
	int		l_r[2];

	l_r[0] = 0;
	l_r[1] = 0;
	i = -1;
	while (r_coord[++i].room)
	{
		if (!ft_strcmp(r_coord[i].room, tmp[0]))
			l_r[0] += 1;
		if (!ft_strcmp(r_coord[i].room, tmp[1]))
			l_r[1] += 1;
		if (l_r[0] && l_r[1])
			break ;
	}
	if (l_r[0] != 1 | l_r[1] != 1)
		return (0);
	return (1);
}

int		ft_mirrored_links(char **rooms)
{
	if (!rooms || ft_take_str_cnt(rooms) != 2)
		return (0);
	if (!ft_strcmp(rooms[0], rooms[1]))
		return (0);
	return (1);
}

int		ft_is_good_num_of_lem(char *str)
{
	if (ft_strlen(str) > 6 || ft_strlen(str) == 0)
	{
		free(str);
		return (0);
	}
	return (1);
}
