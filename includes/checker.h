/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seolim <seolim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 14:17:09 by seolim            #+#    #+#             */
/*   Updated: 2021/03/21 14:58:14 by seolim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H
# include "lib.h"
# include "stack.h"
# include "exec.h"

static char	*g_exec[11] = {
	"sa", "sb", "ss", "pa", "pb",
	"ra", "rb", "rr", "rra", "rrb", "rrr"
};
int			get_exec(char **execs);
int			run(t_stack *a, t_stack *b, char **execs);
int			checker(t_stack *a, t_stack *b);
int			checker_main(int argc, char *argv[]);

#endif
