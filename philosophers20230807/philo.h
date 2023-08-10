/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 18:03:58 by yshimoma          #+#    #+#             */
/*   Updated: 2023/08/10 18:13:27 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H


/*
 * 哲学者一人の構造体
 */
typedef struct s_philosopher {
	int		number;
	int		right_fork;
	int		left_fork;
	time_t	eat_start_time;
	pthread_mutex_t	eat_start_time_mutex;
	int		eat_count;
	pthread_mutex_t	philo_thread_mutex;
}	t_philosopher;

/*
 * 哲学者全員の構造体
 */
typedef struct s_philosophers {
	t_philosopher	*philosopher;
	pthread_mutex_t	*forks;
	pthread_mutex_t	main_thread_mutex;
	pthread_mutex_t	print_mutex;
	pthread_mutex_t	stopped_mutex;
	bool			die_flg;
	bool			error_flg;
	time_t			process_start_time;
	int				num_people;
	int				die_time;
	int				eat_time;
	int				sleep_time;
	int				philosopher_eat_count;
	int				everyone_has_eaten;
}	t_philosophers;

/*
 * 哲学者全員と哲学者一人の構造体
 */
typedef struct s_philo_group {
	t_philosopher	*philosopher;
	t_philosophers	*philosophers;
}	t_philo_group;

//main.c
void	free_mutex_and_memory(t_philosophers *philosophers);

//action.c
void	ft_has_fork(pthread_mutex_t *fork,
			t_philosophers *philosophers, t_philosopher *philosopher);
void	ft_start_eating(pthread_mutex_t *left_fork, pthread_mutex_t *right_fork,
			t_philosophers *philosophers, t_philosopher *philosopher);
void	ft_start_sleeping(t_philosophers *philosophers,
			t_philosopher *philosopher);
bool	ft_is_dead(t_philosophers *philosophers,
			t_philosopher *philosopher);
//action_utils.c
bool	ft_is_program_stopped(t_philosophers *philosophers,
			pthread_mutex_t *mutex);
void	ft_pfint_message(t_philosophers *philosophers,
			t_philosopher *philosopher, char *message, pthread_mutex_t *mutex);
//time.c
bool	ft_get_current_time(time_t *time, pthread_mutex_t *mutex);
time_t	ft_get_time_diff(time_t start_time, time_t end_time, pthread_mutex_t *mutex);

#endif
