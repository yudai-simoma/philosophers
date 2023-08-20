/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 18:13:29 by yshimoma          #+#    #+#             */
/*   Updated: 2023/08/13 22:39:58 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef THREAD_H
# define THREAD_H

# include <pthread.h>
# include <sys/time.h>
# include "philo.h"

/*
 * 哲学者一人の構造体
 */
typedef struct s_philosopher {
	bool			has_right_fork;
	bool			has_left_fork;
	time_t			eat_start_time;
	pthread_mutex_t	eat_start_time_mutex;
	int				eat_count;
}	t_philosopher;

typedef struct s_philo_thread {
	int				philo_id;
	t_philosopher	philo;
	pthread_mutex_t	fork;
	// pthread_mutex_t	philo_thread;
}	t_philo_thread;

//thread.c
// void	*ft_philo_thread(void *v_philo_group);
// bool	ft_is_dead_all(t_philosophers *philosophers);
// void	ft_create_thread(t_philosophers *philosophers);

#endif
