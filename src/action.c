/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 17:43:37 by yshimoma          #+#    #+#             */
/*   Updated: 2023/05/01 22:48:06 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

/*
 * フォークを持つ
 */
bool	ft_has_fork(pthread_mutex_t *fork,
	t_philosophers *philosophers, t_philosopher *philosopher)
{
	int				rev_;
	struct timeval	elapsed_time_;

	if (pthread_mutex_lock(fork) != 0)
		return (true);
	if (ft_is_program_stopped(philosophers))
	{
		pthread_mutex_unlock(fork);
		return (true);
	}
	if (ft_get_elapsed_time(philosophers->start_time, &elapsed_time_)
		|| ft_pfint_message(philosophers, philosopher, "has taken a fork"))
		return (true);
	return (false);
}

/*
 * 食べる
 */
bool	ft_start_eating(pthread_mutex_t *left_fork, pthread_mutex_t *right_fork,
	t_philosophers *philosophers, t_philosopher *philosopher)
{
	struct timeval	elapsed_time_;
	struct timeval	eat_end_time_;

	if (ft_pfint_message(philosophers, philosopher, "is eating")
		|| gettimeofday(&philosopher->eat_start_time, NULL) < 0)
		return (true);
	philosopher->eat_count--;
	if (philosopher->eat_count == 0)
		philosophers->everyone_has_eaten--;
	while (true)
	{
		if (gettimeofday(&eat_end_time_, NULL) < 0)
			return (true);
		elapsed_time_ = ft_get_time_diff(philosopher->eat_start_time,
				eat_end_time_);
		if (elapsed_time_.tv_usec > philosophers->eat_time * 1000)
		{
			if (pthread_mutex_unlock(left_fork) != 0
				|| pthread_mutex_unlock(right_fork) != 0)
				return (true);
			return (false);
		}
	}
}

/*
 * 寝る
 */
bool	ft_start_sleeping(t_philosophers *philosophers,
	t_philosopher *philosopher)
{
	struct timeval	elapsed_time_;
	struct timeval	sleep_start_time_;
	struct timeval	sleep_end_time_;

	if (ft_is_program_stopped(philosophers)
		|| ft_pfint_message(philosophers, philosopher, "is sleeping")
		|| gettimeofday(&sleep_start_time_, NULL) < 0)
		return (true);
	while (true)
	{
		if (gettimeofday(&sleep_end_time_, NULL) < 0)
			return (true);
		elapsed_time_ = ft_get_time_diff(sleep_start_time_, sleep_end_time_);
		if (elapsed_time_.tv_usec > philosophers->sleep_time * 1000)
		{
			if (!ft_is_program_stopped(philosophers)
				&& ft_pfint_message(philosophers, philosopher, "is thinking"))
				philosophers->error_flg = true;
			return (false);
		}
	}
}

/*
 * 死亡判定
 */
bool	ft_is_dead(t_philosophers *philosophers,
	t_philosopher *philosopher)
{
	struct timeval	elapsed_time_;

	if (ft_is_program_stopped(philosophers)
		|| gettimeofday(&elapsed_time_, NULL) < 0)
		return (true);
	// printf("e_time = %ld.%d, e_s_time = %ld.%d\n", elapsed_time_.tv_sec, elapsed_time_.tv_usec, philosopher->eat_start_time.tv_sec, philosopher->eat_start_time.tv_usec);
	elapsed_time_ = ft_get_time_diff(philosopher->eat_start_time,
			elapsed_time_);
	// printf("elapsed_time = %d, die_time = %d\n", elapsed_time_.tv_usec, philosophers->die_time * 1000);
	if (elapsed_time_.tv_usec > philosophers->die_time * 1000)
	{
		if (ft_write_die_flg(philosophers)
			|| ft_pfint_message(philosophers, philosopher, "died"))
			philosophers->error_flg = true;
		return (true);
	}
	return (false);
}
