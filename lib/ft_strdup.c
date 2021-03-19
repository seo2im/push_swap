/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seolim <seolim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 12:30:12 by seolim            #+#    #+#             */
/*   Updated: 2021/03/04 12:30:36 by seolim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char		*ft_strdup(const char *str)
{
	char	*dest;
	int		i;

	if ((dest = malloc(sizeof(char) * (ft_strlen(str) + 1))) == 0)
		return (0);
	i = 0;
	while (*(str + i))
	{
		*(dest + i) = *(str + i);
		i++;
	}
	*(dest + i) = 0;
	return (dest);
}