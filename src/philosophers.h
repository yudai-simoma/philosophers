/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 19:06:24 by yshimoma          #+#    #+#             */
/*   Updated: 2023/04/26 20:14:48 by yshimoma         ###   ########.fr       */
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

enum e_status {
	EATING,
	SLEEPING,
	THINKING,
	IDLE,
	DEAD
};

typedef struct s_elapsed {
	int	start_time;
	int	eat_time;
	int	action_time;
}	t_elapsed;

typedef struct s_philosopher {
	t_elapsed	elapsed;
	int			number;
	int			status;
	int			before_status;
	int			right_fork;
	int			left_fork;
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
}	t_philosophers;

typedef struct s_philo_group {
	t_philosopher	*philosopher;
	t_philosophers	*philosophers;
}	t_philo_group;

//thread.c
bool	ft_create_thread(t_philosophers *philosophers);
//action.c
bool	ft_put_has_fork(t_philosopher *philo, time_t timestamp);
bool	ft_put_eat(t_philosopher *philo, time_t timestamp);
bool	ft_put_sleep(t_philosopher *philo, time_t timestamp);
bool	ft_put_think(t_philosopher *philo, time_t timestamp);
bool	ft_put_died(t_philosopher *philo, time_t timestamp);
//time.c


//ft_atoi.c
int		ft_atoi(const char *str);
//ft_isdigit.c
int		ft_isdigit(int c);
#endif