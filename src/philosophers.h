/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 19:06:24 by yshimoma          #+#    #+#             */
/*   Updated: 2023/04/30 14:58:18 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include <ctype.h>		//atoi用
# include <stdbool.h>
# include <pthread.h>	//スレッド関数用
# include <sys/time.h>	//システム時間取得用
# include <unistd.h>	//sleep関数用,TODO:削除予定

// enum e_status {
// 	EATING,
// 	SLEEPING,
// 	THINKING,
// 	IDLE,
// 	DEAD
// };

// typedef struct s_elapsed {
// 	int	start_time;
// 	int	eat_time;
// 	int	action_time;
// }	t_elapsed;

typedef struct s_philosopher {
	// t_elapsed		elapsed;
	int				number;
	int				right_fork;
	int				left_fork;
	struct timeval	eat_start_time;
}	t_philosopher;

typedef struct s_philosophers {
	t_philosopher	*philosopher;
	pthread_mutex_t	*forks;
	int				num_people;
	int				die_time;
	int				eat_time;
	int				sleep_time;
	int				philosopher_eating_count;
	struct timeval	start_time;
	bool			die_flg;
	bool			error_flg;
}	t_philosophers;

typedef struct s_philo_group {
	t_philosopher	*philosopher;
	t_philosophers	*philosophers;
}	t_philo_group;

//thread.c
void			ft_free_exit(t_philosophers *philosophers,
					t_philosopher *philosopher);
bool			ft_create_thread(t_philosophers *philosophers);
//action.c
//TODO:	出力結果を変更する
bool			ft_has_fork(pthread_mutex_t *fork,
					t_philosophers *philosophers, t_philosopher *philosopher,
					int flg);
bool			ft_start_eating(pthread_mutex_t *left_fork,
					pthread_mutex_t *right_fork, t_philosophers *philosophers,
					t_philosopher *philosopher);
bool			ft_start_sleeping(t_philosophers *philosophers,
					t_philosopher *philosopher);
bool			ft_put_think(t_philosopher *philo, time_t timestamp);
bool			ft_is_dead(t_philosophers *philosophers,
					t_philosopher *philosopher);
//time.c
bool			ft_get_elapsed_time(struct timeval start_time,
					struct timeval *elapsed_time);
struct timeval	ft_get_time_diff(struct timeval start_time,
					struct timeval end_time);
//ft_atoi.c
int				ft_atoi(const char *str);
//ft_action_utils.c
bool			ft_write_die_flg(bool *die_flg);
bool			ft_read_die_flg(t_philosophers *philosopher);
//ft_isdigit.c
int				ft_isdigit(int c);
#endif