/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 14:41:46 by yshimoma          #+#    #+#             */
/*   Updated: 2023/09/17 12:56:35 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef THREAD_H
# define THREAD_H

# include <stdbool.h>
# include "types.h"

int		create_thread(
			t_main_thread *main_thread,
			t_philo_thread *philo_thread);

void	*create_philo_thread(void *tmp);

void	wait_for_thread(
			pthread_t *threads,
			t_main_thread *main_thread,
			t_philo_thread *philo_thread);

#endif
