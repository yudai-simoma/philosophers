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
void	has_forks_even_philosopher(
	t_main_thread *main_thread,
	t_philo_thread *philo_thread)
{
	has_fork(&main_thread->forks[philo_thread->philo.left_fork],
		main_thread, philo_thread);
	has_fork(&main_thread->forks[philo_thread->philo.right_fork],
		main_thread, philo_thread);
}
