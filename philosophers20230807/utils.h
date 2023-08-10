/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 18:05:03 by yshimoma          #+#    #+#             */
/*   Updated: 2023/08/10 18:12:51 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H
# include <stdbool.h>

//utils.c
bool	ft_is_error(int argc, char **argv);
bool	ft_set_pram(int ac, char **av, t_philosophers *philosophers);
bool	ft_set_philosophers(t_philosophers *philosophers);
bool	ft_set_philosopher(t_philosophers *philosophers);

//ft_atoi.c
int				ft_atoi(const char *str);
//ft_isdigit.c
int				ft_isdigit(int c);

#endif