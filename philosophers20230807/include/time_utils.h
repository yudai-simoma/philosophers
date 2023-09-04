/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_utils.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 14:41:52 by yshimoma          #+#    #+#             */
/*   Updated: 2023/09/04 15:03:20 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TIME_UTILS_H
# define TIME_UTILS_H

# include <stdbool.h>
# include <pthread.h>
# include <sys/time.h>

int		get_time_diff(
			const time_t start_time,
			const time_t end_time,
			pthread_mutex_t *mutex,
			bool *is_error);

void	set_current_time(
			time_t *set_time,
			pthread_mutex_t *mutex,
			bool *is_error);

#endif
