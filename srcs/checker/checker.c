/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seolim <seolim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 12:12:26 by seolim            #+#    #+#             */
/*   Updated: 2021/03/22 11:50:07 by seolim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static t_stack	*copy(t_stack *a)
{
	t_stack	*copy;
	t_node	*temp;

	if (copy = init_stack(0, NULL))
		return (NULL);
	temp = a->node;
	while (temp)
	{
		push(copy, temp->value);
		temp = temp->next;
	}
	return (copy);
}

int		checker(t_stack *a, t_stack *b)
{
	int		value;
	t_stack	*check_stack;

	if (b->size != 0)
		return (FAIL);
	if (!(check_stack = copy(a)))
		return (FAIL);
	value = top(check_stack);
	free(pop(check_stack));
	while (a->size != 0)
	{
		if (value > top(check_stack))
			return (FAIL);
		value = top(check_stack);
		free(pop(check_stack));
	}
	free_stack(check_stack);
	return (SUCCESS);
}