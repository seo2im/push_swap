/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   three.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seolim <seolim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 11:11:56 by seolim            #+#    #+#             */
/*   Updated: 2021/03/22 11:51:23 by seolim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	case1(t_stack *a)
{
	s(a);
	ft_command("sa", a, NULL);
}

void	case2(t_stack *a)
{
	s(a);
	ft_command("sa", a, NULL);
	rr(a);
	ft_command("rra", a, NULL);
}

void	case3(t_stack *a)
{
	r(a);
	ft_command("ra", a, NULL);
}

void	case4(t_stack *a)
{
	s(a);
	ft_command("sa", a, NULL);
	r(a);
	ft_command("ra", a, NULL);
}

void	case5(t_stack *a)
{
	rr(a);
	ft_command("rra", a, NULL);
}

void	three(t_stack *a, t_stack *b)
{
	if (checker(a, b))
		return ;
	else if (a->node->next->next->value > a->node->value
		&& a->node->value > a->node->next->value)
		case1(a);
	else if (a->node->value > a->node->next->value
		&& a->node->next->value > a->node->next->next->value)
		case2(a);
	else if (a->node->value > a->node->next->next->value
		&& a->node->next->next->value > a->node->next->value)
		case3(a);
	else if (a->node->next->value > a->node->next->next->value
		&& a->node->next->next->value > a->node->value)
		case4(a);
	else if (a->node->next->value > a->node->value
		&& a->node->value > a->node->next->next->value)
		case5(a);
	printf("count : %d\n", g_count);
}
