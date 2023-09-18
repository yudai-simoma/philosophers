/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_utils.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 14:41:52 by yshimoma          #+#    #+#             */
/*   Updated: 2023/09/11 21:14:16 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TIME_UTILS_H
# define TIME_UTILS_H

# include <stdbool.h>
# include <pthread.h>
# include <sys/time.h>
# include <stdatomic.h>

int		get_time_diff(const atomic_long start_time, const atomic_long end_time);

void	set_current_time(atomic_long *set_time, atomic_bool *is_error);

#endif
