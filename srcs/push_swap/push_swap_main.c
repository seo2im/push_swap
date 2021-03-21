/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seolim <seolim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 16:25:00 by seolim            #+#    #+#             */
/*   Updated: 2021/03/21 16:29:31 by seolim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int push_swap_main(int argc, char *argv[])
{
	t_stack	*a;
	t_stack	*b;
    
    /*
	if (argv_check(argc, argv))
		return (1);
    */
	a = init_stack(argc, argv);
	print_stack(a);
	b = init_stack(0, NULL);
    simple(a, b);
	print_stack(a);
	free_stack(a);
	free_stack(b);
}
