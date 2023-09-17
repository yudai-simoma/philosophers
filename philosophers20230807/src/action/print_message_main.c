/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_message_main.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 20:08:01 by yshimoma          #+#    #+#             */
/*   Updated: 2023/09/16 22:22:41 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "action.h"
#include "x_wrapper.h"

void	print_message_main(
	t_main_thread *main_thread,
	int philo_id,
	char *message)
{
	t_print	print;

	print.process_start_time = main_thread->process_start_time;
	print.is_error = &main_thread->is_error;
	print.philo_id = philo_id;
	print.message = message;
	ft_xpthread_mutex_lock(
		&main_thread->print_mutex, &main_thread->is_error);
	print_message(print);
	ft_xpthread_mutex_unlock(
		&main_thread->print_mutex, &main_thread->is_error);
}
