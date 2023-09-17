/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait_for_thread.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 12:54:49 by yshimoma          #+#    #+#             */
/*   Updated: 2023/09/17 14:06:55 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types.h"
#include "config.h"
#include "time_utils.h"
#include "thread.h"

/*
 * 死亡判定
 */
static void	_check_philo_dead(
	t_main_thread *main_thread,
	t_philo_thread *philo_thread)
{
	atomic_long	elapsed_time;

	if (!is_program_stopped_main(main_thread))
	{
		set_current_time(&elapsed_time, &main_thread->is_error);
		if (get_time_diff(philo_thread->philo.eat_start_time, elapsed_time)
			> main_thread->args_info.time_to_die)
		{
			main_thread->is_dead = true;
			print_message_main(main_thread, philo_thread->philo_id, MSG_DIE);
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

/**
 * 哲学者分のthreadが終了するのを待つ
 */
void	wait_for_thread(
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
