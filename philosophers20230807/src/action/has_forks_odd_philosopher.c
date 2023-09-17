/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   has_forks_odd_philosopher.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 15:24:29 by yshimoma          #+#    #+#             */
/*   Updated: 2023/09/03 17:33:14 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "types.h"
#include "action.h"

/**
 * 奇数の哲学者がフォークを持つ
 * 奇数は、左→右でフォークを持つ
*/
void	has_forks_odd_philosopher(t_philo_thread *philo_thread)
{
	has_fork(&philo_thread->main_forks[philo_thread->philo.right_fork],
		philo_thread);
	has_fork(&philo_thread->main_forks[philo_thread->philo.left_fork],
		philo_thread);
}
