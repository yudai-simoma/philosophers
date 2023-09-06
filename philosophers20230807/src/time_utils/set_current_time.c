/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_current_time.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 11:38:41 by yshimoma          #+#    #+#             */
/*   Updated: 2023/09/06 20:36:07 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <pthread.h>
#include <sys/time.h>

/*
 * 現在時間をミリ秒で取得する関数
 */
void	set_current_time(
	time_t *set_time,
	pthread_mutex_t *mutex,
	bool *is_error)
{
	struct timeval	current_time_;

	if (gettimeofday(&current_time_, NULL) != 0)
	{
		*is_error = true;
		return ;
	}
	ft_xpthread_mutex_lock(mutex, is_error);
	*set_time = (current_time_.tv_sec * 1000) + (current_time_.tv_usec / 1000);
	ft_xpthread_mutex_unlock(mutex, is_error);
}
