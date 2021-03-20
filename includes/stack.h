/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seolim <seolim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 11:34:17 by seolim            #+#    #+#             */
/*   Updated: 2021/03/20 13:04:06 by seolim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "macro.h"
# include "lib.h"

typedef struct		s_node
{
	int				value;
	struct s_node	*next;
	struct s_node	*before;
}					t_node;


typedef struct		s_stack
{
	t_node			*node;
	int				size;
}					t_stack;

t_node				*init_node();
t_stack				*init_stack();
int					empty(t_stack *stack);
t_node				*pop(t_stack *stack);
int					top(t_stack *stack);
int					push(t_stack *stack, int value);
int					size(t_stack *stack);
void				free_stack(t_stack *stack);

void				print_stack(t_stack *stack);

#endif
