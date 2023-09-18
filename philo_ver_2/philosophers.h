/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 19:06:24 by yshimoma          #+#    #+#             */
/*   Updated: 2023/05/02 15:58:20 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include <ctype.h>		//atoi用
# include <stdbool.h>	//true, flaseに使用
# include <pthread.h>	//スレッド関数用
# include <sys/time.h>	//システム時間取得用

/*
 * 哲学者一人の構造体
 */
typedef struct s_philosopher {
	int				number;
	int				right_fork;
	int				left_fork;
	struct timeval	eat_start_time;
	int				eat_count;
}	t_philosopher;

/*
 * 哲学者全員の構造体
 */
typedef struct s_philosophers {
	t_philosopher	*philosopher;
	pthread_mutex_t	*forks;
	int				num_people;
	int				die_time;
	int				eat_time;
	int				sleep_time;
	int				philosopher_eat_count;
	int				everyone_has_eaten;
	struct timeval	start_time;
	pthread_mutex_t	die_mutex;
	bool			die_flg;
	bool			error_flg;
	pthread_mutex_t	print_mutex;
}	t_philosophers;

/*
 * 哲学者全員と哲学者一人の構造体
 */
typedef struct s_philo_group {
	t_philosopher	*philosopher;
	t_philosophers	*philosophers;
}	t_philo_group;

//thread.c
bool			ft_create_thread(t_philosophers *philosophers);
//action.c
bool			ft_has_fork(pthread_mutex_t *fork,
					t_philosophers *philosophers, t_philosopher *philosopher);
bool			ft_start_eating(pthread_mutex_t *left_fork,
					pthread_mutex_t *right_fork, t_philosophers *philosophers,
					t_philosopher *philosopher);
bool			ft_start_sleeping(t_philosophers *philosophers,
					t_philosopher *philosopher);
bool			ft_is_dead(t_philosophers *philosophers,
					t_philosopher *philosopher);
//time.c
time_t			ft_get_time_diff(struct timeval start_time,
					struct timeval end_time);
//ft_action_utils.c
bool			ft_write_die_flg(t_philosophers *philosophers);
bool			ft_is_program_stopped(t_philosophers *philosopher);
bool			ft_pfint_message(t_philosophers *philosophers,
					t_philosopher *philosopher, char *message);
//ft_atoi.c
int				ft_atoi(const char *str);
//ft_isdigit.c
int				ft_isdigit(int c);

#endif