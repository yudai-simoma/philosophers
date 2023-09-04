/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   has_forks_even_philosopher.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 15:24:57 by yshimoma          #+#    #+#             */
/*   Updated: 2023/09/03 17:32:21 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types.h"
#include "action.h"

/**
 * 偶数の哲学者がフォークを持つ
*/
void	has_forks_even_philosopher(t_philo_thread *philo_thread)
{
	has_fork(&philo_thread->main_forks[philo_thread->philo.left_fork],
		philo_thread);
	has_fork(&philo_thread->main_forks[philo_thread->philo.right_fork],
		philo_thread);
}
