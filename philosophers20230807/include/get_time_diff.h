/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_time_diff.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 19:24:55 by yshimoma          #+#    #+#             */
/*   Updated: 2023/09/03 19:25:29 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_TIME_DIFF_H
# define GET_TIME_DIFF_H

# include <time.h>
# include <pthread.h>
# include <stdbool.h>

int	get_time_diff(
		const time_t start_time,
		const time_t end_time,
		pthread_mutex_t *mutex,
		bool *is_error);

#endif
