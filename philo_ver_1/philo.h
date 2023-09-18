/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 15:31:21 by yshimoma          #+#    #+#             */
/*   Updated: 2023/05/03 14:29:08 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include <stdbool.h>
# include <pthread.h>
# include <sys/time.h>

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
//utils.c
bool	ft_is_error(int argc, char **argv);
bool	ft_set_pram(int ac, char **av, t_philosophers *philosophers);
bool	ft_set_philosophers(t_philosophers *philosophers);
bool	ft_set_philosopher(t_philosophers *philosophers);
//thread.c
void	*ft_philo_thread(void *v_philo_group);
bool	ft_is_dead_all(t_philosophers *philosophers);
void	ft_create_thread(t_philosophers *philosophers);
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

//ft_atoi.c
int				ft_atoi(const char *str);
//ft_isdigit.c
int				ft_isdigit(int c);

#endif
