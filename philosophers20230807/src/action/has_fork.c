/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   has_fork.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 17:36:42 by yshimoma          #+#    #+#             */
/*   Updated: 2023/09/04 15:04:37 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include "types.h"
#include "config.h"
#include "action.h"

/*
 * フォークを持つ
 */
void	has_fork(
	pthread_mutex_t *fork,
	t_main_thread *main_thread,
	t_philo_thread *philo_thread)
{
	if (!is_program_stopped(main_thread, &philo_thread->philo_thread_mutex))
	{
		if (pthread_mutex_lock(fork) != 0)
		{
			main_thread->is_error = true;
		}
		if (!is_program_stopped(
				main_thread, &philo_thread->philo_thread_mutex))
		{
			print_message(main_thread, philo_thread->philo_id,
				MSG_FORK_TAKEN, &main_thread->print_mutex);
		}
	}
}
