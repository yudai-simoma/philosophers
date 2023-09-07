/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_program_stopped_main.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 19:52:45 by yshimoma          #+#    #+#             */
/*   Updated: 2023/09/07 20:23:20 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include "types.h"
#include "action.h"

/*
 * 死亡フラグの読み取りを行う
 */
#include <stdio.h>
bool	is_program_stopped_main(t_main_thread *main_thread)
{
	// printf("main_mutex P=%p\n", &main_thread->stopped_mutex);
	// printf("is_dead P=%p\n", &main_thread->is_dead);
	// printf("is_error P=%p\n", &main_thread->is_error);
	// printf("everyone_is_eaten P=%p\n", &main_thread->everyone_is_eaten);
	return (
		is_program_stopped(
			&main_thread->stopped_mutex,
			&main_thread->is_dead,
			&main_thread->is_error,
			main_thread->everyone_is_eaten
		)
	);
}
