/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seolim <seolim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 11:34:17 by seolim            #+#    #+#             */
/*   Updated: 2021/03/20 12:56:11 by seolim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "macro.h"
# include "lib.h"

typedef struct		s_comp
{
	int				value;
	struct s_comp	*next;
	struct s_comp	*before;
}					t_comp;


typedef struct		s_stack
{
	t_comp			*comp;
	int				size;
}					t_stack;

t_comp				*init_comp();
t_stack				*init_stack();
int					empty(t_stack *stack);
t_comp				*pop(t_stack *stack);
int					top(t_stack *stack);
int					push(t_stack *stack, int value);
int					size(t_stack *stack);
void				free_stack(t_stack *stack);

void				print_stack(t_stack *stack);

#endif
