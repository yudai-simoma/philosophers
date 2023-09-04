/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_program_stopped.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 19:56:29 by yshimoma          #+#    #+#             */
/*   Updated: 2023/09/04 19:58:56 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <pthread.h>

/*
 * 死亡フラグの読み取りを行う
 */
bool	is_program_stopped(
	pthread_mutex_t *mutex,
	bool *is_dead,
	bool *is_error,
	int *everyone_is_eaten)
{
	bool	is_stopped;

	is_stopped = false;
	if (pthread_mutex_lock(mutex) != 0)
		*is_error = true;
	is_stopped = is_dead;
	if (everyone_is_eaten == 0)
		is_stopped = true;
	if (pthread_mutex_unlock(mutex) != 0)
		*is_error = true;
	return (is_stopped);
}
