/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_thread_init.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 23:11:27 by yshimoma          #+#    #+#             */
/*   Updated: 2023/09/03 18:55:29 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "types.h"
#include "set_current_time.h"

static void	_args_info_init(int argc, char **argv, t_args_info *args_info)
{
	args_info->number_of_philosophers = ft_atoi(argv[1]);
	args_info->time_to_die = ft_atoi(argv[2]);
	args_info->time_to_eat = ft_atoi(argv[3]);
	args_info->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		args_info->number_of_times_each_philosopher_must_eat = ft_atoi(argv[5]);
	else
		args_info->number_of_times_each_philosopher_must_eat = 0;
}

static int	_set_forks_mutex(pthread_mutex_t *forks, int number_of_philosophers)
{
	int	i;

	i = 0;
	while (i < number_of_philosophers)
	{
		if (pthread_mutex_init(&forks[i], NULL) != 0)
			return (EXIT_FAILURE);
		i++;
	}
	return (EXIT_SUCCESS);
}


/**
 * t_main_threadに値を初期設定する関数
 */
int	main_thread_init(int argc, char **argv, t_main_thread *main_thread)
{
	_args_info_init(argc, argv, &main_thread->args_info);
	if (_set_forks_mutex(main_thread->forks,
			main_thread->args_info.number_of_philosophers) != EXIT_FAILURE
		pthread_mutex_init(&main_thread->main_thread_mutex, NULL) != 0
		|| pthread_mutex_init(&main_thread->print_mutex, NULL) != 0)
	{
		return (EXIT_FAILURE);
	}
	main_thread->process_start_time
		= set_current_time(&main_thread->main_thread_mutex, is_error);
	if (*is_error)
		return (-1);
	main_thread->is_dead = false;
	main_thread->everyone_is_eaten
		= main_thread->args_info.number_of_times_each_philosopher_must_eat;
	return (EXIT_SUCCESS);
}
