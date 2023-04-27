/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 11:12:24 by yshimoma          #+#    #+#             */
/*   Updated: 2023/04/27 20:16:32 by yshimoma         ###   ########.fr       */
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
 * スタートからの経過時間を取得する
 */
bool	ft_get_elapsed_time(t_philosophers	*philosophers, t_elapsed *elapsed)
{
	struct timeval	tmp_time_;
	int				err_flg_;

	err_flg_ = gettimeofday(&tmp_time_, NULL);
	elapsed->start_time = tmp_time_.tv_sec - philosophers->start_time.tv_sec;
	if (err_flg_ < 0)
		return (true);
	return (false);
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
		if (ft_get_elapsed_time(philosophers_, &philosopher_->elapsed))
			ft_free_exit(philo_group_);
		//食べる
		if (ft_can_eat(philosophers_, philosopher_))
		{
			pthread_mutex_lock(&philosophers_->forks[philosopher_->left_fork]);
			pthread_mutex_lock(&philosophers_->forks[philosopher_->right_fork]);
			ft_start_eating();
			pthread_mutex_unlock(&philosophers_->forks[philosopher_->left_fork]);
			pthread_mutex_unlock(&philosophers_->forks[philosopher_->right_fork]);
		}
		//寝る
		ft_start_sleeping(philosophers_, philosopher_);
		//考える
		ft_start_thinking();
		//死亡判定
		if (ft_is_dead(philosophers_, philosopher_))
		{

		}
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
		return (false);
	philo_group_ = (t_philo_group *)malloc(
			sizeof(t_philo_group) * philosophers->num_people);
	if (philo_group_ == NULL)
	{
		free(thread_);
		return (false);
	}
	i_ = 0;
	while (i_ < philosophers->num_people)
	{
		philo_group_[i_].philosopher = &philosophers->philosopher[i_];
		philo_group_[i_].philosophers = philosophers;
		pthread_create(&thread_[i_], NULL, ft_philo_thread, &philo_group_[i_]);
		i_++;
	}
	free(thread_);
	free(philo_group_);
	return (true);
}
