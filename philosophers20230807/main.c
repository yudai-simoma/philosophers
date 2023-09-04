/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 20:10:30 by yshimoma          #+#    #+#             */
/*   Updated: 2023/09/04 17:39:37 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "error.h"
#include "init.h"
#include "utils.h"
#include "thread.h"

static void	_free_main_thread(
	t_main_thread *main_thread,
	t_philo_thread *philo_thread)
{
	free(main_thread->forks);
	free(philo_thread);
}

#include <stdio.h>
int	main(void)
{
	int		argc = 5;
	char		*argv[] = {"./philosophers", "4", "410", "200", "200"};
	t_main_thread	main_thread;
	t_philo_thread	*philo_thread;

	main_thread.is_error = false;
	philo_thread = NULL;
	if (is_error(argc, argv)
		|| main_thread_init(argc, argv, &main_thread) == EXIT_FAILURE
		|| philo_thread_init(&philo_thread,
			main_thread.args_info.number_of_philosophers,
			main_thread.args_info.number_of_times_each_philosopher_must_eat)
		== EXIT_FAILURE
		|| create_thread(&main_thread, philo_thread) == EXIT_FAILURE)
	{
		_free_main_thread(&main_thread, philo_thread);
		ft_putstr_error("Error", &main_thread.is_error);
		return (EXIT_FAILURE);
	}
	_free_main_thread(&main_thread, philo_thread);
	if (main_thread.is_error)
		return (EXIT_FAILURE);
	else
		return (EXIT_SUCCESS);
}
