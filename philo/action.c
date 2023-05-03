/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 17:35:59 by yshimoma          #+#    #+#             */
/*   Updated: 2023/05/03 15:03:52 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
 * フォークを持つ
 */
void	ft_has_fork(pthread_mutex_t *fork,
	t_philosophers *philosophers, t_philosopher *philosopher)
{
	if (!ft_is_program_stopped(philosophers, &philosophers->stopped_mutex))
	{
		if (pthread_mutex_lock(fork) != 0)
			philosophers->error_flg = true;
		if (!ft_is_program_stopped(philosophers, &philosophers->stopped_mutex))
			ft_pfint_message(philosophers, philosopher, "has taken a fork", &philosophers->print_mutex);
	}
}

/*
 * 死亡判定
 */
bool	ft_is_dead(t_philosophers *philosophers,
	t_philosopher *philosopher)
{
	time_t			elapsed_time_;

	if (!ft_is_program_stopped(philosophers, &philosophers->stopped_mutex))
	{
		if (!ft_get_current_time(&elapsed_time_, &philosophers->main_thread_mutex))
			philosophers->error_flg = true;
		if (ft_get_time_diff(philosopher->eat_start_time, elapsed_time_, &philosopher->eat_start_time_mutex)
			> philosophers->die_time)
		{
			philosophers->die_flg = true;
			ft_pfint_message(philosophers, philosopher, "died", &philosophers->print_mutex);
			return (true);
		}
	}
	return (false);
}

/*
 * 食べる
 */
void	ft_start_eating(pthread_mutex_t *left_fork, pthread_mutex_t *right_fork,
	t_philosophers *philosophers, t_philosopher *philosopher)
{
	time_t	elapsed_time_;

	if (!ft_is_program_stopped(philosophers, &philosophers->stopped_mutex))
	{
		ft_pfint_message(philosophers, philosopher, "is eating", &philosophers->print_mutex);
		if (!ft_get_current_time(&philosopher->eat_start_time, &philosopher->eat_start_time_mutex))
			philosophers->error_flg = true;
		philosopher->eat_count--;
		if (philosopher->eat_count == 0)
		{
			pthread_mutex_lock(&philosophers->stopped_mutex);
			philosophers->everyone_has_eaten--;
			pthread_mutex_unlock(&philosophers->stopped_mutex);
		}
		while (true)
		{
			if (!ft_get_current_time(&elapsed_time_, &philosophers->main_thread_mutex))
				philosophers->error_flg = true;
			if (ft_get_time_diff(philosopher->eat_start_time, elapsed_time_, &philosopher->eat_start_time_mutex)
				>= philosophers->eat_time)
			{
				pthread_mutex_unlock(left_fork);
				pthread_mutex_unlock(right_fork);
				return ;
			}
		}
	}
	else
	{
		pthread_mutex_unlock(left_fork);
		pthread_mutex_unlock(right_fork);
	}
}

/*
 * 寝る
 */
void	ft_start_sleeping(t_philosophers *philosophers,
	t_philosopher *philosopher)
{
	time_t	elapsed_time_;
	time_t	sleep_start_time_;

	if (!ft_is_program_stopped(philosophers, &philosophers->stopped_mutex))
	{
		ft_pfint_message(philosophers, philosopher, "is sleeping", &philosophers->print_mutex);
		// printf("eat_count = %d\n", philosophers->everyone_has_eaten);
		if (!ft_get_current_time(&sleep_start_time_, &philosophers->main_thread_mutex))
			philosophers->error_flg = true;
		// printf("sleep_start_time = %ld, process_time = %ld, sleep_time = %d\n", sleep_start_time_, philosophers->process_start_time, philosophers->sleep_time);
		while (true)
		{
			if (!ft_get_current_time(&elapsed_time_, &philosophers->main_thread_mutex))
				philosophers->error_flg = true;
			if (ft_get_time_diff(sleep_start_time_, elapsed_time_, &philosopher->eat_start_time_mutex)
				>= philosophers->sleep_time
				|| ft_is_program_stopped(philosophers, &philosophers->stopped_mutex))
			{
				// printf("sleep_time = %ld, sleep_time = %d\n", ft_get_time_diff(philosopher->eat_start_time, elapsed_time_), philosophers->sleep_time);
				if (!ft_is_program_stopped(philosophers, &philosophers->stopped_mutex))
				{
					ft_pfint_message(philosophers, philosopher, "is thinking", &philosophers->print_mutex);
				}
				return ;
			}
		}
	}
}
