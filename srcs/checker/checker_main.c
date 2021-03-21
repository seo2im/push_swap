/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seolim <seolim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 14:18:14 by seolim            #+#    #+#             */
/*   Updated: 2021/03/21 15:39:24 by seolim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int checker_main(int argc, char *argv[])
{
	t_stack	*a;
	t_stack	*b;
	char	**execs;

	if (argv_check(argc, argv))
		return (1);
	if (!(execs = malloc(sizeof(char) * 1024)))
		return (1);
	a = init_stack(argc, argv);
	print_stack(a);
	b = init_stack(0, NULL);
	if (!get_exec(execs))
	{
		ft_double_free(execs);
		return (ft_write_n("Error"));
	}
	run(a, b, execs);
	print_stack(a);
	if (checker(a, b))
		ft_write_n("OK");
	else
		ft_write_n("KO");
	free_stack(a);
	free_stack(b);
	ft_double_free(execs);
}
