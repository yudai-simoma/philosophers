/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_utils.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 14:41:52 by yshimoma          #+#    #+#             */
/*   Updated: 2023/09/07 22:33:06 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TIME_UTILS_H
# define TIME_UTILS_H

# include <stdbool.h>
# include <pthread.h>
# include <sys/time.h>
# include <stdatomic.h>

int		get_time_diff(
			const time_t start_time,
			const time_t end_time,
			pthread_mutex_t *mutex,
			atomic_bool *is_error);

void	set_current_time(
			atomic_long *set_time,
			pthread_mutex_t *mutex,
			atomic_bool *is_error);

#endif
