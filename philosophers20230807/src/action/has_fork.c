/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   has_fork.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 17:36:42 by yshimoma          #+#    #+#             */
/*   Updated: 2023/09/17 17:22:34 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include "types.h"
#include "config.h"
#include "thread.h"
#include "x_wrapper.h"

/*
 * フォークを持つ
 * プログラムの終了判定をして、まだ続くようであればフォークのミューテックスをロック
*/
void	has_fork(
	pthread_mutex_t *fork,
	t_philo_thread *philo_thread)
{
	if (!is_program_stopped_philo(philo_thread))
	{
		ft_xpthread_mutex_lock(fork, philo_thread->main_is_error);
		if (!is_program_stopped_philo(philo_thread))
		{
			print_message_philo(philo_thread, MSG_FORK_TAKEN);
		}
	}
}
