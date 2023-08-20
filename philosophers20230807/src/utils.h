/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 18:05:03 by yshimoma          #+#    #+#             */
/*   Updated: 2023/08/20 18:44:42 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H
# include <stdbool.h>
# include <pthread.h>

//utils.c
// bool	ft_is_error(int argc, char **argv);
// bool	ft_set_pram(int ac, char **av, t_philosophers *philosophers);
// bool	ft_set_philosophers(t_philosophers *philosophers);
// bool	ft_set_philosopher(t_philosophers *philosophers);

time_t	get_current_time(pthread_mutex_t *mutex, bool *is_error);
void	ft_putstr(char *str, bool *is_error);
void	ft_putendl(char *str, bool *is_error);
void	ft_putstr_error(char *str, bool *is_error);
size_t	ft_strlen(const char *s);

#endif