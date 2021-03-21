/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seolim <seolim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 11:35:25 by seolim            #+#    #+#             */
/*   Updated: 2021/03/21 15:27:30 by seolim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB_H
# define LIB_H
# include <unistd.h>
# include <stdlib.h>

int				ft_strlen(const char *str);
int				ft_write(char *str);
int				ft_write_n(char *str);
int				ft_atoi(const char *str);
char			*ft_itoa(int n);
int				ft_strcmp(char *s1, char *s2);
char			*ft_strdup(const char *str);
void			ft_double_free(char **execs);
int				ft_isdigit(int c);

#endif
