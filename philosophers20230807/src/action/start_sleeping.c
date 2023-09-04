/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_sleeping.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 21:16:00 by yshimoma          #+#    #+#             */
/*   Updated: 2023/09/04 15:10:35 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types.h"
#include "config.h"
#include "action.h"
#include "time_utils.h"

/*
 * 寝る
 */
void	start_sleeping(t_main_thread *main_thread, t_philo_thread *philo_thread)
{
	time_t	elapsed_time;
	time_t	sleep_start_time;

	if (!is_program_stopped(main_thread, &philo_thread->philo_thread_mutex))
	{
		print_message(main_thread, philo_thread->philo_id,
			MSG_SLEEP, &philo_thread->philo_thread_mutex);
		set_current_time(&sleep_start_time,
			&philo_thread->philo_thread_mutex, &main_thread->is_error);
		while (true)
		{
			set_current_time(&elapsed_time,
				&philo_thread->philo_thread_mutex, &main_thread->is_error);
			if (get_time_diff(sleep_start_time, elapsed_time,
					&philo_thread->philo_thread_mutex, &main_thread->is_error)
				>= main_thread->args_info.time_to_sleep
				|| is_program_stopped(
					main_thread, &philo_thread->philo_thread_mutex))
			{
				if (!is_program_stopped(
						main_thread, &philo_thread->philo_thread_mutex))
				{
					print_message(main_thread, philo_thread->philo_id,
						MSG_THINK, &main_thread->print_mutex);
				}
				return ;
			}
		}
	}
}
