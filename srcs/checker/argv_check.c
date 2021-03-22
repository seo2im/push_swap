/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argv_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seolim <seolim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 15:19:47 by seolim            #+#    #+#             */
/*   Updated: 2021/03/22 11:07:17 by seolim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static int	is_in(int set[], int num, int len)
{
	int	i;

	i = -1;
	while (++i < len)
		if (num == set[i])
			return (FALSE);
	return (TRUE);
}

int argv_check(int argc, char *argv[])
{
	int	set[argc];
	int	i;
	int	j;
	
	if (argc == 0)
		return (ft_write_n("Error"));
	i = 0;
	while (++i < argc)
	{
		int	j = -1;
		while (argv[i][++j])
		{
			if (!ft_isdigit(argv[i][j]))
				return (ft_write_n("Error"));
		}
		if (!is_in(set, ft_atoi(argv[i]), i))
			return (ft_write_n("Error"));
		else
			set[i] = ft_atoi(argv[i]);
	}
	return (0);
}
