/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_program_stopped.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 19:56:29 by yshimoma          #+#    #+#             */
/*   Updated: 2023/09/16 17:28:49 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <pthread.h>
#include <stdatomic.h>
#include "config.h"
#include "x_wrapper.h"

/*
 * 死亡フラグの読み取りを行う
 */
bool	is_program_stopped(
	atomic_bool *is_dead,
	int everyone_is_eaten)
{
	bool	is_stopped;

	is_stopped = false;
	is_stopped = *is_dead;
	if (everyone_is_eaten == ALL_IS_EATEM_NO)
		is_stopped = true;
	return (is_stopped);
}
