/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_program_stopped.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 19:56:29 by yshimoma          #+#    #+#             */
/*   Updated: 2023/09/06 20:06:55 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <pthread.h>
#include "config.h"
#include "x_wrapper.h"

/*
 * 死亡フラグの読み取りを行う
 */
#include <stdio.h>
//TODO:is_deadで競合しているため修正が必要
bool	is_program_stopped(
	pthread_mutex_t *mutex,
	bool *is_dead,
	bool *is_error,
	int everyone_is_eaten)
{
	bool	is_stopped;

	// printf("is_program_stopped_mutex P=%p, is_error P=%p, is_dead P=%p\n", mutex, is_error, is_dead);
	is_stopped = false;
	ft_xpthread_mutex_lock(mutex, is_error);
	is_stopped = *is_dead;
	if (everyone_is_eaten == ALL_IS_EATEM_NO)
		is_stopped = true;
	ft_xpthread_mutex_unlock(mutex, is_error);
	return (is_stopped);
}
