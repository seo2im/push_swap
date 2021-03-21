/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seolim <seolim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 12:33:40 by seolim            #+#    #+#             */
/*   Updated: 2021/03/21 15:07:24 by seolim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	work_s(t_stack *a, t_stack *b, char *exec)
{
	if (!ft_strcmp(exec, "sa"))
		s(a);
	if (!ft_strcmp(exec, "sb"))
		s(b);
	if (!ft_strcmp(exec, "ss"))
	{
		s(a);
		s(b);
	}
}
static void	work_p(t_stack *a, t_stack *b, char *exec)
{
	if (!ft_strcmp(exec, "pa"))
		p(b, a);
	if (!ft_strcmp(exec, "pb"))
		p(a, b);
}
static void	work_r(t_stack *a, t_stack *b, char *exec)
{
	if (!ft_strcmp(exec, "ra"))
		r(a);
	if (!ft_strcmp(exec, "rb"))
		r(b);
	if (!ft_strcmp(exec, "rr"))
	{
		r(a);
		r(b);
	}
}
static void	work_rr(t_stack *a, t_stack *b, char *exec)
{
	if (!ft_strcmp(exec, "rra"))
		rr(a);
	if (!ft_strcmp(exec, "rrb"))
		rr(b);
	if (!ft_strcmp(exec, "rrr"))
	{
		rr(a);
		rr(b);
	}
}

int			run(t_stack *a, t_stack *b, char **execs)
{
	while (*execs)
	{
		work_s(a, b, *execs);
		work_p(a, b, *execs);
		work_r(a, b, *execs);
		work_rr(a, b, *execs);
		ft_write_n(*execs);
		++execs;
	}
}
