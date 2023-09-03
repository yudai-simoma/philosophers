/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_eating.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 21:13:02 by yshimoma          #+#    #+#             */
/*   Updated: 2023/09/03 21:13:28 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef START_EATING_H
# define START_EATING_H

# include "types.h"

void	start_eating(
			pthread_mutex_t *left_fork,
			pthread_mutex_t *right_fork,
			t_main_thread *main_thread,
			t_philo_thread *philo_thread);

#endif
