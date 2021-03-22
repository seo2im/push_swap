/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seolim <seolim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 12:06:51 by seolim            #+#    #+#             */
/*   Updated: 2021/03/22 12:19:53 by seolim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_pivot(t_stack *stack)
{
	int		i;
	int		pivot;
	t_node	*node;

	i = -1;
	node = stack->node;
	pivot = node->value;
	while (++i < stack->size / 2)
	{
		node = node->next;
		pivot = node->value;
	}
	return (pivot);
}

void	a_to_b(t_stack *a, t_stack *b, int range)
{
	int	pivot;
	int	i;
	int ra_num;
	int	pb_num;

	if (range == 1)
		return ;
	pivot = get_pivot(a);
	ra_num = 0;
	pb_num = 0;
	i = -1;
	while (++i < range)
	{
		if (top(a) > pivot)
		{
			r(a);
			ra_num++;
		}
		else
		{
			p(a, b);
			pb_num++;
		}
	}
	i = -1;
	while (++i < ra_num)
	{
		rr(a);
	}
	a_to_b(a, b, ra_num);
	b_to_a(a, b, pb_num);
}

void	b_to_a(t_stack *a, t_stack *b, int range)
{
	int	pivot;
	int	i;
	int rb_num;
	int	pa_num;
	int	pb_num;

	if (range == 1)
	{
		p(b, a);
		return ;
	}
	pivot = get_pivot(b);
	rb_num = 0;
	pa_num = 0;
	i = -1;
	while (++i < range)
	{
		if (top(b) > pivot)
		{
			r(b);
			rb_num++;
		}
		else
		{
			p(b, a);
			pa_num++;
		}
	}
	i = -1;
	while (++i < rb_num)
	{
		rr(a);
	}
	a_to_b(a, b, ra_num);
	b_to_a(a, b, pb_num);
}
