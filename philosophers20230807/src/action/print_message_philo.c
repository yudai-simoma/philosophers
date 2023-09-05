/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_message_philo.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 20:08:08 by yshimoma          #+#    #+#             */
/*   Updated: 2023/09/05 20:19:20 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "action.h"

void	print_message_philo(t_philo_thread *philo_thread, char *message)
{
	t_print	print;

	print.mutex = philo_thread->print_mutex;
	print.process_start_time = *philo_thread->main_process_start_time;
	print.is_error = philo_thread->main_is_error;
	print.philo_id = philo_thread->philo_id;
	print.message = message;
	print_message(print);
}
