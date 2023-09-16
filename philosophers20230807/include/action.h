/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 14:41:25 by yshimoma          #+#    #+#             */
/*   Updated: 2023/09/16 17:44:04 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ACTION_H
# define ACTION_H

# include <pthread.h>
# include <stdatomic.h>
# include <stdatomic.h>
# include "types.h"

typedef struct s_print {
	atomic_long		process_start_time;
	atomic_bool		*is_error;
	int				philo_id;
	char			*message;
}	t_print;

void	has_fork(
			pthread_mutex_t *fork,
			t_philo_thread *philo_thread);

void	has_forks_even_philosopher(t_philo_thread *philo_thread);

void	has_forks_odd_philosopher(t_philo_thread *philo_thread);

bool	is_program_stopped_main(t_main_thread *main_thread);

bool	is_program_stopped_philo(t_philo_thread *philo_thread);

bool	is_program_stopped(
			atomic_bool *is_dead,
			atomic_int everyone_is_eaten);

void	print_message_main(
			t_main_thread *main_thread,
			int philo_id,
			char *message);

void	print_message_philo(t_philo_thread *philo_thread, char *message);

void	print_message(t_print print);

void	start_eating(
			pthread_mutex_t *left_fork,
			pthread_mutex_t *right_fork,
			t_philo_thread *philo_thread);

void	start_sleeping(
			t_philo_thread *philo_thread);

#endif
