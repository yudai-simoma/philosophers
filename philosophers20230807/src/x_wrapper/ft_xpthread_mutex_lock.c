/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xpthread_mutex_lock.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 19:36:03 by yshimoma          #+#    #+#             */
/*   Updated: 2023/09/03 20:50:45 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <stdbool.h>

int	ft_xpthread_mutex_lock(pthread_mutex_t *mutex, bool *is_error)
{
	int	ret;

	ret = 0;
	if (!is_error)
		ret = pthread_mutex_lock(mutex);
	if (ret != 0)
		*is_error = true;
	return (ret);
}
