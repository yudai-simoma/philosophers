/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 14:41:38 by yshimoma          #+#    #+#             */
/*   Updated: 2023/09/04 16:41:29 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT_H
# define INIT_H

# include "types.h"

int	main_thread_init(int argc, char **argv, t_main_thread *main_thread);

int	philo_thread_init(
		t_philo_thread **philo_thread,
		const int number_of_philosophers,
		const int number_of_times_each_philosopher_must_eat);

#endif
