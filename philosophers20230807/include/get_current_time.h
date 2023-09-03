/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_current_time.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 11:47:21 by yshimoma          #+#    #+#             */
/*   Updated: 2023/09/03 11:48:28 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_CURRENT_TIME_H
# define GET_CURRENT_TIME_H

# include <stdbool.h>
# include <pthread.h>
# include <sys/time.h>

time_t	get_current_time(pthread_mutex_t *mutex, bool *is_error);

#endif
