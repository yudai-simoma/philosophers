/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   has_fork.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 15:25:50 by yshimoma          #+#    #+#             */
/*   Updated: 2023/09/03 21:35:02 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HAS_FORK_H
# define HAS_FORK_H

# include <pthread.h>
# include "types.h"

void	has_fork(
			pthread_mutex_t *fork,
			t_main_thread *main_thread,
			t_philo_thread *philo_thread);

#endif