/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_exec.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seolim <seolim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 12:16:00 by seolim            #+#    #+#             */
/*   Updated: 2021/03/04 13:16:56 by seolim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

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
			exec[++i] = 0;
			i = -1;
			if (!is_exec(exec))
				return (0);
			if (!(execs[++j] = ft_strdup(exec)))
				return (0);
			continue;
		}
		exec[++i] = buf;
	}
	execs[++j] = 0;
	return (1);
}