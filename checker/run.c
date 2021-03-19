/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seolim <seolim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 12:33:40 by seolim            #+#    #+#             */
/*   Updated: 2021/03/19 11:11:24 by seolim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static void	work_s(t_manager *manager, char *exec)
{
	if (!ft_strcmp(exec, "sa"))
		s(manager->a, manager->a_len);
	if (!ft_strcmp(exec, "sb"))
		s(manager->b, manager->b_len);
	if (!ft_strcmp(exec, "ss"))
	{
		s(manager->a, manager->a_len);
		s(manager->b, manager->b_len);
	}
}
static void	work_p(t_manager *manager, char *exec)
{
	if (!ft_strcmp(exec, "pa"))
		p(manager->b, manager->a, &manager->b_len, &manager->a_len);
	if (!ft_strcmp(exec, "pb"))
		p(manager->a, manager->b, &manager->a_len, &manager->b_len);
}
static void	work_r(t_manager *manager, char *exec)
{
	if (!ft_strcmp(exec, "ra"))
		r(manager->a, manager->a_len);
	if (!ft_strcmp(exec, "rb"))
		r(manager->b, manager->b_len);
	if (!ft_strcmp(exec, "rr"))
	{
		r(manager->a, manager->a_len);
		r(manager->b, manager->b_len);
	}
}
static void	work_rr(t_manager *manager, char *exec)
{
	if (ft_strcmp(exec, "rra"))
		rr(manager->a, manager->a_len);
	if (ft_strcmp(exec, "rrb"))
		rr(manager->b, manager->b_len);
	if (ft_strcmp(exec, "rrr"))
	{
		rr(manager->a, manager->a_len);
		rr(manager->b, manager->b_len);
	}
}

int			run(t_manager *manager)
{
	char	**execs;
	int		i;
	
	if (!(execs = malloc(sizeof(char *) * 100)))
		return (0);
	if (!get_exec(execs))
		return (0);
	i = -1;
	while (execs[++i])
	{
		work_s(manager, execs[i]);
		work_p(manager, execs[i]);
		work_r(manager, execs[i]);
		work_rr(manager, execs[i]);
		ft_write_n(execs[i]);
		free(execs[i]);
	}
	free(execs);
	return (1);
}
