/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seolim <seolim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 10:47:43 by seolim            #+#    #+#             */
/*   Updated: 2021/03/21 14:41:25 by seolim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

static int	pass_isspace(const char *str)
{
	int i;

	i = 0;
	while (*(str + i) == 9 || *(str + i) == 10 || *(str + i) == 11 ||
			*(str + i) == 12 || *(str + i) == 13 || *(str + i) == 32)
	{
		i++;
	}
	return (i);
}

static int	check_sign(const char *str, int i)
{
	if (*(str + i) == '+')
		return (1);
	if (*(str + i) == '-')
		return (-1);
	return (0);
}

static int	calculate_digit(const char *str, int i)
{
	int result;

	result = 0;
	while (*(str + i) && ('0' <= *(str + i) && *(str + i) <= '9'))
	{
		result = (result * 10) + *(str + i) - '0';
		i++;
	}
	return (result);
}

int			ft_atoi(const char *str)
{
	int i;
	int sign;

	i = pass_isspace(str);
	if ((sign = check_sign(str, i)) != 0)
		i++;
	else
		sign = 1;
	return (calculate_digit(str, i) * sign);
}
