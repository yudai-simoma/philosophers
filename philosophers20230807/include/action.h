/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 14:41:25 by yshimoma          #+#    #+#             */
/*   Updated: 2023/09/04 14:45:04 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ACTION_H
# define ACTION_H

# include <pthread.h>
# include "types.h"

void	has_fork(
			pthread_mutex_t *fork,
			t_main_thread *main_thread,
			t_philo_thread *philo_thread);

void	has_forks_even_philosopher(
			t_main_thread *main_thread,
			t_philo_thread *philo_thread);

void	has_forks_odd_philosopher(
			t_main_thread *main_thread,
			t_philo_thread *philo_thread);

bool	is_program_stopped(t_main_thread *main_thread, pthread_mutex_t *mutex);

void	print_message(
			t_main_thread *main_thread,
			int philo_id,
			char *message,
			pthread_mutex_t *mutex);

void	start_eating(
			pthread_mutex_t *left_fork,
			pthread_mutex_t *right_fork,
			t_main_thread *main_thread,
			t_philo_thread *philo_thread);

void	start_sleeping(
			t_main_thread *main_thread,
			t_philo_thread *philo_thread);

#endif
