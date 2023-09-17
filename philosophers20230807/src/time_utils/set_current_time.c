/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_current_time.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 11:38:41 by yshimoma          #+#    #+#             */
/*   Updated: 2023/09/17 17:35:26 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <pthread.h>
#include <sys/time.h>
#include <stdatomic.h>
#include "x_wrapper.h"

/*
 * 現在時間をミリ秒で取得し、取得した値をセット関数
 */
void	set_current_time(atomic_long *set_time, atomic_bool *is_error)
{
	struct timeval	current_time;

	if (gettimeofday(&current_time, NULL) != 0)
	{
		*is_error = true;
		return ;
	}
	*set_time = (current_time.tv_sec * 1000) + (current_time.tv_usec / 1000);
}
