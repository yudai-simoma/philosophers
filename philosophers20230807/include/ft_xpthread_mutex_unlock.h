/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xpthread_mutex_unlock.h                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 19:40:25 by yshimoma          #+#    #+#             */
/*   Updated: 2023/09/03 20:20:26 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_XPTHREAD_MUTEX_UNLOCK_H
# define FT_XPTHREAD_MUTEX_UNLOCK_H

int	ft_xpthread_mutex_lock(pthread_mutex_t *mutex, bool *is_error);

#endif
