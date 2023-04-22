/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 19:07:41 by yshimoma          #+#    #+#             */
/*   Updated: 2023/04/22 13:12:05 by yshimoma         ###   ########.fr       */
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
	philosophers->num_people = atoi(av[1]);
	philosophers->die_time = atoi(av[2]);
	philosophers->eat_time = atoi(av[3]);
	philosophers->sleep_time = atoi(av[4]);
	// philosophers->remaining_forks = philosophers->num_people;
	if (ac == 6)
		philosophers->philosopher_eating_count = atoi(av[5]);
	return (false);
}

bool	ft_set_philosopher(t_philosophers *philosophers)
{
	size_t	i_;

	philosophers->philosopher = (t_philosopher *)malloc(
			sizeof(t_philosopher) * philosophers->num_people);
	if (philosophers->philosopher == NULL)
		return (true);
	i_ = 0;
	while (i_ < philosophers->num_people)
	{
		philosophers->philosopher[i_].number = (int)i_;
		philosophers->philosopher[i_].status = IDLE;
		if (pthread_mutex_init(
				&philosophers->philosopher[i_].right_fork, NULL) != 0)
		{
			free(philosophers->philosopher);
			return (true);
		}
		if (pthread_mutex_init(
				&philosophers->philosopher[i_].left_fork, NULL) != 0)
		{
			free(philosophers->philosopher);
			return (true);
		}
		i_++;
	}
	return (false);
}

/*
 * TODO:
 * 	pthread_mutex_destroyの使用
 */
int	main(void)
{
	char *argv[6] = {"./philosophers", "3", "200", "50", "50", "5"};
	int argc = 6;
	t_philosophers	philosophers;

	if (ft_is_error(argc, argv)
		|| ft_set_pram(argc, argv, &philosophers)
		|| ft_set_philosopher(&philosophers)
		|| ft_create_philo(&philosophers))
	{
		printf ("Error\n");
		return (0);
	}
	return (0);
}
