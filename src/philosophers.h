/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 19:06:24 by yshimoma          #+#    #+#             */
/*   Updated: 2023/04/21 19:15:51 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H
# include <stdio.h>
# include <ctype.h>
# include <stdbool.h>

enum e_status {
	EATING,
	SLEEPING,
	THINKING,
	IDLE,
	DEAD
};

typedef struct s_philosopher {
	int	number;
	int	status;
}	t_philosopher;

typedef struct s_philosophers {
	t_philosopher	philosopher;
	size_t			num_people;
	size_t			die_time;
	size_t			eat_time;
	size_t			sleep_time;
	size_t			philosopher_eating_count;
	size_t			remaining_forks;
}	t_philosophers;

#endif