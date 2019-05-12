/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myarovoy <myarovoy@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 12:35:51 by myarovoy          #+#    #+#             */
/*   Updated: 2018/10/29 12:35:53 by myarovoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int		ft_is_good_gnl_line(char *str, char *tmp)
{
	if (ft_strlen(str) == 0)
	{
		free(tmp);
		free(str);
		return (0);
	}
	return (1);
}

int		ft_good_command(int cnt, char **tmp)
{
	if (cnt == 1)
	{
		if (ft_strlen(tmp[0]) > 2 && (tmp[0][0] == '#' && tmp[0][1] == '#'))
		{
			if (ft_strcmp("##end", tmp[0]) && ft_strcmp("##start", tmp[0]))
				return (0);
		}
	}
	else if (cnt > 1)
	{
		if (ft_strlen(tmp[0]) > 2 && (tmp[0][0] == '#' && tmp[0][1] == '#'))
			return (0);
	}
	return (1);
}

char	**ft_fill_s_e_tmp(int *cnt, int *s_e, char *data)
{
	char	**tmp;

	tmp = ft_strsplit(data, ' ');
	if ((*cnt = ft_take_str_cnt(tmp)) == 1 && !ft_strcmp("##start", tmp[0]))
		s_e[0] += 1;
	else if (*cnt == 1 && !ft_strcmp("##end", tmp[0]))
		s_e[1] += 1;
	return (tmp);
}

int		ft_good_com(char **data)
{
	int		i;
	int		cnt;
	char	**tmp;
	int		s_e[2];

	i = 0;
	s_e[0] = 0;
	s_e[1] = 0;
	while (data[++i])
	{
		tmp = ft_fill_s_e_tmp(&cnt, s_e, data[i]);
		if ((cnt != 1 && (!ft_strcmp("##end", tmp[0]) ||
							!ft_strcmp("##start", tmp[0]))) ||
							!ft_good_command(cnt, tmp))
		{
			ft_free_mem(tmp);
			return (0);
		}
		ft_free_mem(tmp);
		if (ft_strchr(data[i], '-') && data[i][0] != '#')
			break ;
	}
	if (s_e[0] != 1 || s_e[1] != 1)
		return (0);
	return (1);
}

int		ft_good_rooms(char **data, t_room_coord *r_coord)
{
	int		i;
	int		cnt;
	char	**tmp;

	if (!ft_good_com(data))
		return (0);
	i = 0;
	while (data[++i])
	{
		if (data[i][ft_strlen(data[i]) - 1] == ' ')
			return (0);
		if (ft_strchr(data[i], '-') && data[i][0] != '#')
			break ;
		if (data[i][0] == '#')
			continue ;
		tmp = ft_strsplit(data[i], ' ');
		cnt = ft_take_str_cnt(tmp);
		if (cnt != 3 || !ft_r_c_name(tmp, r_coord))
		{
			ft_free_mem(tmp);
			return (0);
		}
		ft_free_mem(tmp);
	}
	return (1);
}
