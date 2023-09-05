/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_philo_thread.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 15:08:22 by yshimoma          #+#    #+#             */
/*   Updated: 2023/09/05 20:21:28 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types.h"
#include "action.h"

void	*create_philo_thread(void *tmp)
{
	t_philo_thread	*philo_thread;

	philo_thread = tmp;
	while (true)
	{
		if (philo_thread->philo_id % 2 == 0)
			has_forks_even_philosopher(philo_thread);
		else
			has_forks_odd_philosopher(philo_thread);
		if (*philo_thread->main_is_error)
		{
			break ;
		}
		start_eating(
			&philo_thread->main_forks[philo_thread->philo.left_fork],
			&philo_thread->main_forks[philo_thread->philo.right_fork],
			philo_thread);
		if (*philo_thread->main_is_error)
			break ;
		start_sleeping(philo_thread);
		if (*philo_thread->main_is_error
			|| is_program_stopped_philo(philo_thread))
		{
			break ;
		}
	}
	return (NULL);
}
