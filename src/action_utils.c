/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 14:10:55 by yshimoma          #+#    #+#             */
/*   Updated: 2023/05/02 13:39:17 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

/*
 * 死亡フラグの書き込みを行う
 */
bool	ft_write_die_flg(t_philosophers *philosophers)
{
	// if (pthread_mutex_lock(&philosophers->die_mutex) != 0)
	// 	return (true);
	philosophers->die_flg = true;
	// if (pthread_mutex_unlock(&philosophers->die_mutex) != 0)
	// 	return (true);
	return (false);
}

/*
 * 死亡フラグの読み取りを行う
 */
bool	ft_is_program_stopped(t_philosophers *philosophers)
{
	bool			return_flg;

	return_flg = false;
	// if (pthread_mutex_lock(&philosophers->die_mutex) != 0)
	// 	philosophers->error_flg = true;
	return_flg = philosophers->die_flg;
	// if (pthread_mutex_unlock(&philosophers->die_mutex) != 0)
	// 	philosophers->error_flg = true;
	if (philosophers->everyone_has_eaten == 0)
		return_flg = true;
	return (return_flg);
}

/*
 * スタートからの経過時間を取得する
 */
bool	ft_get_elapsed_time(struct timeval start_time, time_t *elapsed_time)
{
	struct timeval	current_time_;
	time_t			start_time_;
	time_t			current_time__;

	if (gettimeofday(&current_time_, NULL) < 0)
		return (true);
	start_time_ = (start_time.tv_sec * 1000) + (start_time.tv_usec / 1000);
	current_time__ = (current_time_.tv_sec * 1000) + (current_time_.tv_usec / 1000);
	*elapsed_time = current_time__ - start_time_;
	return (false);
}

/*
 * 哲学者の行動をターミナルに出力する
 */
bool	ft_pfint_message(t_philosophers *philosophers,
	t_philosopher *philosopher, char *message)
{
	time_t	elapsed_time_;

	if (pthread_mutex_lock(&philosophers->print_mutex) != 0)
		philosophers->error_flg = true;
	if (ft_get_elapsed_time(philosophers->start_time, &elapsed_time_)
		|| printf("%ld %d %s\n", elapsed_time_, philosopher->number + 1,
			message) < 0)
		return (true);
	if (pthread_mutex_unlock(&philosophers->print_mutex) != 0)
		philosophers->error_flg = true;
	return (false);
}
