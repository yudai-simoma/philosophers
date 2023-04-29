/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 11:12:24 by yshimoma          #+#    #+#             */
/*   Updated: 2023/04/29 20:12:24 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

/*
 * プログラムの終了
 */
void	ft_free_exit(t_philo_group	*philo_group_)
{
	exit(1);
}
/*
 * アクションからの経過時間
 */
// bool	ft_get_elapsed_time_activity()
// {

// }

/*
 * 食事して良いか判断する関数
 */
bool	ft_can_eat(t_philosophers *philosophers, t_philosopher *philosopher)
{
	if (philosopher->status == IDLE && philosopher->before_status == IDLE)
		return (true);
	if (philosopher->status == IDLE && philosopher->before_status == SLEEPING)
		return (true);
	if (philosopher->status == IDLE && philosopher->before_status == THINKING)
		return (true);
	return (false);
}

/*
 * 睡眠して良いか判断する関数
 */
bool	ft_can_sleep(t_philosophers *philosophers, t_philosopher *philosopher)
{
	if (philosopher->status == IDLE && philosopher->before_status == EATING)
		return (true);
	return (false);
}

/*
 * 考えて良いか判断する関数
 */
bool	ft_can_think(t_philosophers *philosophers, t_philosopher *philosopher)
{
	if (philosopher->status == IDLE && philosopher->before_status == IDLE)
		return (true);
	if (philosopher->status == IDLE && philosopher->before_status == EATING)
		return (true);
	if (philosopher->status == IDLE && philosopher->before_status == SLEEPING)
		return (true);
	if (philosopher->status == IDLE && philosopher->before_status == THINKING)
		return (true);
	return (false);
}

/*
 * 死亡したか判断する関数
 */
bool	ft_is_dead(t_philosophers *philosophers, t_philosopher *philosopher)
{
	if (philosophers->die_time < philosopher->elapsed.eat_time)
		return (true);
	return (false);
}

//寝る関数
void	ft_start_sleeping()
{

}

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
					philosopher_->number, philosophers_->start_time, 1)
				|| ft_has_fork(&philosophers_->forks[philosopher_->right_fork],
					philosopher_->number, philosophers_->start_time, 2))
				ft_free_exit(philo_group_);
		}
		else
		{
			if (ft_has_fork(&philosophers_->forks[philosopher_->right_fork],
					philosopher_->number, philosophers_->start_time, 2)
				|| ft_has_fork(&philosophers_->forks[philosopher_->left_fork],
					philosopher_->number, philosophers_->start_time, 1))
				ft_free_exit(philo_group_);
		}
		//食べる
		if (ft_start_eating(&philosophers_->forks[philosopher_->left_fork],
				&philosophers_->forks[philosopher_->right_fork], philosopher_->number, philosophers_->start_time))
			ft_free_exit(philo_group_);
		// //寝る
		// ft_start_sleeping(philosophers_, philosopher_);
		// //考える
		// ft_start_thinking();
		// //死亡判定
		// if (ft_is_dead(philosophers_, philosopher_))
		// {

		// }
	}
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
	i_ = 0;
	while (i_ < philosophers->num_people)
	{
		philo_group_[i_].philosopher = &philosophers->philosopher[i_];
		philo_group_[i_].philosophers = philosophers;
		pthread_create(&thread_[i_], NULL, ft_philo_thread, &philo_group_[i_]);
		i_++;
	}
	i_ = 0;
	while (i_ < philosophers->num_people)
	{
		pthread_join(thread_[i_], NULL);
		i_++;
	}
	free(thread_);
	free(philo_group_);
	return (false);
}
