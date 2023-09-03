/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_program_stopped.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 15:41:03 by yshimoma          #+#    #+#             */
/*   Updated: 2023/09/03 17:58:52 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <types.h>

/*
 * 死亡フラグの読み取りを行う
 */
bool	is_program_stopped(t_main_thread *main_thread, pthread_mutex_t *mutex)
{
	bool	is_stopped;

	is_stopped = false;
	if (pthread_mutex_lock(mutex) != 0)
		main_thread->is_error = true;
	is_stopped = main_thread->is_dead;
	if (main_thread->everyone_is_eaten == 0)
		is_stopped = true;
	if (pthread_mutex_unlock(mutex) != 0)
		main_thread->is_error = true;
	return (is_stopped);
}
