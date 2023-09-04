/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_eating.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 18:33:50 by yshimoma          #+#    #+#             */
/*   Updated: 2023/09/04 20:07:05 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include "types.h"
#include "config.h"
#include "action.h"
#include "x_wrapper.h"
#include "time_utils.h"

/*
 * 食べる
 */
void	start_eating(
	pthread_mutex_t *left_fork,
	pthread_mutex_t *right_fork,
	t_philo_thread *philo_thread)
{
	time_t	elapsed_time;

	if (!is_program_stopped_philo(philo_thread))
	{
		print_message_philo(philo_thread, MSG_EAT);
		set_current_time(&philo_thread->philo.eat_start_time,
			&philo_thread->philo.eat_start_time_mutex,
			philo_thread->main_is_error);
		philo_thread->philo.eat_count--;
		if (philo_thread->philo.eat_count == 0)
		{
			ft_xpthread_mutex_lock(&philo_thread->philo_thread_mutex,
				philo_thread->main_is_error);
			philo_thread->main_everyone_is_eaten--;
			ft_xpthread_mutex_unlock(&philo_thread->philo_thread_mutex,
				philo_thread->main_is_error);
		}
		while (true)
		{
			set_current_time(&elapsed_time, &philo_thread->philo_thread_mutex,
				philo_thread->main_is_error);
			if (get_time_diff(philo_thread->philo.eat_start_time, elapsed_time,
					&philo_thread->philo_thread_mutex,
					philo_thread->main_is_error)
				>= *philo_thread->main_args_time_to_eat)
			{
				ft_xpthread_mutex_unlock(
					left_fork, philo_thread->main_is_error);
				ft_xpthread_mutex_unlock(
					right_fork, philo_thread->main_is_error);
				return ;
			}
		}
	}
	ft_xpthread_mutex_unlock(left_fork, philo_thread->main_is_error);
	ft_xpthread_mutex_unlock(right_fork, philo_thread->main_is_error);
}
