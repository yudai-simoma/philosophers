/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 16:36:43 by yshimoma          #+#    #+#             */
/*   Updated: 2023/05/03 14:53:13 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
 * コマンドライン引数で受けっとった値のエラー処理
 */
bool	ft_is_error(int argc, char **argv)
{
	int		i_;
	size_t	j_;

	if (argc != 5 && argc != 6)
		return (true);
	i_ = 1;
	while (i_ < argc)
	{
		j_ = 0;
		while (argv[i_][j_] != '\0')
		{
			if (!ft_isdigit(argv[i_][j_]))
				return (true);
			j_++;
		}
		i_++;
	}
	return (false);
}

/*
 * コマンドライン引数で受けっとった値を構造体へ格納
 */
bool	ft_set_pram(int ac, char **av, t_philosophers *philosophers)
{
	philosophers->num_people = ft_atoi(av[1]);
	philosophers->die_time = ft_atoi(av[2]);
	philosophers->eat_time = ft_atoi(av[3]);
	philosophers->sleep_time = ft_atoi(av[4]);
	philosophers->philosopher_eat_count = -1;
	philosophers->everyone_has_eaten = -1;
	if (ac == 6)
	{
		philosophers->philosopher_eat_count = ft_atoi(av[5]);
		philosophers->everyone_has_eaten = philosophers->num_people;
	}
	return (false);
}

static bool	_ft_set_mutex(t_philosophers *philosophers)
{
	int	i_;

	if (pthread_mutex_init(&philosophers->stopped_mutex, NULL) != 0)
		return (true);
	if (pthread_mutex_init(&philosophers->print_mutex, NULL) != 0)
	{
		pthread_mutex_destroy(&philosophers->stopped_mutex);
		return (true);
	}
	if (pthread_mutex_init(&philosophers->main_thread_mutex, NULL) != 0)
	{
		pthread_mutex_destroy(&philosophers->stopped_mutex);
		pthread_mutex_destroy(&philosophers->print_mutex);
		return (true);
	}
	i_ = 0;
	while (i_ < philosophers->num_people)
	{
		if (pthread_mutex_init(&philosophers->forks[i_], NULL) != 0)
		{
			pthread_mutex_destroy(&philosophers->stopped_mutex);
			pthread_mutex_destroy(&philosophers->print_mutex);
			pthread_mutex_destroy(&philosophers->main_thread_mutex);
			while (i_--)
				pthread_mutex_destroy(&philosophers->forks[i_]);
			return (true);
		}
		if (pthread_mutex_init(
				&philosophers->philosopher[i_].eat_start_time_mutex, NULL) != 0)
		{
			pthread_mutex_destroy(&philosophers->stopped_mutex);
			pthread_mutex_destroy(&philosophers->print_mutex);
			pthread_mutex_destroy(&philosophers->main_thread_mutex);
			while (i_--)
				pthread_mutex_destroy(
					&philosophers->philosopher[i_].eat_start_time_mutex);
			return (true);
		}
		i_++;
	}
	return (false);
}

/*
 * 構造体philosophersに初期値を設定
 */
bool	ft_set_philosophers(t_philosophers *philosophers)
{
	philosophers->philosopher = (t_philosopher *)malloc(
			sizeof(t_philosopher) * philosophers->num_people);
	if (philosophers->philosopher == NULL)
		return (true);
	philosophers->forks = (pthread_mutex_t *)malloc(
			sizeof(pthread_mutex_t) * philosophers->num_people);
	if (philosophers->forks == NULL)
	{
		free(philosophers->philosopher);
		return (true);
	}
	philosophers->die_flg = false;
	philosophers->error_flg = false;
	if (_ft_set_mutex(philosophers)
		|| !ft_get_current_time(&philosophers->process_start_time, &philosophers->main_thread_mutex))
		return (true);
	return (false);
}

/*
 * 構造体philosopherに初期値を設定
 */
bool	ft_set_philosopher(t_philosophers *philosophers)
{
	int	i_;

	i_ = 0;
	while (i_ < philosophers->num_people)
	{
		philosophers->philosopher[i_].number = i_;
		philosophers->philosopher[i_].left_fork = i_;
		if (i_ == 0)
			philosophers->philosopher[i_].right_fork
				= philosophers->num_people - 1;
		else
			philosophers->philosopher[i_].right_fork = i_ - 1;
		philosophers->philosopher[i_].eat_count
			= philosophers->philosopher_eat_count;
		if (!ft_get_current_time(&philosophers->philosopher[i_].eat_start_time, &philosophers->main_thread_mutex))
		{
			free_mutex_and_memory(philosophers);
			return (true);
		}
		i_++;
	}
	return (false);
}
