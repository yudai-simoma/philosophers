/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 14:41:25 by yshimoma          #+#    #+#             */
/*   Updated: 2023/09/17 14:03:45 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ACTION_H
# define ACTION_H

# include <pthread.h>
# include <stdatomic.h>
# include <stdatomic.h>
# include "types.h"

void	has_fork(
			pthread_mutex_t *fork,
			t_philo_thread *philo_thread);

void	has_forks_even_philosopher(t_philo_thread *philo_thread);

void	has_forks_odd_philosopher(t_philo_thread *philo_thread);

void	start_eating(
			pthread_mutex_t *left_fork,
			pthread_mutex_t *right_fork,
			t_philo_thread *philo_thread);

void	start_sleeping(
			t_philo_thread *philo_thread);

#endif
