/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seolim <seolim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 11:39:53 by seolim            #+#    #+#             */
/*   Updated: 2021/03/20 12:57:08 by seolim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

t_comp				*init_comp(int value)
{
	t_comp	*comp;
	
	if (!(comp = malloc(sizeof(t_comp))))
		return (NULL);
	comp->value = value;
	comp->before = NULL;
	comp->next = NULL;
	return (comp);
}

int					empty(t_stack *stack)
{
	return (stack->size == 0);
}

t_comp				*pop(t_stack *stack)
{
	t_comp	*comp;
	int		value;

	if (stack->size == 0)
		return (NULL); //TODO : Error coding update...
	comp = stack->comp;
	stack->comp = comp->next;
	if (stack->comp)
		stack->comp->before = NULL;
	stack->size--;
	return (comp);
}

int					top(t_stack *stack)
{
	return (stack->comp->value);
}

int					push(t_stack *stack, int value)
{
	t_comp	*new;

	if (!(new = init_comp(value)))
		return (FAIL); //TODO : Error coding update...
	if (stack->size == 0)
		stack->comp = new;
	else
	{
		new->next = stack->comp;
		stack->comp->before = new;
		stack->comp = new;
	}
	stack->size++;
	return (SUCCESS);
}

int					size(t_stack *stack)
{
	return (stack->size);
}

void				print_stack(t_stack *stack)
{
	t_comp	*comp;
	int		i;

	comp = stack->comp;
	i = stack->size;
	while (--i >= 0)
	{
		printf("%d\n", comp->value);
		comp = comp->next;
	}
}

t_stack				*init_stack(char *argv[])
{
	t_stack	*stack;

	if (!(stack = malloc(sizeof(t_stack))))
		return (NULL);
	stack->comp = NULL;
	stack->size = 0;
	if (!argv)
		return (stack);
	while (*argv)
	{
		push(stack, ft_atoi(*argv));
		argv++;
	}
	return (stack);
}

void				free_stack(t_stack *stack)
{
	t_comp *temp;

	while (stack->size > 0)
		free(pop(stack));
	free(stack);
}