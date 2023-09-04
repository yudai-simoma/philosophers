/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_thread.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 13:58:03 by yshimoma          #+#    #+#             */
/*   Updated: 2023/09/04 16:48:36 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdbool.h>
#include "types.h"
#include "time_utils.h"
#include "config.h"
#include "action.h"
#include "thread.h"

/*
 * 死亡判定
 */
#include <stdio.h>
static void	_check_philo_dead(
	t_main_thread *main_thread,
	t_philo_thread *philo_thread)
{
	time_t			elapsed_time;

	if (!is_program_stopped(main_thread, &main_thread->main_thread_mutex))
	{
		set_current_time(&elapsed_time,
			&main_thread->main_thread_mutex, &main_thread->is_error);
		if (get_time_diff(
				philo_thread->philo.eat_start_time,
				elapsed_time,
				&philo_thread->philo_thread_mutex,
				&main_thread->is_error)
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
		_check_philo_dead(main_thread, &(philo_thread[i]));
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
		if (is_program_stopped(main_thread, &main_thread->main_thread_mutex))
			break ;
	}
	i = 0;
	while (i < main_thread->args_info.number_of_philosophers)
	{
		if (pthread_join(threads[i], NULL) != 0)
			main_thread->is_error = true;
		i++;
	}
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
	printf("main_thread->args_info.number_of_philosophers = %d\n", main_thread->args_info.number_of_philosophers);
	while (i < main_thread->args_info.number_of_philosophers)
	{
		set_current_time(&(philo_thread[i].philo.eat_start_time),
			&(philo_thread[i].philo.eat_start_time_mutex),
			&main_thread->is_error);
		printf("bbbb\n");
		main_thread->philo_thread = &(philo_thread[i]);
		if (main_thread->is_error
			|| pthread_create(
				&threads[i], NULL, create_philo_thread, main_thread) != 0)
			return (free(threads), EXIT_FAILURE);
		i++;
	}
	printf("cccc\n");
	_wait_for_thread(threads, main_thread, philo_thread);
	printf("dddd\n");
	free(threads);
	return (EXIT_SUCCESS);
}
