/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argv_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seolim <seolim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 15:19:47 by seolim            #+#    #+#             */
/*   Updated: 2021/03/21 15:36:27 by seolim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int argv_check(int argc, char *argv[])
{
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
	}
	return (0);
}
