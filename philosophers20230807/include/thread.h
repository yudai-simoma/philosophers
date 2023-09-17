/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 14:41:46 by yshimoma          #+#    #+#             */
/*   Updated: 2023/09/17 17:32:43 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef THREAD_H
# define THREAD_H

# include <stdbool.h>
# include "types.h"

typedef struct s_print {
	atomic_long		process_start_time;
	atomic_bool		*is_error;
	int				philo_id;
	char			*message;
}	t_print;

int		create_thread(
			t_main_thread *main_thread,
			t_philo_thread *philo_thread);

void	*create_philo_thread(void *tmp);

void	wait_for_thread(
			pthread_t *threads,
			t_main_thread *main_thread,
			t_philo_thread *philo_thread);

bool	is_program_stopped_main(t_main_thread *main_thread);

bool	is_program_stopped_philo(t_philo_thread *philo_thread);

bool	is_program_stopped(
			const atomic_bool is_stopped,
			const atomic_int everyone_is_eaten);

void	print_message_main(
			t_main_thread *main_thread,
			int philo_id,
			char *message);

void	print_message_philo(t_philo_thread *philo_thread, char *message);

void	print_message(t_print print);

#endif
