/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 16:46:56 by yshimoma          #+#    #+#             */
/*   Updated: 2023/05/03 14:40:11 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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
			ft_has_fork(&philosophers_->forks[philosopher_->left_fork],
				philosophers_, philosopher_);
			ft_has_fork(&philosophers_->forks[philosopher_->right_fork],
				philosophers_, philosopher_);
		}
		else
		{
			ft_has_fork(&philosophers_->forks[philosopher_->right_fork],
				philosophers_, philosopher_);
			ft_has_fork(&philosophers_->forks[philosopher_->left_fork],
				philosophers_, philosopher_);
		}
		ft_start_eating(&philosophers_->forks[philosopher_->left_fork],
			&philosophers_->forks[philosopher_->right_fork],
			philosophers_, philosopher_);
		ft_start_sleeping(philosophers_, philosopher_);
		if (ft_is_program_stopped(philosophers_, &philosophers_->stopped_mutex))
			break ;
	}
	return (NULL);
}

/*
 * 哲学者が一人でも死んだか判断する関数
 */
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
void	ft_create_thread(t_philosophers *philosophers)
{
	int				i_;
	pthread_t		*thread_;
	t_philo_group	*philo_group_;

	thread_ = (pthread_t *)malloc(sizeof(pthread_t) * philosophers->num_people);
	philo_group_ = (t_philo_group *)malloc(
			sizeof(t_philo_group) * philosophers->num_people);
	if (thread_ == NULL || philo_group_ == NULL)
	{
		free_mutex_and_memory(philosophers);
		free(thread_);
		free(philo_group_);
		return ;
	}
	i_ = 0;
	while (i_ < philosophers->num_people)
	{
		if (!ft_get_current_time(&philosophers->philosopher[i_].eat_start_time, &philosophers->philosopher[i_].eat_start_time_mutex))
			philosophers->error_flg = true;
		philo_group_[i_].philosopher = &philosophers->philosopher[i_];
		philo_group_[i_].philosophers = philosophers;
		if (pthread_create(&thread_[i_], NULL, ft_philo_thread,
				&philo_group_[i_]) != 0)
			philosophers->error_flg = true;
		i_++;
	}
	while (true)
	{
		ft_is_dead_all(philosophers);
		if (ft_is_program_stopped(philosophers, &philosophers->stopped_mutex))
			break ;
	}
	i_ = 0;
	while (i_ < philosophers->num_people)
	{
		if (pthread_join(thread_[i_], NULL) != 0)
			philosophers->error_flg = true;
		i_++;
	}
	free(thread_);
	free(philo_group_);
}
