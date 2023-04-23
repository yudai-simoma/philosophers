/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 11:12:24 by yshimoma          #+#    #+#             */
/*   Updated: 2023/04/22 14:23:12 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*ft_philo_thread(void *v_philosopher)
{
	t_philosopher	*philosopher_;

	philosopher_ = v_philosopher;
}

bool	ft_create_philo(t_philosophers *philosophers)
{
	size_t		i_;
	pthread_t	*thread;

	thread = (pthread_t *)malloc(sizeof(pthread_t) * philosophers->num_people);
	if (thread == NULL)
		return (0);
	i_ = 0;
	while (i_ < philosophers->num_people)
	{
		pthread_create(thread[i_], NULL,
			ft_philo_thread, &philosophers->philosopher[i_]);
		i_++;
	}
}
