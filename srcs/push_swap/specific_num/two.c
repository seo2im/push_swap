/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   two.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seolim <seolim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 11:59:11 by seolim            #+#    #+#             */
/*   Updated: 2021/03/22 12:02:13 by seolim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	two(t_stack *a, t_stack *b)
{
	if (checker(a, b))
		return ;
	else if (a->node->value > a->node->next->value)
	{
		s(a);
		ft_command("sa", a, b);
	}
}
