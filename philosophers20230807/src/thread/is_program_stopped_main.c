/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_program_stopped_main.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 19:52:45 by yshimoma          #+#    #+#             */
/*   Updated: 2023/09/17 14:05:48 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include "types.h"
#include "thread.h"

/*
 * 死亡フラグの読み取りを行う
 */
bool	is_program_stopped_main(t_main_thread *main_thread)
{
	return (
		is_program_stopped(
			main_thread->is_dead,
			main_thread->everyone_is_eaten
		)
	);
}
