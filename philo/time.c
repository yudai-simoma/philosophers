/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 16:12:24 by yshimoma          #+#    #+#             */
/*   Updated: 2023/09/03 19:10:43 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
 * 現在時間をミリ秒で取得する関数
 */
bool	ft_get_current_time(time_t *time, pthread_mutex_t *mutex)
{
	struct timeval	current_time_;

	if (pthread_mutex_lock(mutex) != 0)
		return (true);
	if (gettimeofday(&current_time_, NULL) == 0)
	{
		*time = (current_time_.tv_sec * 1000) + (current_time_.tv_usec / 1000);
		pthread_mutex_unlock(mutex);
		return (true);
	}
	else
	{
		if (pthread_mutex_unlock(mutex) != 0)
			return (true);
	}
	return (false);
}

/*
 * 二つの時間を受け取り、その差分を返す関数
 */
time_t	ft_get_time_diff(time_t start_time, time_t end_time, pthread_mutex_t *mutex)
{
	time_t	ret_;

	pthread_mutex_lock(mutex);
	ret_ = end_time - start_time;
	pthread_mutex_unlock(mutex);
	return (ret_);
}
