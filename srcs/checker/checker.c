/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seolim <seolim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 12:12:26 by seolim            #+#    #+#             */
/*   Updated: 2021/03/21 14:39:09 by seolim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int		checker(t_stack *a, t_stack *b)
{
	int value;

	if (b->size != 0)
		return (FAIL);
	value = top(a);
	free(pop(a));
	while (a->size != 0)
	{
		if (value > top(a))
			return (FAIL);
		value = top(a);
		free(pop(a));
	}
	return (SUCCESS);
}