/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_lem.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myarovoy <myarovoy@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 12:38:22 by myarovoy          #+#    #+#             */
/*   Updated: 2018/10/29 12:38:23 by myarovoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	ft_lems_init(t_lemin *lemin, int *lems)
{
	int		i;

	i = -1;
	while (++i < lemin->lem_cnt)
		lems[i] = i + 1;
}

void	ft_move_lem(t_lemin *lemin)
{
	int		i;
	int		lems[lemin->lem_cnt];

	i = 0;
	ft_lems_init(lemin, lems);
	// while (lemin->input_data[i])
	// {
	// 	ft_putstr(lemin->input_data[i++]);
	// 	ft_putchar('\n');
	// }
	// ft_putchar('\n');
	i = lemin->s_room_cnt + 1;
	while (--i > 0)
	{
		if (ft_is_lems_in_heap(lems, lemin->lem_cnt))
			ft_get_lem(lems, lemin);
		// ft_print_filled_rooms(lemin);
		ft_move_forward(lemin);
		if (!ft_is_lems_in_heap(lems, lemin->lem_cnt) &&
			!ft_is_lems_in_rooms(lemin))
			i = 0;
		else
			i = lemin->s_room_cnt + 1;
	}
}

int		ft_is_lems_in_heap(int *lems, int lem_cnt)
{
	int i;

	i = -1;
	while (++i < lem_cnt)
	{
		if (lems[i] != 0)
			return (1);
	}
	return (0);
}

void	ft_get_lem(int *lems, t_lemin *lemin)
{
	int		i;
	int		lem;

	lem = 0;
	i = -1;
	while (++i < lemin->lem_cnt)
	{
		if (lems[i] != 0)
		{
			lem = lems[i];
			lems[i] = 0;
			break ;
		}
	}
	lemin->s_route[1].lem = lem;
}
