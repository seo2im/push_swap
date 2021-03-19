/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seolim <seolim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 12:12:26 by seolim            #+#    #+#             */
/*   Updated: 2021/03/19 11:37:15 by seolim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int right(t_manager *manager)
{
	int value;
	int	i;
	
	if (manager->b_len != 0)
		return (0);
	i = -1;
	value = manager->a[++i];
	while (++i < manager->a_len)
	{
		if (value < manager->a[i])
			return (0);
		value = manager->a[i];
	}
	return (1);
}

int checker(int argc, char *argv[])
{
	t_manager	manager;
	
	if(!(manager.a_len = init(++argv, &manager.a)))
		return (ft_write_n("ERROR init"));
	if (!(manager.b = malloc(sizeof(int) * manager.a_len)))
		return (ft_write_n("ERROR b malloc"));
	manager.b_len = 0;
	print(manager.a, manager.b, manager.a_len, manager.b_len);
	run(&manager);
	print(manager.a, manager.b, manager.a_len, manager.b_len);
	if (right(&manager))
		ft_write_n("OK!");
	else
		ft_write_n("KO!");

	free(manager.a);
	free(manager.b);
	return (0);
}
