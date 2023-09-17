/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_message.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 18:17:54 by yshimoma          #+#    #+#             */
/*   Updated: 2023/09/17 14:06:16 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <pthread.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdatomic.h>
#include "types.h"
#include "time_utils.h"
#include "thread.h"

/*
 * スタートからの経過時間を設定する
 */
static int	_set_elapsed_time(
	time_t *elapsed_time,
	time_t start_time,
	atomic_bool *is_error)
{
	atomic_long	current_time;

	set_current_time(&current_time, is_error);
	if (*is_error)
		return (EXIT_FAILURE);
	*elapsed_time = current_time - start_time;
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
			print.is_error) == EXIT_FAILURE)
	{
		*print.is_error = true;
		return ;
	}
	if (printf("%ld %d %s\n",
			elapsed_time, print.philo_id + 1, print.message) < 0)
		*print.is_error = true;
	return ;
}
