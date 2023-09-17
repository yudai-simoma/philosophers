/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_thread.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 13:58:03 by yshimoma          #+#    #+#             */
/*   Updated: 2023/09/17 17:33:55 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "types.h"
#include "config.h"
#include "action.h"
#include "thread.h"
#include "time_utils.h"
#include "x_wrapper.h"

static void	_set_philo_thread_date(
	t_philo_thread *philo_thread,
	t_main_thread *main_thread)
{
	philo_thread->main_forks = main_thread->forks;
	philo_thread->main_print_mutex = &main_thread->print_mutex;
	philo_thread->main_process_start_time = &main_thread->process_start_time;
	philo_thread->main_is_stopped = &main_thread->is_stopped;
	philo_thread->main_is_error = &main_thread->is_error;
	philo_thread->main_everyone_is_eaten = &main_thread->everyone_is_eaten;
	philo_thread->main_args_time_to_eat = &main_thread->args_info.time_to_eat;
	philo_thread->main_args_time_to_sleep
		= &main_thread->args_info.time_to_sleep;
	set_current_time(
		&(philo_thread->philo.eat_start_time), &main_thread->is_error);
}

/**
 * 哲学者分のthreadを作成し、処理を実行
*/
int	create_thread(
	t_main_thread *main_thread,
	t_philo_thread *philo_thread)
{
	pthread_t	*threads;
	int			i;

	threads = malloc(
			sizeof(pthread_t) * main_thread->args_info.number_of_philosophers);
	if (threads == NULL)
		return (EXIT_FAILURE);
	i = 0;
	while (i < main_thread->args_info.number_of_philosophers)
	{
		_set_philo_thread_date(&philo_thread[i], main_thread);
		if (main_thread->is_error
			|| pthread_create(
				&threads[i], NULL, create_philo_thread, &philo_thread[i]) != 0)
		{
			free(threads);
			return (EXIT_FAILURE);
		}
		i++;
	}
	wait_for_thread(threads, main_thread, philo_thread);
	free(threads);
	return (EXIT_SUCCESS);
}
