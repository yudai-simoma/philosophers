/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_time_diff.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 19:12:05 by yshimoma          #+#    #+#             */
/*   Updated: 2023/09/11 21:14:11 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <time.h>
#include <stdatomic.h>

/*
 * 二つの時間を受け取り、その差分を返す関数
 */
int	get_time_diff(const atomic_long start_time, const atomic_long end_time)
{
	return (end_time - start_time);
}
