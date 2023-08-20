/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 18:03:58 by yshimoma          #+#    #+#             */
/*   Updated: 2023/08/18 20:24:13 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdbool.h>
# include <pthread.h>
# include <sys/time.h>
# include "thread.h"

typedef struct s_args_info {
	int	number_of_philosophers;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	number_of_times_each_philosopher_must_eat;
}	t_args_info;

/*
 * 哲学者全員の構造体
 */
typedef struct s_main_thread {
	t_philo_thread	*philo_thread;
	pthread_mutex_t	main_thread_mutex;
	pthread_mutex_t	print_mutex;
	t_args_info		args_info;
	// pthread_mutex_t	stopped_mutex;
	time_t			process_start_time;
	bool			is_dead;
	bool			is_error;
	int				everyone_is_eaten;
}	t_main_thread;

//main.c
// void	free_mutex_and_memory(t_philosophers *philosophers);

//time.c
// bool	ft_get_current_time(time_t *time, pthread_mutex_t *mutex);
// time_t	ft_get_time_diff(time_t start_time, time_t end_time, pthread_mutex_t *mutex);

//init.c
int	main_thread_init(
	int argc, char **argv, t_main_thread *main_thread, bool *is_error);

#endif
