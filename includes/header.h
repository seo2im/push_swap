/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seolim <seolim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 10:40:52 by seolim            #+#    #+#             */
/*   Updated: 2021/03/19 11:36:25 by seolim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H
# include "manager.h"
# include "lib.h"
#include <stdio.h>

# define SA 0
# define SB	1
# define SS 2
# define PA 3
# define PB 4
# define RA 5
# define RB 6
# define RR 7
# define RRA 8
# define RRB 9
# define RRR 10

static char		*g_exec[11] = {
		"sa", "sb", "ss", "pa", "pb",
		"ra", "rb", "rr", "rra", "rrb", "rrr"
	};
static char		*g_exec_s[3] = {
		"sa", "sb", "ss"
	};
static char		*g_exec_p[2] = {
		"pa", "pb"
	};
static char		*g_exec_r[3] = {
		"ra", "rb", "rr"
	};
static char		*g_exec_rr[3] = {
		"rra", "rrb", "rrr"
	};


int				print(int *a, int *b, int len_a, int len_b);

void			s(int *arr, int len);
void			p(int *give, int *get, int *give_len_addr, int *get_len_addr);
void			r(int *arr,  int len);
void			rr(int *arr, int len);

int				init(char *argv[], int **a);
int				get_exec(char **execs);
int 			checker(int argc, char *argv[]);
int				run(t_manager *manager);

#endif

