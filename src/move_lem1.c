/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_lem1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myarovoy <myarovoy@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 14:16:01 by myarovoy          #+#    #+#             */
/*   Updated: 2018/10/29 14:16:02 by myarovoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	ft_move_forward(t_lemin *lemin)
{
	int		i;

	i = lemin->s_room_cnt;
	while (i > 0)
	{
		if (lemin->s_route[i].lem != 0)
		{
			lemin->s_route[i + 1].lem = lemin->s_route[i].lem;
			lemin->s_route[i].lem = 0;
		}
		i--;
	}
}

int		ft_is_lems_in_rooms(t_lemin *lemin)
{
	int		i;

	i = -1;
	while (++i < lemin->s_room_cnt)
	{
		if (lemin->s_route[i].lem != 0)
			return (1);
	}
	return (0);
}

int		ft_is_next_lem(t_lem_move *s_route, int i)
{
	while (--i >= 1)
	{
		if (s_route[i].lem > 0)
			return (1);
	}
	return (0);
}
