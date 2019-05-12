/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myarovoy <myarovoy@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/18 17:34:46 by myarovoy          #+#    #+#             */
/*   Updated: 2018/10/18 17:34:47 by myarovoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	ft_error(void)
{
	write(1, "ERROR\n", 6);
}

void	ft_print_filled_rooms(t_lemin *lemin)
{
	int		i;

	i = lemin->s_room_cnt;
	while (--i >= 1)
	{
		if (lemin->s_route[i].lem > 0)
		{
			ft_putchar('L');
			ft_putnbr(lemin->s_route[i].lem);
			ft_putchar('-');
			ft_putstr(lemin->s_route[i].room);
			ft_putstr("");
			if (ft_is_next_lem(lemin->s_route, i))
				ft_putchar(' ');
		}
	}
	ft_putchar('\n');
}

int		ft_fill_struct(t_lemin *lemin, t_room_coord *r_coord)
{
	if (!ft_get_task(lemin) || !ft_is_valid(lemin->input_data, r_coord))
		return (0);
	if (!ft_get_task_links(lemin))
		return (0);
	if (!ft_cnt_rooms(lemin) || !ft_get_tips(lemin))
		return (0);
	if (!ft_fill_rooms(lemin) || !ft_get_links(lemin))
		return (0);
	if (!ft_take_route(lemin))
		return (0);
	return (1);
}

int		main(void)
{
	t_lemin			lemin;
	t_room_coord	*r_coord;

	r_coord = NULL;
	if (!(ft_fill_struct(&lemin, r_coord)))
		ft_error();
	else
		ft_move_lem(&lemin);
	return (0);
}
