/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 11:12:24 by yshimoma          #+#    #+#             */
/*   Updated: 2023/05/02 13:18:50 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

/*
 * pthread_createしたときに呼ばれる関数
 * 食事、睡眠、死亡などのアクションが行われる
 */
void	*ft_philo_thread(void *v_philo_group)
{
	t_philo_group	*philo_group_;
	t_philosopher	*philosopher_;
	t_philosophers	*philosophers_;

	philo_group_ = v_philo_group;
	philosopher_ = philo_group_->philosopher;
	philosophers_ = philo_group_->philosophers;
	while (true)
	{
		if (philosopher_->number % 2 == 0)
		{
			if (ft_has_fork(&philosophers_->forks[philosopher_->left_fork],
					philosophers_, philosopher_)
				|| ft_has_fork(&philosophers_->forks[philosopher_->right_fork],
					philosophers_, philosopher_))
				break ;
		}
		else
		{
			if (ft_has_fork(&philosophers_->forks[philosopher_->right_fork],
					philosophers_, philosopher_)
				|| ft_has_fork(&philosophers_->forks[philosopher_->left_fork],
					philosophers_, philosopher_))
				break ;
		}
		if (ft_start_eating(&philosophers_->forks[philosopher_->left_fork],
				&philosophers_->forks[philosopher_->right_fork],
				philosophers_, philosopher_))
			break ;
		if (ft_start_sleeping(philosophers_, philosopher_))
			break ;
		if (ft_is_dead(philosophers_, philosopher_))
			break ;
	}
	return (NULL);
}

bool	ft_is_dead_all(t_philosophers *philosophers)
{
	int	i_;

	i_ = 0;
	while (i_ < philosophers->num_people)
	{
		if (ft_is_dead(philosophers, &philosophers->philosopher[i_]))
			return (true);
		i_++;
	}
	return (false);
}

/*
 * 哲学者分のthreadを作成し、処理を実行
 */
bool	ft_create_thread(t_philosophers *philosophers)
{
	size_t			i_;
	pthread_t		*thread_;
	t_philo_group	*philo_group_;

	thread_ = (pthread_t *)malloc(sizeof(pthread_t) * philosophers->num_people);
	if (thread_ == NULL)
		return (true);
	philo_group_ = (t_philo_group *)malloc(
			sizeof(t_philo_group) * philosophers->num_people);
	if (philo_group_ == NULL)
	{
		free(thread_);
		return (true);
	}
	if (gettimeofday(&philosophers->start_time, NULL) < 0)
		return (true);
	i_ = 0;
	while (i_ < philosophers->num_people)
	{
		if (gettimeofday(&philosophers->philosopher[i_].eat_start_time,
				NULL) < 0)
			return (true);
		philo_group_[i_].philosopher = &philosophers->philosopher[i_];
		philo_group_[i_].philosophers = philosophers;
		if (pthread_create(&thread_[i_], NULL, ft_philo_thread,
				&philo_group_[i_]) != 0)
			return (true);
		i_++;
	}
	while (true)
	{
		if (ft_is_dead_all(philosophers))
			break ;
			// return (false);
	}
	i_ = 0;
	while (i_ < philosophers->num_people)
	{
		// while (true)
		// 	pthread_detach(thread_[i_]);
		pthread_join(thread_[i_], NULL);
		if (philosophers->error_flg)
			return (true);
		i_++;
	}
	free(thread_);
	free(philo_group_);
	return (false);
}
