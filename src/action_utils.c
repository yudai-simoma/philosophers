/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 14:10:55 by yshimoma          #+#    #+#             */
/*   Updated: 2023/04/30 23:21:35 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

/*
 * 死亡フラグの書き込みを行う
 */
bool	ft_write_die_flg(t_philosophers *philosophers)
{
	if (pthread_mutex_lock(&philosophers->error_mutex) != 0)
		return (true);
	philosophers->die_flg = true;
	if (pthread_mutex_unlock(&philosophers->error_mutex) != 0)
		return (true);
	return (false);
}

/*
 * 死亡フラグの読み取りを行う
 */
bool	ft_read_die_flg(t_philosophers *philosophers)
{
	bool			return_flg;

	if (pthread_mutex_lock(&philosophers->error_mutex) != 0)
		philosophers->error_flg = true;
	return_flg = philosophers->die_flg;
	if (pthread_mutex_unlock(&philosophers->error_mutex) != 0)
		philosophers->error_flg = true;
	return (return_flg);
}
