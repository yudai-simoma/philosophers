/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_message.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 18:17:54 by yshimoma          #+#    #+#             */
/*   Updated: 2023/09/04 20:25:29 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <pthread.h>
#include <stdbool.h>
#include <stdlib.h>
#include "types.h"
#include "time_utils.h"
#include "action.h"

/*
 * スタートからの経過時間を設定する
 */
static int	_set_elapsed_time(
	time_t *elapsed_time,
	time_t start_time,
	pthread_mutex_t *mutex,
	bool *is_error)
{
	time_t	current_time;

	set_current_time(&current_time, mutex, is_error);
	if (*is_error)
		return (EXIT_FAILURE);
	if (pthread_mutex_lock(mutex) != 0)
		return (EXIT_FAILURE);
	*elapsed_time = current_time - start_time;
	if (pthread_mutex_unlock(mutex) != 0)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

/*
 * 哲学者の行動をターミナルに出力する
 */
void	print_message(t_print print)
{
	time_t	elapsed_time;

	if (_set_elapsed_time(&elapsed_time,
			print.process_start_time,
			print.mutex,
			print.is_error) != EXIT_FAILURE)
	{
		*print.is_error = true;
		return ;
	}
	if (printf("%ld %d %s\n",
			elapsed_time, print.philo_id + 1, print.message) < 0)
		*print.is_error = true;
	return ;
}
