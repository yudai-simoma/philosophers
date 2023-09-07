/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_current_time.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 11:38:41 by yshimoma          #+#    #+#             */
/*   Updated: 2023/09/07 22:32:37 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <pthread.h>
#include <sys/time.h>
#include <stdatomic.h>
#include "x_wrapper.h"

/*
 * 現在時間をミリ秒で取得する関数
 */
#include <stdio.h>
void	set_current_time(
	atomic_long *set_time,
	pthread_mutex_t *mutex,
	atomic_bool *is_error)
{
	struct timeval	current_time;

	// printf("current_time P=%p\n", &current_time);
	// printf("set_time P=%p\n", &set_time);
	// printf("mutex P=%p\n", &mutex);
	// printf("is_error P=%p\n", &is_error);
	if (gettimeofday(&current_time, NULL) != 0)
	{
		*is_error = true;
		return ;
	}
	ft_xpthread_mutex_lock(mutex, is_error);
	*set_time = (current_time.tv_sec * 1000) + (current_time.tv_usec / 1000);
	ft_xpthread_mutex_unlock(mutex, is_error);
}
