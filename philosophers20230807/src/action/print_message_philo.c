/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_message_philo.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 20:08:08 by yshimoma          #+#    #+#             */
/*   Updated: 2023/09/16 22:26:34 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "action.h"
#include "x_wrapper.h"

void	print_message_philo(t_philo_thread *philo_thread, char *message)
{
	t_print	print;

	print.process_start_time = *philo_thread->main_process_start_time;
	print.is_error = philo_thread->main_is_error;
	print.philo_id = philo_thread->philo_id;
	print.message = message;
	ft_xpthread_mutex_lock(
		philo_thread->main_print_mutex, philo_thread->main_is_error);
	if (!is_program_stopped_philo(philo_thread))
		print_message(print);
	ft_xpthread_mutex_unlock(
		philo_thread->main_print_mutex, philo_thread->main_is_error);
}
