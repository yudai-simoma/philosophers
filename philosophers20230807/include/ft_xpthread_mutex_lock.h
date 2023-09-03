/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xpthread_mutex_lock.h                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 19:38:41 by yshimoma          #+#    #+#             */
/*   Updated: 2023/09/03 19:39:14 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_XPTHREAD_MUTEX_LOCK_H
# define FT_XPTHREAD_MUTEX_LOCK_H

# include <pthread.h>
# include <stdbool.h>

int	ft_xpthread_mutex_lock(pthread_mutex_t *mutex, bool *is_error);

#endif
