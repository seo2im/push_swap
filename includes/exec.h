/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seolim <seolim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 12:27:10 by seolim            #+#    #+#             */
/*   Updated: 2021/03/20 12:50:26 by seolim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXEC_H
# define EXEC_H
# include "stack.h"
# include "lib.h"

void	s(t_stack *stack);
void	p(t_stack *give, t_stack *get);
void	r(t_stack *stack);
void	rr(t_stack *stack);

#endif
