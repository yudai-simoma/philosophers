/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   has_fork.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 17:36:42 by yshimoma          #+#    #+#             */
/*   Updated: 2023/09/04 20:06:56 by yshimoma         ###   ########.fr       */
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
	t_philo_thread *philo_thread)
{
	if (!is_program_stopped_philo(philo_thread))
	{
		if (pthread_mutex_lock(fork) != 0)
		{
			*philo_thread->main_is_error = true;
		}
		if (!is_program_stopped_philo(philo_thread))
		{
			print_message_philo(philo_thread, MSG_FORK_TAKEN);
		}
	}
}
