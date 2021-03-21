/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seolim <seolim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 16:12:58 by seolim            #+#    #+#             */
/*   Updated: 2021/03/21 16:42:00 by seolim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void simple(t_stack *a, t_stack *b)
{
	int		i;
	int		min;
	int		num;
	t_node	*temp;
	
	while (a->size != 0)
	{
		num = a->size;
		min = top(a);
		i = -1;
		while (++i < num)
		{
			temp = pop(a);
			if (min > top(a))
			{
				push_node(a, temp);
				r(a);
			}
			else
				push_node(a, temp);
			temp = NULL;
		}
		p(a, b);
	}
	while (b->size != 0)
		p(b, a);
}
