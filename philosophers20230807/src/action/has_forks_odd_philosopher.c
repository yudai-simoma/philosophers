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
#include <types.h>

/**
 * 奇数の哲学者がフォークを持つ
*/
void	has_forks_odd_philosopher(
	t_main_thread *main_thread,
	t_philo_thread *philo_thread)
{
	usleep(10);
	has_fork(main_thread->forks[philo_thread->philo.right_fork],
		main_thread, philo_thread);
	has_fork(main_thread->forks[philo_thread->philo.left_fork],
		main_thread, philo_thread);
}
