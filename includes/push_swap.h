/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seolim <seolim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 16:13:24 by seolim            #+#    #+#             */
/*   Updated: 2021/03/22 12:02:28 by seolim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "exec.h"
# include "checker.h"

static int  g_count = 0;

void	    simple(t_stack *a, t_stack *b);
void	    ft_command(char *code, t_stack *a, t_stack *b);

void        two(t_stack *a, t_stack *b);
void    	three(t_stack *a, t_stack *b);

int		    push_swap_main(int argc, char *argv[]);

#endif
