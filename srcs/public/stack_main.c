/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seolim <seolim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 11:05:45 by seolim            #+#    #+#             */
/*   Updated: 2021/03/21 15:00:09 by seolim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

int stack_main(int argc, char *argv[])
{
	t_stack *a;
	t_stack *b;

	a = init_stack(argc, argv);
	b = init_stack(0, NULL);
	
	printf("---a before---\n");
	print_stack(a);
	s(a);
	printf("---a after---\n");
	print_stack(a);
	printf("---b before---\n");
	print_stack(b);
	printf("---b after---\n");
	rr(b);
	print_stack(b);

	free_stack(a);
	free_stack(b);
}
