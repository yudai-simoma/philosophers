/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_thread_init.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 23:11:27 by yshimoma          #+#    #+#             */
/*   Updated: 2023/09/03 12:10:44 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "types.h"
#include "get_current_time.h"

static void	_philosopher_init(t_philosopher philo, bool *is_error)
{
	philo.has_right_fork = false;
	philo.has_left_fork = false;
	philo.eat_start_time = 0;
	if (pthread_mutex_init(&philo.eat_start_time_mutex, NULL) != 0)
	{
		*is_error = true;
		return ;
	}
	philo.eat_count = 0;
}

static void	_philo_thread_init(
	t_philo_thread *philo_thread, t_args_info *args_info, bool *is_error)
{
	int	i;

	philo_thread = (t_philo_thread *)malloc(sizeof(t_philo_thread)
			* (args_info->number_of_philosophers));
	if (philo_thread == NULL)
	{
		*is_error = true;
		return ;
	}
	i = 0;
	while (i < args_info->number_of_philosophers)
	{
		philo_thread->philo_id = i;
		_philosopher_init(philo_thread->philo, is_error);
		if (*is_error || pthread_mutex_init(&philo_thread->fork, NULL) != 0)
		{
			*is_error = true;
			return ;
		}
		i++;
	}
}

static void	_args_info_init(int argc, char **argv, t_args_info *args_info)
{
	args_info->number_of_philosophers = ft_atoi(argv[1]);
	args_info->time_to_die = ft_atoi(argv[2]);
	args_info->time_to_eat = ft_atoi(argv[3]);
	args_info->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		args_info->number_of_times_each_philosopher_must_eat = ft_atoi(argv[5]);
}

/**
 * t_main_threadに値を初期設定する関数
 */
int	main_thread_init(
	int argc, char **argv, t_main_thread *main_thread, bool *is_error)
{
	_args_info_init(argc, argv, &main_thread->args_info);
	_philo_thread_init(
		main_thread->philo_thread, &main_thread->args_info, is_error);
	if (*is_error)
		return (-1);
	if (pthread_mutex_init(&main_thread->main_thread_mutex, NULL) != 0
		|| pthread_mutex_init(&main_thread->print_mutex, NULL) != 0)
	{
		*is_error = true;
		return (-1);
	}
	main_thread->process_start_time
		= get_current_time(&main_thread->main_thread_mutex, is_error);
	if (*is_error)
		return (-1);
	main_thread->is_dead = false;
	main_thread->everyone_is_eaten = 0;
	return (0);
}
