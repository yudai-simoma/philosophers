/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_message_main.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 20:08:01 by yshimoma          #+#    #+#             */
/*   Updated: 2023/09/04 20:26:23 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "action.h"

void	print_message_main(
	t_main_thread *main_thread,
	int philo_id,
	char *message)
{
	t_print	print;

	print.mutex = &main_thread->main_thread_mutex;
	print.process_start_time = main_thread->process_start_time;
	print.is_error = &main_thread->is_error;
	print.philo_id = philo_id;
	print.message = message;
	print_message(print);
}
