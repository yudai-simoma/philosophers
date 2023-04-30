/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 14:10:55 by yshimoma          #+#    #+#             */
/*   Updated: 2023/04/30 14:58:24 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

/*
 * 死亡フラグの書き込みを行う
 */
bool	ft_write_die_flg(bool *die_flg)
{
	pthread_mutex_t	mutex_;

	if (pthread_mutex_init(&mutex_, NULL) != 0)
		return (true);
	if (pthread_mutex_lock(&mutex_) != 0)
		return (true);
	*die_flg = true;
	if (pthread_mutex_unlock(&mutex_) != 0)
	{
		pthread_mutex_destroy(&mutex_) != 0;
		return (true);
	}
	if (pthread_mutex_destroy(&mutex_) != 0)
		return (true);
	return (false);
}

/*
 * 死亡フラグの読み取りを行う
 */
bool	ft_read_die_flg(t_philosophers *philosophers)
{
	pthread_mutex_t	mutex_;
	bool			return_flg;

	if (pthread_mutex_init(&mutex_, NULL) != 0)
		philosophers->error_flg = true;
	if (pthread_mutex_lock(&mutex_) != 0)
		philosophers->error_flg = true;
	return_flg = philosophers->die_flg;
	if (pthread_mutex_unlock(&mutex_) != 0)
	{
		pthread_mutex_destroy(&mutex_) != 0;
		philosophers->error_flg = true;
	}
	if (pthread_mutex_destroy(&mutex_) != 0)
		philosophers->error_flg = true;
	return (return_flg);
}
