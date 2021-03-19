/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seolim <seolim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 11:12:22 by seolim            #+#    #+#             */
/*   Updated: 2021/03/04 12:50:27 by seolim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		is_num(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if (i == 0 && str[i] == '-')
			continue;
		if ('0' > str[i] && str[i] > '9')
			return (0);
	}
	return (1);
}

int		init(char *argv[], int **a)
{
	int	*arr;
	int i;
	int	j;

	i = -1;
	while (argv[++i])
	{
		if (!is_num(argv[i]))
			return (0);
	}
	if (!(arr = malloc(sizeof(int) * i)))
		return (0);
	j = i;
	i = -1;
	while (argv[++i])
		arr[--j] = ft_atoi(argv[i]);
	*a = arr;
	return (i);
}
