/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_current_time.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 11:38:41 by yshimoma          #+#    #+#             */
/*   Updated: 2023/09/03 11:39:04 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <pthread.h>
#include <sys/time.h>

/*
 * 現在時間をミリ秒で取得する関数
 */
time_t	get_current_time(pthread_mutex_t *mutex, bool *is_error)
{
	struct timeval	current_time_;

	if (pthread_mutex_lock(mutex) != 0)
	{
		*is_error = true;
		return (0);
	}
	if (gettimeofday(&current_time_, NULL) != 0)
	{
		pthread_mutex_unlock(mutex);
		*is_error = true;
		return (0);
	}
	if (pthread_mutex_unlock(mutex) != 0)
	{
		*is_error = true;
		return (0);
	}
	return ((current_time_.tv_sec * 1000) + (current_time_.tv_usec / 1000));
}
