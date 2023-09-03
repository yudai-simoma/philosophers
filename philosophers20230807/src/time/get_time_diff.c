/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_time_diff.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 19:12:05 by yshimoma          #+#    #+#             */
/*   Updated: 2023/09/03 19:40:16 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <time.h>
#include <pthread.h>
#include <stdbool.h>
#include "ft_xpthread_mutex_lock.h"
#include "ft_xpthread_mutex_unlock.h"

/*
 * 二つの時間を受け取り、その差分を返す関数
 */
int	get_time_diff(
	const time_t start_time,
	const time_t end_time,
	pthread_mutex_t *mutex,
	bool *is_error)
{
	int	diff_time;

	ft_xpthread_mutex_lock(mutex, is_error);
	diff_time = end_time - start_time;
	ft_xpthread_mutex_unlock(mutex, is_error);
	return (diff_time);
}
