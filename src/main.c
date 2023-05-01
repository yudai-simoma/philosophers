/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 19:07:41 by yshimoma          #+#    #+#             */
/*   Updated: 2023/05/01 22:48:41 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

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
	int	err_flg_;

	philosophers->num_people = ft_atoi(av[1]);
	philosophers->die_time = ft_atoi(av[2]);
	philosophers->eat_time = ft_atoi(av[3]);
	philosophers->sleep_time = ft_atoi(av[4]);
	philosophers->everyone_has_eaten = -1;
	err_flg_ = gettimeofday(&philosophers->start_time, NULL);
	if (err_flg_ < 0)
		return (true);
	if (ac == 6)
	{
		philosophers->philosopher_eat_count = ft_atoi(av[5]);
		philosophers->everyone_has_eaten = philosophers->num_people;
	}
	return (false);
}

/*
 * 構造体philosophersに初期値を設定
 */
bool	ft_set_philosophers(t_philosophers *philosophers)
{
	int	i_;
	int	err_flg_;

	philosophers->forks = (pthread_mutex_t *)malloc(
			sizeof(pthread_mutex_t) * philosophers->num_people);
	if (philosophers->forks == NULL)
		return (true);
	i_ = 0;
	while (i_ < philosophers->num_people)
	{
		err_flg_ = pthread_mutex_init(&philosophers->forks[i_], NULL);
		if (err_flg_ != 0)
			return (true);
		i_++;
	}
	if (pthread_mutex_init(&philosophers->die_mutex, NULL) != 0
		|| pthread_mutex_init(&philosophers->print_mutex, NULL) != 0)
		return (true);
	philosophers->die_flg = false;
	philosophers->error_flg = false;
	return (false);
}

/*
 * 構造体philosopherに初期値を設定
 */
bool	ft_set_philosopher(t_philosophers *philosophers)
{
	int	i_;

	philosophers->philosopher = (t_philosopher *)malloc(
			sizeof(t_philosopher) * philosophers->num_people);
	if (philosophers->philosopher == NULL)
		return (true);
	i_ = 0;
	while (i_ < philosophers->num_people)
	{
		philosophers->philosopher[i_].number = i_;
		philosophers->philosopher[i_].eat_count
			= philosophers->philosopher_eat_count;
		philosophers->philosopher[i_].left_fork = i_;
		if (i_ == 0)
			philosophers->philosopher[i_].right_fork
				= philosophers->num_people - 1;
		else
			philosophers->philosopher[i_].right_fork = i_ - 1;
		if (gettimeofday(&philosophers->philosopher[i_].eat_start_time,
				NULL) < 0)
			return (true);
		i_++;
	}
	return (false);
}

/*
 * 構造体の中身をフリーする
 */
bool	ft_free_philo(t_philosophers *philosophers)
{
	int	i_;

	if (pthread_mutex_destroy(&philosophers->die_mutex) != 0
		|| pthread_mutex_destroy(&philosophers->print_mutex) != 0)
		return (true);
	i_ = 0;
	while (i_ < philosophers->num_people)
	{
		if (pthread_mutex_destroy(&philosophers->forks[i_]) != 0)
		{
			printf("aaaaai = %d\n", i_);
			return (true);
		}
		i_++;
	}
	free(philosophers->philosopher);
	free(philosophers->forks);
	return (false);
}

/*
 * TODO:
 * 	処理のエラーがあったときはerror_flgを立てる処理の確認
 * 	サニタイザーのスレッド・アドレスを調査
 */
int	main(void)
{
	char *argv[5] = {"./philosophers", "3", "200", "120", "120"};
	int argc = 5;
	// char *argv[6] = {"./philosophers", "2", "200", "120", "120", "8"};
	// int argc = 6;
	t_philosophers	philosophers;

	if (ft_is_error(argc, argv)
		|| ft_set_pram(argc, argv, &philosophers)
		|| ft_set_philosophers(&philosophers)
		|| ft_set_philosopher(&philosophers)
		|| ft_create_thread(&philosophers))
	{
		printf ("Error\n");
		ft_free_philo(&philosophers);
		return (0);
	}
	if (ft_free_philo(&philosophers))
		printf ("Error\n");
	return (0);
}
