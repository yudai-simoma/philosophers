/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 17:43:37 by yshimoma          #+#    #+#             */
/*   Updated: 2023/04/29 18:57:30 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

/*
 * フォークを持つ
 */
//TODO: プロトタイプをヘッダーと合わせる、出力関数を修正する
bool	ft_has_fork(pthread_mutex_t *fork,
	int number, struct timeval start_time, int flg)
{
	int				rev_;
	struct timeval	elapsed_time_;

	if (ft_get_elapsed_time(start_time, &elapsed_time_))
		return (true);
	rev_ = pthread_mutex_lock(fork);
	// printf("rev_ = %d\n", rev_);
	if (rev_ != 0)
		return (true);
	rev_ = printf("%ld%d %d has taken a %dfork\n",
			elapsed_time_.tv_sec, elapsed_time_.tv_usec / 1000, number, flg);
	if (rev_ < 0)
		return (true);
	return (false);
}

/*
 * 食べる
 */
bool	ft_start_eating(pthread_mutex_t *left_fork, pthread_mutex_t *right_fork,
	int number, struct timeval start_time)
{
	int				rev_;
	struct timeval	elapsed_time_;

	if (ft_get_elapsed_time(start_time, &elapsed_time_))
		return (true);
	rev_ = printf("%ld%d %d is eating\n",
			elapsed_time_.tv_sec, elapsed_time_.tv_usec / 1000, number);
	if (rev_ < 0)
		return (true);
	rev_ = pthread_mutex_unlock(left_fork);
	if (rev_ != 0)
		return (true);
	rev_ = pthread_mutex_unlock(right_fork);
	if (rev_ != 0)
		return (true);
	return (false);
}

/*
 * 寝る
 */
bool	ft_put_sleep(t_philosopher *philo, time_t timestamp)
{
	int	rev_;

	rev_ = printf("%ld %d is sleeping\n", timestamp * 1000, philo->number);
	if (rev_ < 0)
		return (true);
	return (false);
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
 * 死亡
 */
bool	ft_put_died(t_philosopher *philo, time_t timestamp)
{
	int	rev_;

	rev_ = printf("%ld %d died\n", timestamp * 1000, philo->number);
	if (rev_ < 0)
		return (true);
	return (false);
}
