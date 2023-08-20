/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 22:15:43 by yshimoma          #+#    #+#             */
/*   Updated: 2023/08/20 18:57:55 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdbool.h>
#include <pthread.h>
#include <sys/time.h>
#include "libft/libft.h"

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

void	ft_putstr(char *str, bool *is_error)
{
	if (write(STDOUT_FILENO, str, ft_strlen(str)) == -1)
		*is_error = true;
}

void	ft_putendl(char *str, bool *is_error)
{
	ft_putstr(str, is_error);
	if (write(STDOUT_FILENO, "\n", 1) == -1)
		*is_error = true;
}

void	ft_putstr_error(char *str, bool *is_error)
{

	if (write(STDERR_FILENO, str, ft_strlen(str)) == -1)
		*is_error = true;
	if (write(STDERR_FILENO, "\n", 1) == -1)
		*is_error = true;
}
