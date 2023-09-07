/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_sleeping.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 21:16:00 by yshimoma          #+#    #+#             */
/*   Updated: 2023/09/07 22:35:44 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types.h"
#include "config.h"
#include "action.h"
#include "time_utils.h"

/*
 * 寝る
 */
void	start_sleeping(t_philo_thread *philo_thread)
{
	atomic_long	elapsed_time;
	atomic_long	sleep_start_time;

	if (!is_program_stopped_philo(philo_thread))
	{
		print_message_philo(philo_thread, MSG_SLEEP);
		set_current_time(&sleep_start_time,
			philo_thread->main_time_mutex, philo_thread->main_is_error);
		while (true)
		{
			set_current_time(&elapsed_time, philo_thread->main_time_mutex,
				philo_thread->main_is_error);
			if (get_time_diff(sleep_start_time, elapsed_time,
					philo_thread->main_time_mutex, philo_thread->main_is_error)
				>= *philo_thread->main_args_time_to_sleep
				|| is_program_stopped_philo(philo_thread))
			{
				if (!is_program_stopped_philo(philo_thread))
				{
					print_message_philo(philo_thread, MSG_THINK);
				}
				return ;
			}
		}
	}
}
