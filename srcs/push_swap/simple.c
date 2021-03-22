/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seolim <seolim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 16:12:58 by seolim            #+#    #+#             */
/*   Updated: 2021/03/22 11:00:45 by seolim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_command(char *code, t_stack *a, t_stack *b)
{
	g_count++;
	ft_write_n(code);
	/*
	ft_write("a : ");
	print_stack(a);
	ft_write("b : ");
	print_stack(b);
	*/
}

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
				ft_command("ra", a, b);
			}
			else
			{
				push_node(a, temp);
				s(a);
				ft_command("sa", a, b);
				r(a);
				ft_command("ra", a, b);
			}
			temp = NULL;
		}
		p(a, b);
		ft_command("pb", a, b);
	}
	while (b->size != 0)
	{
		p(b, a);
		ft_command("pa", a, b);
	}
	printf("count : %d\n", g_count);
}
