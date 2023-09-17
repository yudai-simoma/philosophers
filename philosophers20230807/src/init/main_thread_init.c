/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_thread_init.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 23:11:27 by yshimoma          #+#    #+#             */
/*   Updated: 2023/09/17 13:49:35 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdatomic.h>
#include "libft.h"
#include "types.h"
#include "config.h"
#include "time_utils.h"

static void	_forks_mutex_destroy(pthread_mutex_t **forks, const int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		pthread_mutex_destroy(&((*forks)[i]));
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
	else
		args_info->number_of_times_each_philosopher_must_eat = NO_NUMBER;
}

static int	_set_forks_mutex(
	pthread_mutex_t **forks,
	const int number_of_philosophers)
{
	int	i;

	i = 0;
	*forks = malloc(sizeof(pthread_mutex_t) * number_of_philosophers);
	if (*forks == NULL)
		return (EXIT_FAILURE);
	while (i < number_of_philosophers)
	{
		if (pthread_mutex_init(&((*forks)[i]), NULL) != 0)
		{
			_forks_mutex_destroy(forks, i);
			return (EXIT_FAILURE);
		}
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
	if (_set_forks_mutex(&main_thread->forks,
			main_thread->args_info.number_of_philosophers) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	set_current_time(&main_thread->process_start_time, &main_thread->is_error);
	if (main_thread->is_error
		|| pthread_mutex_init(&main_thread->print_mutex, NULL) != 0)
	{
		_forks_mutex_destroy(
			&main_thread->forks, main_thread->args_info.number_of_philosophers);
		return (EXIT_FAILURE);
	}
	main_thread->is_dead = false;
	main_thread->everyone_is_eaten
		= main_thread->args_info.number_of_times_each_philosopher_must_eat;
	return (EXIT_SUCCESS);
}
