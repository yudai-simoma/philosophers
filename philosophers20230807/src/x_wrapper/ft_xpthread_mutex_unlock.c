/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xpthread_mutex_unlock.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 19:39:24 by yshimoma          #+#    #+#             */
/*   Updated: 2023/09/07 22:22:03 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <stdbool.h>
#include <stdatomic.h>

int	ft_xpthread_mutex_unlock(pthread_mutex_t *mutex, atomic_bool *is_error)
{
	int	ret;

	ret = 0;
	if (!(*is_error))
		ret = pthread_mutex_unlock(mutex);
	if (ret != 0)
		*is_error = true;
	return (ret);
}
