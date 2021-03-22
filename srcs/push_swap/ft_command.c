/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_command.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seolim <seolim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 11:32:48 by seolim            #+#    #+#             */
/*   Updated: 2021/03/22 11:45:07 by seolim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_command(char *code, t_stack *a, t_stack *b)
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
