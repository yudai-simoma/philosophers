/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 17:43:37 by yshimoma          #+#    #+#             */
/*   Updated: 2023/04/30 23:48:45 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

/*
 * フォークを持つ
 */
bool	ft_has_fork(pthread_mutex_t *fork,
	t_philosophers *philosophers, t_philosopher *philosopher, int flg)
{
	int				rev_;
	struct timeval	elapsed_time_;

	if (pthread_mutex_lock(fork) != 0
		|| ft_read_die_flg(philosophers)
		|| ft_get_elapsed_time(philosophers->start_time, &elapsed_time_))
		return (true);
	rev_ = printf("%ld %d has taken a %dfork\n",
			elapsed_time_.tv_sec + elapsed_time_.tv_usec / 1000, philosopher->number + 1, flg);
	if (rev_ < 0)
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

	if (ft_read_die_flg(philosophers)
		|| ft_get_elapsed_time(philosophers->start_time, &elapsed_time_)
		|| printf("%ld %d is eating\n", elapsed_time_.tv_sec
			+ elapsed_time_.tv_usec / 1000, philosopher->number + 1) < 0
		|| gettimeofday(&philosopher->eat_start_time, NULL) < 0)
		return (true);
    // printf("  start time: %ld.%06d\n", eat_start_time_.tv_sec, eat_start_time_.tv_usec);
	while (true)
	{
		if (gettimeofday(&eat_end_time_, NULL) < 0)
			return (true);
		elapsed_time_ = ft_get_time_diff(philosopher->eat_start_time,
				eat_end_time_);
		if (elapsed_time_.tv_usec > philosophers->eat_time * 1000)
		{
			// printf("Current time: %ld.%06d\n", eat_end_time_.tv_sec, eat_end_time_.tv_usec);
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

	if (ft_read_die_flg(philosophers)
		|| ft_get_elapsed_time(philosophers->start_time, &elapsed_time_)
		|| printf("%ld %d is sleeping\n", elapsed_time_.tv_sec
			+ elapsed_time_.tv_usec / 1000, philosopher->number + 1) < 0
		|| gettimeofday(&sleep_start_time_, NULL) < 0)
		return (true);
    // printf("  start time: %ld.%06d\n", eat_start_time_.tv_sec, eat_start_time_.tv_usec);
	while (true)
	{
		if (gettimeofday(&sleep_end_time_, NULL) < 0)
			return (true);
		elapsed_time_ = ft_get_time_diff(sleep_start_time_, sleep_end_time_);
		if (elapsed_time_.tv_usec > philosophers->sleep_time * 1000)
		{
			// printf("Current time: %ld.%06d\n", eat_end_time_.tv_sec, eat_end_time_.tv_usec);
			return (false);
		}
	}
}

/*
 * 考える
 */
bool	ft_put_think(t_philosopher *philo, time_t timestamp)
{
	int	rev_;

	rev_ = printf("%ld %d is thinking\n", timestamp * 1000, philo->number);
	if (rev_ < 0)
		return (true);
	return (false);
}

/*
 * 死亡判定
 */
bool	ft_is_dead(t_philosophers *philosophers,
	t_philosopher *philosopher)
{
	struct timeval	now_time_;
	struct timeval	elapsed_time_;

	if (gettimeofday(&now_time_, NULL) < 0)
		return (true);
	elapsed_time_ = ft_get_time_diff(philosopher->eat_start_time, now_time_);
	if (ft_read_die_flg(philosophers) ||
		elapsed_time_.tv_usec > philosophers->die_time * 1000)
	{
		if (ft_write_die_flg(philosophers)
			|| printf("%ld %d died\n", elapsed_time_.tv_sec
				+ elapsed_time_.tv_usec / 1000, philosopher->number + 1) < 0)
			philosophers->die_flg = true;
		return (true);
	}
	return (false);
}
