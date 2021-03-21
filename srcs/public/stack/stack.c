/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seolim <seolim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 11:39:53 by seolim            #+#    #+#             */
/*   Updated: 2021/03/21 15:01:48 by seolim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

t_node				*init_node(int value)
{
	t_node	*node;
	
	if (!(node = malloc(sizeof(t_node))))
		return (NULL);
	node->value = value;
	node->before = NULL;
	node->next = NULL;
	return (node);
}

int					empty(t_stack *stack)
{
	return (stack->size == 0);
}

t_node				*pop(t_stack *stack)
{
	t_node	*node;
	int		value;

	if (stack->size == 0)
		return (NULL); //TODO : Error coding update...
	node = stack->node;
	stack->node = node->next;
	if (stack->node)
		stack->node->before = NULL;
	stack->size--;
	return (node);
}

int					top(t_stack *stack)
{
	return (stack->node->value);
}

int					push(t_stack *stack, int value)
{
	t_node	*new;

	if (!(new = init_node(value)))
		return (FAIL); //TODO : Error coding update...
	if (stack->size == 0)
		stack->node = new;
	else
	{
		new->next = stack->node;
		stack->node->before = new;
		stack->node = new;
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
	t_node	*node;
	int		i;

	node = stack->node;
	i = stack->size;
	printf("(top) ");
	while (--i >= 0)
	{
		printf("%d ", node->value);
		node = node->next;
	}
	printf(" (bottom) \n");
}

t_stack				*init_stack(int argc, char *argv[])
{
	t_stack	*stack;

	if (!(stack = malloc(sizeof(t_stack))))
		return (NULL);
	stack->node = NULL;
	stack->size = 0;
	if (argc == 0)
		return (stack);
	while (argc != 1)
	{
		push(stack, ft_atoi(argv[argc - 1]));
		argc--;
	}
	return (stack);
}

void				free_stack(t_stack *stack)
{
	t_node *temp;

	while (stack->size > 0)
		free(pop(stack));
	free(stack);
}