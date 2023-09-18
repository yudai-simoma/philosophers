/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x_wrapper.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 14:42:02 by yshimoma          #+#    #+#             */
/*   Updated: 2023/09/07 22:18:05 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef X_WRAPPER_H
# define X_WRAPPER_H

# include <pthread.h>
# include <stdbool.h>
# include <stdatomic.h>

int	ft_xpthread_mutex_lock(pthread_mutex_t *mutex, atomic_bool *is_error);

int	ft_xpthread_mutex_unlock(pthread_mutex_t *mutex, atomic_bool *is_error);

#endif
