/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 11:24:50 by yshimoma          #+#    #+#             */
/*   Updated: 2023/09/07 22:35:29 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
# define TYPES_H

# include <pthread.h>
# include <sys/time.h>
# include <stdbool.h>
# include <stdatomic.h>

/*
 * 哲学者一人の構造体
 */
typedef struct s_philosopher {
	int				left_fork;
	int				right_fork;
	atomic_long		eat_start_time;
	int				eat_count;
}	t_philosopher;

typedef struct s_philo_thread {
	int				philo_id;
	t_philosopher	philo;
	pthread_mutex_t	*main_forks;
	atomic_long		*main_process_start_time;
	atomic_bool		*main_is_dead;
	atomic_bool		*main_is_error;
	atomic_int		*main_everyone_is_eaten;
	atomic_int		*main_args_time_to_eat;
	atomic_int		*main_args_time_to_sleep;
	pthread_mutex_t	*main_stopped_mutex;
	pthread_mutex_t	*main_time_mutex;
	pthread_mutex_t	*main_eat_mutex;
}	t_philo_thread;

typedef struct s_args_info {
	int			number_of_philosophers;
	int			time_to_die;
	atomic_int	time_to_eat;
	atomic_int	time_to_sleep;
	int			number_of_times_each_philosopher_must_eat;
}	t_args_info;

/*
 * 哲学者全員の構造体
 */
typedef struct s_main_thread {
	pthread_mutex_t	*forks;
	pthread_mutex_t	stopped_mutex;
	pthread_mutex_t	time_mutex;
	pthread_mutex_t	eat_mutex;
	t_args_info		args_info;
	atomic_long		process_start_time;
	atomic_bool		is_dead;
	atomic_bool		is_error;
	atomic_int		everyone_is_eaten;
}	t_main_thread;

#endif