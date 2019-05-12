/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myarovoy <myarovoy@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 14:33:43 by myarovoy          #+#    #+#             */
/*   Updated: 2018/10/29 14:33:44 by myarovoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int		ft_good_lem_num(char *lem_num)
{
	int					i;
	long long int		num;

	i = 0;
	while (lem_num[i])
	{
		if ((i == 0 && lem_num[i] == '0') || !ISDIGIT(lem_num[i]))
			return (0);
		i++;
	}
	num = ft_atoi(lem_num);
	if (num == 0 || num > 100000)
		return (0);
	return (1);
}

void	ft_fill_r_coord(t_room_coord *r_coord, char *room,
						long long int x, long long int y)
{
	int		i;

	i = 0;
	while (r_coord[i].room)
		i++;
	r_coord[i].room = ft_strdup(room);
	r_coord[i].x = x;
	r_coord[i].y = y;
}

int		ft_r_c_name(char **room, t_room_coord *r_coord)
{
	long long int	coord;
	long long int	coord1;
	int				i;

	i = -1;
	if (room[0][0] == 'L')
		return (0);
	while (room[1][++i])
	{
		if (!ISDIGIT(room[1][i]))
			return (0);
	}
	i = -1;
	while (room[2][++i])
	{
		if (!ISDIGIT(room[1][i]))
			return (0);
	}
	coord = ft_atoi(room[1]);
	coord1 = ft_atoi(room[2]);
	if ((coord > 100000) || (coord < -100000) ||
		(coord1 > 100000) || (coord1 < -100000))
		return (0);
	ft_fill_r_coord(r_coord, room[0], coord, coord1);
	return (1);
}

int		ft_get_number_of_rooms(char **data)
{
	int		i;
	int		cnt;
	int		r_cnt;
	char	**tmp;

	i = -1;
	r_cnt = 0;
	while (data[++i])
	{
		if (ft_strchr(data[i], '-') && data[i][0] != '#')
			break ;
		if (data[i][0] == '#')
			continue ;
		tmp = ft_strsplit(data[i], ' ');
		cnt = ft_take_str_cnt(tmp);
		if (cnt == 3 && tmp[0][0] != '#')
			r_cnt++;
		ft_free_mem(tmp);
	}
	return (r_cnt);
}

int		ft_nsame_coord(t_room_coord *r_coord, int r_num)
{
	int		i;
	int		k;

	i = -1;
	while (++i < r_num)
	{
		k = i;
		while (++k < r_num)
		{
			if (!ft_strcmp(r_coord[i].room, r_coord[k].room) ||
			((r_coord[i].x == r_coord[k].x) && (r_coord[i].y == r_coord[k].y)))
				return (0);
		}
	}
	return (1);
}
