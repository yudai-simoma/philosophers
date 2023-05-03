/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 18:14:28 by yshimoma          #+#    #+#             */
/*   Updated: 2023/05/03 14:34:21 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
 * 死亡フラグの書き込みを行う
 */
// void	ft_write_die_flg(t_philosophers *philosophers)
// {
// 	philosophers->die_flg = true;
// }

/*
 * 死亡フラグの読み取りを行う
 */
bool	ft_is_program_stopped(t_philosophers *philosophers,
	pthread_mutex_t *mutex)
{
	bool			return_flg;

	return_flg = false;
	if (pthread_mutex_lock(mutex) != 0)
		philosophers->error_flg = true;
	return_flg = philosophers->die_flg;
	if (philosophers->everyone_has_eaten == 0)
		return_flg = true;
	if (pthread_mutex_unlock(mutex) != 0)
		philosophers->error_flg = true;
	return (return_flg);
}

/*
 * スタートからの経過時間を取得する
 */
static bool	_ft_get_elapsed_time(time_t start_time, time_t *elapsed_time, pthread_mutex_t *mutex)
{
	time_t	current_time_;

	if (!ft_get_current_time(&current_time_, mutex))
	{
		*elapsed_time = 0;
		return (true);
	}
	if (pthread_mutex_lock(mutex) != 0)
		return (true);
	*elapsed_time = current_time_ - start_time;
	if (pthread_mutex_unlock(mutex) != 0)
		return (true);
	return (false);
}

/*
 * 哲学者の行動をターミナルに出力する
 */
void	ft_pfint_message(t_philosophers *philosophers,
	t_philosopher *philosopher, char *message, pthread_mutex_t *mutex)
{
	time_t	elapsed_time_;

	if (_ft_get_elapsed_time(philosophers->process_start_time, &elapsed_time_, mutex))
	{
		philosophers->error_flg = true;
		return ;
	}
	if (printf("%ld %d %s\n", elapsed_time_, philosopher->number + 1,
			message) < 0)
		philosophers->error_flg = true;
	return ;
}
