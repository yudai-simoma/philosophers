/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_program_stopped_philo.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 19:52:36 by yshimoma          #+#    #+#             */
/*   Updated: 2023/09/17 14:06:03 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include "types.h"
#include "thread.h"

/*
 * 死亡フラグの読み取りを行う
 */
bool	is_program_stopped_philo(t_philo_thread *philo_thread)
{
	return (
		is_program_stopped(
			*(philo_thread->main_is_dead),
			*(philo_thread->main_everyone_is_eaten)
		)
	);
}
