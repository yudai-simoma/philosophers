/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 11:24:50 by yshimoma          #+#    #+#             */
/*   Updated: 2023/09/04 19:39:29 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
# define TYPES_H

# include <pthread.h>
# include <sys/time.h>
# include <stdbool.h>

/*
 * 哲学者一人の構造体
 */
typedef struct s_philosopher {
	int				left_fork;
	int				right_fork;
	time_t			eat_start_time;
	pthread_mutex_t	eat_start_time_mutex;
	int				eat_count;
}	t_philosopher;

typedef struct s_philo_thread {
	int				philo_id;
	t_philosopher	philo;
	pthread_mutex_t	philo_thread_mutex;
	pthread_mutex_t	*main_forks;
	time_t			*main_process_start_time;
	bool			*main_is_dead;
	bool			*main_is_error;
	int				*main_everyone_is_eaten;
	int				*main_args_time_to_eat;
	int				*main_args_time_to_sleep;
}	t_philo_thread;

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
	pthread_mutex_t	*forks;
	pthread_mutex_t	main_thread_mutex;
	pthread_mutex_t	print_mutex;
	t_args_info		args_info;
	// pthread_mutex_t	stopped_mutex;
	time_t			process_start_time;
	bool			is_dead;
	bool			is_error;
	int				everyone_is_eaten;
}	t_main_thread;

#endif