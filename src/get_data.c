/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myarovoy <myarovoy@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/20 15:25:22 by myarovoy          #+#    #+#             */
/*   Updated: 2018/10/20 15:25:23 by myarovoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int		ft_get_task_links(t_lemin *lemin)
{
	int		c_cnt;
	int		i;

	c_cnt = 0;
	i = -1;
	while (lemin->input_data[++i])
	{
		if (ft_strchr(lemin->input_data[i], '-') &&
					lemin->input_data[i][0] != '#')
			break ;
		c_cnt += ft_strlen(lemin->input_data[i]) + 1;
	}
	lemin->str_links = ft_strdup(lemin->data + c_cnt);
	return (1);
}

int		ft_get_task(t_lemin *lemin)
{
	char	*g_str;
	char	*tmp;
	char	*tmp2;

	g_str = NULL;
	get_next_line(0, &g_str);
	if (!ft_is_good_num_of_lem(g_str))
		return (0);
	lemin->lem_cnt = ft_atoi(g_str);
	tmp = ft_strjoin(g_str, "\n");
	free(g_str);
	while (get_next_line(0, &g_str) == 1)
	{
		if (!ft_is_good_gnl_line(g_str, tmp))
			return (0);
		tmp2 = ft_strjoin(tmp, g_str);
		free(tmp);
		tmp = ft_strjoin(tmp2, "\n");
		free(tmp2);
		free(g_str);
	}
	lemin->input_data = ft_strsplit(tmp, '\n');
	lemin->data = ft_strdup(tmp);
	free(tmp);
	return (1);
}

void	ft_clear_links(t_lemin *lemin, int l_cnt)
{
	int		i;
	int		k;
	char	*links_cpy[l_cnt];

	k = 0;
	i = -1;
	while (++i < l_cnt)
	{
		if (!ft_strcmp(lemin->links[i], ""))
			continue ;
		links_cpy[k] = ft_strdup(lemin->links[i]);
		free(lemin->links[i]);
		k++;
	}
	free(lemin->links);
	lemin->links = (char**)malloc(sizeof(char*) * k + 1);
	i = -1;
	while (++i < k)
	{
		lemin->links[i] = ft_strdup(links_cpy[i]);
		free(links_cpy[i]);
	}
	lemin->links[i] = NULL;
}

void	ft_fill_links_mirrored(char **links_mirr)
{
	char	**tmp;
	int		i;

	i = -1;
	while (links_mirr[++i])
	{
		if (links_mirr[i][0] == '#')
			continue ;
		tmp = ft_strsplit(links_mirr[i], '-');
		free(links_mirr[i]);
		links_mirr[i] = ft_strnew(ft_strlen(tmp[0]) +
							ft_strlen(tmp[1]) + 1);
		ft_strcat(links_mirr[i], tmp[1]);
		ft_strcat(links_mirr[i], "-");
		ft_strcat(links_mirr[i], tmp[0]);
		ft_free_mem(tmp);
	}
}

void	ft_exclude_same_links(t_lemin *lemin, int l_cnt)
{
	char	**links_mirr;
	int		i;
	int		k;

	links_mirr = ft_strsplit(lemin->str_links, '\n');
	ft_fill_links_mirrored(links_mirr);
	i = 0;
	while (i < l_cnt)
	{
		k = i;
		while (++k < l_cnt)
		{
			if (!ft_strcmp(lemin->links[i], lemin->links[k]) ||
				!ft_strcmp(lemin->links[i], links_mirr[k]))
			{
				free(lemin->links[i]);
				lemin->links[i] = "";
			}
		}
		i++;
	}
	ft_free_mem(links_mirr);
	ft_clear_links(lemin, l_cnt);
}
