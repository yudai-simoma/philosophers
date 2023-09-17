/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 20:10:30 by yshimoma          #+#    #+#             */
/*   Updated: 2023/09/17 16:22:37 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "error.h"
#include "init.h"
#include "utils.h"
#include "thread.h"
#include "config.h"

static void	_free_and_mutex_destroy(
	t_main_thread *main_thread,
	t_philo_thread *philo_thread)
{
	int	i;

	i = 0;
	while (i < main_thread->args_info.number_of_philosophers)
	{
		pthread_mutex_destroy(&main_thread->forks[i]);
		i++;
	}
	pthread_mutex_destroy(&main_thread->print_mutex);
	free(main_thread->forks);
	free(philo_thread);
}

/**
 * TODO
 * ./philo 6 410 200 200 4 で死亡メッセージを出さずに終了させる_OK
 * ./philo 6 405 200 200 で死亡メッセージの後に何も出力させない事_OK
 * ./philo 6 410 200 200 4 で全員が4回食べていない_OK(visualizerで見ていたため勘違い)
 * ./philo 31 500 200 200 で死なない事
 * ./philo 3 610 200 200 で死なない事
 * ./philo 1 4100 200 200でフリーズしない事_OK
 * ./philo 5 710 200 200 7で全員が7回食べたのに終わらない
 * 引数のエラーチェックをする
 * 
*/
int	main(int argc, char *argv[])
{
	t_main_thread	main_thread;
	t_philo_thread	*philo_thread;

	main_thread.is_error = false;
	philo_thread = NULL;
	if (is_error(argc, argv)
		|| main_thread_init(argc, argv, &main_thread) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (philo_thread_init(&philo_thread,
			main_thread.args_info.number_of_philosophers,
			main_thread.args_info.number_of_times_each_philosopher_must_eat)
		== EXIT_FAILURE
		|| create_thread(&main_thread, philo_thread) == EXIT_FAILURE)
	{
		_free_and_mutex_destroy(&main_thread, philo_thread);
		ft_putstr_error(SYSTEM_ERR_MSG, &main_thread.is_error);
		return (EXIT_FAILURE);
	}
	_free_and_mutex_destroy(&main_thread, philo_thread);
	if (main_thread.is_error)
		return (EXIT_FAILURE);
	else
		return (EXIT_SUCCESS);
}
