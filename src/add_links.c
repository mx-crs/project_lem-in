/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_links.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myarovoy <myarovoy@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/20 21:28:54 by myarovoy          #+#    #+#             */
/*   Updated: 2018/10/20 21:28:56 by myarovoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int		ft_take_str_cnt(char **str)
{
	int		i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

int		ft_cnt_rooms(t_lemin *lemin)
{
	int		i;
	int		c;
	char	**str;
	int		cnt;

	i = -1;
	c = 0;
	while (lemin->input_data[++i])
	{
		str = ft_strsplit(lemin->input_data[i], ' ');
		if ((cnt = ft_take_str_cnt(str)) == 3 && str[0][0] != '#')
			c++;
		ft_free_mem(str);
	}
	lemin->room_cnt = c;
	return (1);
}

void	ft_fill_start_end(t_lemin *lemin, char ***str, int i)
{
	if (!ft_strcmp(*str[0], "##start"))
	{
		ft_free_mem(*str);
		*str = ft_strsplit(lemin->input_data[i + 1], ' ');
		lemin->start = ft_strdup(*str[0]);
	}
	else if (!ft_strcmp(*str[0], "##end"))
	{
		ft_free_mem(*str);
		*str = ft_strsplit(lemin->input_data[i + 1], ' ');
		lemin->end = ft_strdup(*str[0]);
	}
}

int		ft_get_tips(t_lemin *lemin)
{
	int		i;
	int		c;
	char	**str;

	c = lemin->room_cnt;
	i = -1;
	while (lemin->input_data[++i])
	{
		if (ft_strchr(lemin->input_data[i], '-') &&
					lemin->input_data[i][0] != '#')
			break ;
		str = ft_strsplit(lemin->input_data[i], ' ');
		ft_fill_start_end(lemin, &str, i);
		ft_free_mem(str);
	}
	return (1);
}

void	ft_fill_with_tips(t_lemin *lemin)
{
	int		r;

	r = -1;
	while (++r < lemin->room_cnt)
	{
		if (!ft_strcmp(lemin->rooms[r].room, lemin->start))
			lemin->start_ind = r;
		else if (!ft_strcmp(lemin->rooms[r].room, lemin->end))
			lemin->end_ind = r;
	}
}
