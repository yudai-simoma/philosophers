/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 19:12:59 by yshimoma          #+#    #+#             */
/*   Updated: 2023/05/02 16:11:46 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"


/*
 * 二つの時間を受け取り、その差分を返す関数
 */
time_t	ft_get_time_diff(struct timeval start_time, struct timeval end_time)
{
	struct timeval	deff_time_;

	deff_time_.tv_sec = end_time.tv_sec - start_time.tv_sec;
	deff_time_.tv_usec = end_time.tv_usec - start_time.tv_usec;
	if (deff_time_.tv_usec < 0)
	{
		deff_time_.tv_sec -= 1;
		deff_time_.tv_usec += 1000000;
	}
	return ((deff_time_.tv_sec * 1000) + (deff_time_.tv_usec / 1000));
}

// /*
//  * スタートからの経過時間を取得する
//  * TODO:4/29時点で不要
//  */
// bool	ft_get_elapsed_time(struct timeval start_time, t_elapsed *elapsed)
// {
// 	struct timeval	tmp_time_;
// 	int				err_flg_;

// 	err_flg_ = gettimeofday(&tmp_time_, NULL);
// 	elapsed->start_time = tmp_time_.tv_sec - start_time.tv_sec;
// 	if (err_flg_ < 0)
// 		return (true);
// 	return (false);
// }
