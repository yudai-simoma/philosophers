/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_thread.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 15:08:22 by yshimoma          #+#    #+#             */
/*   Updated: 2023/09/03 21:34:02 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types.h"

void	philo_thread(void *tmp)
{
	t_main_thread	*main_thread;

	main_thread = tmp;
	while (true)
	{
		if (main_thread->philo_thread->philo_id % 2 == 0)
			has_forks_even_philosopher(main_thread, main_thread->philo_thread);
		else
			has_forks_odd_philosopher(main_thread, main_thread->philo_thread);
		if (main_thread->is_error)
			break ;
		start_eating(
			main_thread->forks[main_thread->philo_thread->philo.left_fork],
			main_thread->forks[main_thread->philo_thread->philo.right_fork],
			main_thread,
			main_thread->philo_thread);
		if (main_thread->is_error)
			break ;
		start_sleeping(main_thread, main_thread->philo_thread);
		if (main_thread->is_error || is_program_stopped())
			break ;
	}
}
