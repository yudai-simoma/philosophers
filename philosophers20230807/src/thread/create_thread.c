/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_thread.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 13:58:03 by yshimoma          #+#    #+#             */
/*   Updated: 2023/09/03 22:10:15 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include "types.h"
#include "set_current_time.h"

/*
 * 死亡判定
 */
static void	_check_philo_dead(
	t_main_thread *main_thread,
	t_philo_thread *philo_thread)
{
	time_t			elapsed_time;

	if (!is_program_stopped(main_thread, main_thread->main_thread_mutex))
	{
		set_current_time(&elapsed_time,
			main_thread->main_thread_mutex, main_thread->is_error);
		if (get_time_diff(
				philo_thread->philo.eat_start_time,
				elapsed_time,
				&philo_thread->philo_thread_mutex)
			> main_thread->args_info.time_to_die)
		{
			main_thread->is_dead = true;
			print_message(main_thread, philo_thread->philo_id,
				MSG_DIE, &main_thread->main_thread_mutex);
			return ;
		}
	}
}

static void	_check_all_philosophers_dead(
	t_main_thread *main_thread,
	t_philo_thread *philo_thread)
{
	int	i;

	i = 0;
	while (i < main_thread->args_info.number_of_philosophers)
	{
		_check_philo_dead(main_thread, philo_thread[i])
		i++;
	}
}

static void	_wait_for_thread(
	pthread_t *threads,
	t_main_thread *main_thread,
	t_philo_thread *philo_thread)
{
	int	i;

	while (true)
	{
		_check_all_philosophers_dead(main_thread, philo_thread);
		if (is_program_stopped(main_thread, main_thread->main_thread_mutex))
			break ;
	}
	i_ = 0;
	while (i_ < main_thread->args_info.number_of_philosophers)
	{
		if (pthread_join(threads[i_], NULL) != 0)
			main_thread->is_error = true;
		i_++;
	}
}

/**
 * 哲学者分のthreadを作成し、処理を実行
 */
bool	create_thread(
	t_main_thread *main_thread,
	t_philo_thread *philo_thread,
	bool *is_error)
{
	pthread_t	*threads;
	size_t		i;

	threads = malloc(
			sizeof(pthread_t) * main_thread->args_info.number_of_philosophers);
	if (threads == NULL)
		return (main_thread->is_error = true, true);
	i = 0;
	while (i < main_thread->args_info.number_of_philosophers)
	{
		main_thread->philo_thread = &philo_thread[i];
		set_current_time(&(main_thread->philo_thread[i].philo.eat_start_time),
			main_thread->philo_thread->philo.eat_start_time_mutex, is_error);
		if (*is_error
			|| pthread_create(&threads[i], NULL, philo_thread,
				main_thread->philo_thread[i]) != 0)
			return (free(threads), *is_error = true, true);
		i++;
	}
	_wait_for_thread(threads, main_thread, philo_thread);
	free(threads);
}
