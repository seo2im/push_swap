/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_exec.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seolim <seolim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 12:16:00 by seolim            #+#    #+#             */
/*   Updated: 2021/03/21 15:47:57 by seolim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static int	is_exec(char *str)
{
	int			i;

	i = -1;
	while (++i < 11)
	{
		if (!ft_strcmp(g_exec[i], str))
			return (1);
	}
	return (0);
}

static int	copy_module(char **execs, char *exec, int *i_addr, int *j_addr)
{
	int i;
	int	j;

	i = *i_addr;
	j = *j_addr;
	exec[++i] = 0;
	if (!is_exec(exec))
	{
		execs[++j] = 0;
		return (0);
	}
	if (!(execs[++j] = ft_strdup(exec)))
	{
		execs[++j] = 0;
		return (0);
	}
	*i_addr = i;
	*j_addr = j;
	return (1);
}

int			get_exec(char **execs)
{
	char	buf;
	char	exec[128];
	int		i;
	int		j;
	
	i = -1;
	j = -1;
	while ((read(0, &buf, 1) > 0))
	{
		if (buf == '\n')
		{
			if (!copy_module(execs, exec, &i, &j))
				return (0);
			/*
			exec[++i] = 0;
			if (!is_exec(exec))
			{
				execs[++j] = 0;
				return (0);
			}
			if (!(execs[++j] = ft_strdup(exec)))
			{
				execs[++j] = 0;
				return (0);
			}
			*/
			exec[0] = 0;
			i = -1;
			continue;
		}
		exec[++i] = buf;
	}
	execs[++j] = 0;
	if (exec[0] != 0)
		return (0);
	return (1);
}
