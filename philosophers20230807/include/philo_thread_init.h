/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_thread_init.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 16:19:50 by yshimoma          #+#    #+#             */
/*   Updated: 2023/09/03 17:22:27 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_THREAD_INIT_H
# define PHILO_THREAD_INIT_H

# include <types.h>

int	philo_thread_init(
		t_philo_thread *philo_thread,
		const int number_of_philosophers);

#endif