/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seolim <seolim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 10:40:49 by seolim            #+#    #+#             */
/*   Updated: 2021/03/04 12:18:08 by seolim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		print_two(int a_value, int b_value)
{
	char *temp;

	if (!(temp = ft_itoa(a_value)))
		return (0);
	ft_write(temp);
	ft_write("\t");
	free(temp);
	if (!(temp = ft_itoa(b_value)))
		return (0);
	ft_write_n(temp);
	free(temp);
	return (1);
}

int		print_one(int value, int flag)
{
	char *temp;

	if (flag == 'b')
		ft_write("\t");
	if (!(temp = ft_itoa(value)))
		return (0);
	ft_write_n(temp);
	free(temp);
	return (1);
}

int		print(int *a, int *b, int len_a, int len_b)
{
	int	len;
	int i;

	len = len_a > len_b ? len_a : len_b;
	i = len;
	while (--i >= 0)
	{
		if (len_a > i && len_b > i)
			if (!print_two(a[i], b[i]))
				return (0);
		if (len_a > i && len_b <= i)
			if (!print_one(a[i], 'a'))
				return (0);
		if (len_a <= i && len_b > i)
			if (!print_one(b[i], 'b'))
				return (0);
		if (len_a <= i && len_b <= i)
			break;
	}
	ft_write_n("_\t_");
	ft_write_n("a\tb");
	ft_write_n("------------");
	return (1);
}
