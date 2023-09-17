/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 20:10:30 by yshimoma          #+#    #+#             */
/*   Updated: 2023/09/16 22:56:23 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "error.h"
#include "init.h"
#include "utils.h"
#include "thread.h"
#include "config.h"

static void	_free_main_thread(
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
	free(main_thread->forks);
	free(philo_thread);
}

/**
 * TODO
 * ./philo 6 410 200 200 4 で死亡メッセージを出さずに終了させる_OK
 * ./philo 6 405 200 200 で死亡メッセージの後に何も出力させない事_OK
 * ./philo 31 500 200 200 で死なない事
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
		|| main_thread_init(argc, argv, &main_thread) == EXIT_FAILURE
		|| philo_thread_init(&philo_thread,
			main_thread.args_info.number_of_philosophers,
			main_thread.args_info.number_of_times_each_philosopher_must_eat)
		== EXIT_FAILURE
		|| create_thread(&main_thread, philo_thread) == EXIT_FAILURE)
	{
		_free_main_thread(&main_thread, philo_thread);
		ft_putstr_error(SYSTEM_ERR_MSG, &main_thread.is_error);
		return (EXIT_FAILURE);
	}
	_free_main_thread(&main_thread, philo_thread);
	if (main_thread.is_error)
		return (EXIT_FAILURE);
	else
		return (EXIT_SUCCESS);
}
