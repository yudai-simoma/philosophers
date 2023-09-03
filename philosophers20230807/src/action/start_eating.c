/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_eating.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 18:33:50 by yshimoma          #+#    #+#             */
/*   Updated: 2023/09/03 22:09:13 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include "types.h"
#include "config.h"

/*
 * 食べる
 */
void	start_eating(
	pthread_mutex_t *left_fork,
	pthread_mutex_t *right_fork,
	t_main_thread *main_thread,
	t_philo_thread *philo_thread)
{
	time_t	elapsed_time;

	if (!is_program_stopped(main_thread, &philo_thread->philo_thread_mutex))
	{
		print_message(main_thread,
			philo_thread->philo_id, MSG_EAT, &main_thread->print_mutex);
		set_current_time(&philo_thread->philo.eat_start_time,
			&philo_thread->philo.eat_start_time_mutex,
			main_thread->is_error);
		philo_thread->philo.eat_count--;
		if (philo_thread->philo.eat_count == 0)
		{
			ft_xpthread_mutex_lock(
				&philo_thread->philo_thread_mutex, main_thread->is_error);
			main_thread->everyone_is_eaten--;
			ft_xpthread_mutex_unlock(
				&philo_thread->philo_thread_mutex, main_thread->is_error);
		}
		while (true)
		{
			set_current_time(&elapsed_time,
				philo_thread->philo_thread_mutex, main_thread->is_error);
			if (get_time_diff(philo_thread->philo.eat_start_time, elapsed_time,
					&philo_thread->philo_thread_mutex, main_thread->is_error)
				>= main_thread->args_info.time_to_eat)
			{
				ft_xpthread_mutex_unlock(left_fork, main_thread->is_error);
				ft_xpthread_mutex_unlock(right_fork, main_thread->is_error);
				return ;
			}
		}
	}
	ft_xpthread_mutex_unlock(left_fork, main_thread->is_error);
	ft_xpthread_mutex_unlock(right_fork, main_thread->is_error);
}
