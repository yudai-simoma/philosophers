/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 17:43:37 by yshimoma          #+#    #+#             */
/*   Updated: 2023/04/23 13:44:27 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

/*
 * フォークを持つ
 */
bool	ft_put_has_fork(t_philosopher *philo, time_t timestamp)
{
	int	rev_;

	rev_ = printf("%ld %d  has taken a fork\n", timestamp * 1000, philo->number);
	if (rev_ < 0)
		return (true);
	return (false);
}

/*
 * 食べる
 */
bool	ft_put_eat(t_philosopher *philo, time_t timestamp)
{
	int	rev_;

	rev_ = printf("%ld %d is eating\n", timestamp * 1000, philo->number);
	if (rev_ < 0)
		return (true);
	return (false);
}

/*
 * 寝る
 */
bool	ft_put_sleep(t_philosopher *philo, time_t timestamp)
{
	int	rev_;

	rev_ = printf("%ld %d is sleeping\n", timestamp * 1000, philo->number);
	if (rev_ < 0)
		return (true);
	return (false);
}

/*
 * 考える
 */
bool	ft_put_think(t_philosopher *philo, time_t timestamp)
{
	int	rev_;

	rev_ = printf("%ld %d is thinking\n", timestamp * 1000, philo->number);
	if (rev_ < 0)
		return (true);
	return (false);
}

/*
 * 死亡
 */
bool	ft_put_died(t_philosopher *philo, time_t timestamp)
{
	int	rev_;

	rev_ = printf("%ld %d died\n", timestamp * 1000, philo->number);
	if (rev_ < 0)
		return (true);
	return (false);
}
