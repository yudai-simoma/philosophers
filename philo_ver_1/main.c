/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 15:45:18 by yshimoma          #+#    #+#             */
/*   Updated: 2023/05/03 14:56:46 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	free_mutex_and_memory(t_philosophers *philosophers)
{
	int	i_;

	pthread_mutex_destroy(&philosophers->stopped_mutex);
	pthread_mutex_destroy(&philosophers->print_mutex);
	i_ = 0;
	while (i_ < philosophers->num_people)
	{
		pthread_mutex_destroy(&philosophers->forks[i_]);
		// pthread_mutex_destroy(&philosophers->philosopher[i_].philo_thread_mutex);
		i_++;
	}
	free(philosophers->philosopher);
	free(philosophers->forks);
	return ;
}

int	main(void)
{
	// char *argv[5] = {"./philo", "10", "410", "200", "200"};
	char *argv[5] = {"./philo", "3", "200", "120", "120"};
	int argc = 5;
	// char *argv[6] = {"./philo", "5", "800", "200", "200", "7"};
	// int argc = 6;
	t_philosophers	philosophers;

	if (ft_is_error(argc, argv)
		|| ft_set_pram(argc, argv, &philosophers)
		|| ft_set_philosophers(&philosophers)
		|| ft_set_philosopher(&philosophers))
	{
		printf ("Error\n");
		return (0);
	}
	ft_create_thread(&philosophers);
	free_mutex_and_memory(&philosophers);
	if (philosophers.error_flg)
		printf ("Error1\n");
	return (0);
}
