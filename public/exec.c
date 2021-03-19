/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seolim <seolim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 11:27:04 by seolim            #+#    #+#             */
/*   Updated: 2021/03/19 10:59:20 by seolim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
/*
*	swap top 2 elements
*/
void	s(int *arr, int len)
{
	int	temp;

	if (len < 2)
		return ;
	temp = arr[len - 1];
	arr[len - 1] = arr[len - 2];
	arr[len - 2] = temp;
}
/*
*	a => b or b => a of top element
*/
void	p(int *give, int *get, int *give_len_addr, int *get_len_addr)
{
	int	give_len;
	int get_len;

	give_len = *give_len_addr;
	get_len = *get_len_addr;
	if (give_len == 0)
		return ;
	get[get_len] = give[give_len - 1];
	*get_len_addr = get_len + 1;
	*give_len_addr = give_len - 1;
}
/*
*	rotate top to botton
*/
void	r(int *arr,  int len)
{
	int temp;
	int	i;

	if (len < 1)
		return ;
	i = len;
	temp = arr[len - 1];
	while (--i > 0)
		arr[i] = arr[i - 1];
	arr[i] = temp;
}
/*
*	rotate bottom to top
*/
void	rr(int *arr, int len)
{
	int temp;
	int	i;

	if (len < 1)
		return ;
	i = -1;
	temp = arr[0];
	while (++i < len - 1)
		arr[i] = arr[i + 1];
	arr[i] = temp;
}


