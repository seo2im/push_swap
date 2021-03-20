/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seolim <seolim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 11:27:04 by seolim            #+#    #+#             */
/*   Updated: 2021/03/20 13:04:23 by seolim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
/*
*	swap top 2 elements
*/
void	s(t_stack *stack)
{
	t_node	*one;
	t_node	*two;

	if (stack->size == 0 || stack->size == 1)
		return ;
	one = pop(stack);
	two = pop(stack);
	push(stack, one->value);
	push(stack, two->value);
	free(one);
	free(two);
}
/*
*	a => b or b => a of top element
*/
void	p(t_stack *give, t_stack *get)
{
	t_node	*node;

	if (give->size == 0)
		return ;
	node = pop(give);
	push(get, node->value);
	free(node);
}
/*
*	rotate top to botton
*/
void	r(t_stack *stack)
{
	t_node	*top;
	t_node	*list;

	if (stack->size == 0 || stack->size == 1)
		return ;
	top = pop(stack);
	top->next = NULL;
	list = stack->node;
	while (list->next)
		list = list->next;
	list->next = top;
	top->before = list;
	stack->size++;
}
/*
*	rotate bottom to top
*/
void	rr(t_stack *stack)
{
	t_node	*bottom;
	t_node	*list;

	if (stack->size == 0 || stack->size == 1)
		return ;
	bottom = stack->node;
	while (bottom->next)
		bottom = bottom->next;
	bottom->before->next = NULL;
	stack->size--;
	push(stack, bottom->value);
	free(bottom);
}


