/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_program_stopped.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 19:56:29 by yshimoma          #+#    #+#             */
/*   Updated: 2023/09/17 17:35:01 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <pthread.h>
#include <stdatomic.h>
#include "config.h"
#include "x_wrapper.h"

/*
 * プログラム終了フラグの読み取りを行う
 */
bool	is_program_stopped(
	const atomic_bool is_stopped,
	const atomic_int everyone_is_eaten)
{
	bool	result;

	result = false;
	result = is_stopped;
	if (everyone_is_eaten == ALL_IS_EATEM_NO)
		result = true;
	return (result);
}
