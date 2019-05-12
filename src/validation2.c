/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myarovoy <myarovoy@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 14:33:53 by myarovoy          #+#    #+#             */
/*   Updated: 2018/10/29 14:33:54 by myarovoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int		ft_check_data(char *data)
{
	if (data[ft_strlen(data) - 1] == ' ' ||
		data[ft_strlen(data) - 1] == '-')
		return (0);
	if ((data[0] == '#' && data[1] == '#') ||
		data[0] == '-')
		return (0);
	return (1);
}

int		ft_good_links_line(char **data, t_room_coord *r_coord)
{
	int		i;
	int		cnt;
	char	**tmp;

	i = -1;
	while (data[++i])
	{
		if (!ft_check_data(data[i]))
			return (0);
		if (data[i][0] == '#')
			continue ;
		tmp = ft_strsplit(data[i], '-');
		if ((cnt = ft_take_str_cnt(tmp)) != 2 ||
			!ft_is_valid_link(tmp, r_coord) ||
			!ft_mirrored_links(tmp))
		{
			ft_free_mem(tmp);
			return (0);
		}
		ft_free_mem(tmp);
	}
	return (1);
}

int		ft_good_links(char **data, t_room_coord *r_coord)
{
	int		i;
	char	**tmp;
	int		cnt;

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
	if (!ft_good_links_line(data + i, r_coord))
		return (0);
	return (1);
}

void	ft_free_r_coord(t_room_coord *r_coord, int r_num)
{
	int		i;

	i = -1;
	while (++i < r_num)
		free(r_coord[i].room);
	free(r_coord);
}

int		ft_is_valid(char **data, t_room_coord *r_coord)
{
	int		i;
	int		r_num;

	i = -1;
	r_num = ft_get_number_of_rooms(data);
	r_coord = malloc(sizeof(t_room_coord) * r_num + 1);
	while (++i < r_num + 1)
		r_coord[i].room = NULL;
	if (r_num == 0 ||
		!ft_good_lem_num(data[0]) ||
		!ft_rooms_links_aparted(data) ||
		!ft_good_rooms(data, r_coord) ||
		!ft_nsame_coord(r_coord, r_num) ||
		!ft_good_links(data, r_coord))
	{
		ft_free_r_coord(r_coord, r_num);
		return (0);
	}
	ft_free_r_coord(r_coord, r_num);
	return (1);
}
