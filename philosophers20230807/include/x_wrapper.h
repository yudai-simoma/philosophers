/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x_wrapper.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 14:42:02 by yshimoma          #+#    #+#             */
/*   Updated: 2023/09/04 14:49:48 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef X_WRAPPER_H
# define X_WRAPPER_H

# include <pthread.h>
# include <stdbool.h>

int	ft_xpthread_mutex_lock(pthread_mutex_t *mutex, bool *is_error);

int	ft_xpthread_mutex_unlock(pthread_mutex_t *mutex, bool *is_error);

#endif
