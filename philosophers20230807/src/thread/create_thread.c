/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_thread.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 13:58:03 by yshimoma          #+#    #+#             */
/*   Updated: 2023/09/06 20:47:55 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdbool.h>
#include "types.h"
#include "time_utils.h"
#include "config.h"
#include "action.h"
#include "thread.h"
#include "x_wrapper.h"

/*
 * 死亡判定
 */
#include <stdio.h>
static void	_check_philo_dead(
	t_main_thread *main_thread,
	t_philo_thread *philo_thread)
{
	time_t			elapsed_time;

	// printf("main_thread P=%p, philo_thread P=%p, main_thread->args_info.time_to_die P=%p, main_thread->forks P=%p\n", &main_thread->main_thread_mutex, philo_thread, &main_thread->args_info.time_to_die, main_thread->forks);
	// printf("elapsed_time P=%p, &philo_thread P=%p, &main_thread->is_dead P=%p\n", &elapsed_time, &philo_thread, &main_thread->is_dead);
	
	printf("%p\n", main_thread);
	printf("%p\n", main_thread->forks);
	printf("%p\n", &main_thread->stopped_mutex);
	printf("  %p\n", &main_thread->args_info);
	printf("  %p\n", &main_thread->args_info.number_of_philosophers);
	printf("  %p\n", &main_thread->args_info.time_to_die);
	printf("  %p\n", &main_thread->args_info.time_to_eat);
	printf("  %p\n", &main_thread->args_info.time_to_sleep);
	printf("  %p\n", &main_thread->args_info.number_of_times_each_philosopher_must_eat);
	printf("%p\n", &main_thread->process_start_time);
	printf("%p\n", &main_thread->is_dead);
	printf("%p\n", &main_thread->is_error);
	printf("%p\n", &main_thread->everyone_is_eaten);
	printf("\n%p\n", philo_thread);
	printf("%p\n", &philo_thread->philo_id);
	printf("  %p\n", &philo_thread->philo);
	printf("  %p\n", &philo_thread->philo.left_fork);
	printf("  %p\n", &philo_thread->philo.right_fork);
	printf("  %p\n", &philo_thread->philo.eat_start_time);
	printf("  %p\n", &philo_thread->philo.eat_count);
	printf("%p\n", philo_thread->main_forks);
	printf("%p\n", philo_thread->main_process_start_time);
	printf("%p\n", philo_thread->main_is_dead);
	printf("%p\n", philo_thread->main_is_error);
	printf("%p\n", philo_thread->main_everyone_is_eaten);
	printf("%p\n", philo_thread->main_args_time_to_eat);
	printf("%p\n", philo_thread->main_args_time_to_sleep);
	printf("%p\n", philo_thread->main_stopped_mutex);
	if (!is_program_stopped_main(main_thread))
	{
		set_current_time(&elapsed_time, &main_thread->is_error);
		if (get_time_diff(
				philo_thread->philo.eat_start_time,
				elapsed_time,
				&philo_thread->time_mutex,
				&main_thread->is_error)
			> main_thread->args_info.time_to_die)
		{
			ft_xpthread_mutex_lock(
				&main_thread->stopped_mutex, &main_thread->is_error);
			main_thread->is_dead = true;
			print_message_main(main_thread, philo_thread->philo_id, MSG_DIE);
			ft_xpthread_mutex_unlock(
				&main_thread->stopped_mutex, &main_thread->is_error);
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
		if (!main_thread->is_error)
			_check_philo_dead(main_thread, &(philo_thread[i]));
		else
			break ;
		i++;
	}
}

//TODO:関数を分ける
static void	_wait_for_thread(
	pthread_t *threads,
	t_main_thread *main_thread,
	t_philo_thread *philo_thread)
{
	int	i;

	while (true)
	{
		_check_all_philosophers_dead(main_thread, philo_thread);
		if (is_program_stopped_main(main_thread) || main_thread->is_error)
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

static void	_set_philo_thread_date(
	t_philo_thread *philo_thread,
	t_main_thread *main_thread)
{
	philo_thread->main_forks = main_thread->forks;
	philo_thread->main_process_start_time = &main_thread->process_start_time;
	philo_thread->main_is_dead = &main_thread->is_dead;
	philo_thread->main_is_error = &main_thread->is_error;
	philo_thread->main_everyone_is_eaten = &main_thread->everyone_is_eaten;
	philo_thread->main_args_time_to_eat = &main_thread->args_info.time_to_eat;
	philo_thread->main_args_time_to_sleep
		= &main_thread->args_info.time_to_sleep;
	philo_thread->main_stopped_mutex = &main_thread->stopped_mutex;
	philo_thread->time_mutex = &main_thread->time_mutex;
	set_current_time(&(philo_thread->philo.eat_start_time),
		&main_thread->time_mutex, &main_thread->is_error);
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
			return (free(threads), EXIT_FAILURE);
		i++;
	}
	_wait_for_thread(threads, main_thread, philo_thread);
	free(threads);
	return (EXIT_SUCCESS);
}
