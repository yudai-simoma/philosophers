/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_thread_init.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 16:09:52 by yshimoma          #+#    #+#             */
/*   Updated: 2023/09/05 12:30:05 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdbool.h>
#include "types.h"
#include "config.h"

static int	_philosopher_init(
	t_philosopher *philo,
	const int philo_id,
	const int number_of_philosophers,
	const int number_of_times_each_philosopher_must_eat)
{
	philo->left_fork = philo_id;
	if (philo_id == FIRST_PHILO_ID)
		philo->right_fork = number_of_philosophers - RIGHT_FORK_DIFF;
	else
		philo->right_fork = philo_id - RIGHT_FORK_DIFF;
	philo->eat_start_time = START_TIME;
	if (pthread_mutex_init(&philo->eat_start_time_mutex, NULL) != 0)
	{
		return (EXIT_FAILURE);
	}
	philo->eat_count = number_of_times_each_philosopher_must_eat;
	return (EXIT_SUCCESS);
}

int	philo_thread_init(
	t_philo_thread **philo_thread,
	const int number_of_philosophers,
	const int number_of_times_each_philosopher_must_eat)
{
	int	i;

	*philo_thread = (t_philo_thread *)malloc(sizeof(t_philo_thread)
			* number_of_philosophers);
	if (*philo_thread == NULL)
		return (EXIT_FAILURE);
	i = 0;
	while (i < number_of_philosophers)
	{
		(*philo_thread)[i].philo_id = i;
		if (_philosopher_init(
				&(*philo_thread)[i].philo, i, number_of_philosophers,
			number_of_times_each_philosopher_must_eat) == EXIT_FAILURE
			|| pthread_mutex_init(
				&(*philo_thread)[i].philo_thread_mutex, NULL) != 0)
		{
			return (EXIT_FAILURE);
		}
		i++;
	}
	return (EXIT_SUCCESS);
}
