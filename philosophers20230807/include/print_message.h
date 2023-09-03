/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_message.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 18:31:00 by yshimoma          #+#    #+#             */
/*   Updated: 2023/09/03 18:31:22 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINT_MESSAGE_H
# define PRINT_MESSAGE_H

# include "types.h"

void	print_message(
			t_main_thread *main_thread,
			int philo_id,
			char *message,
			pthread_mutex_t *mutex);

#endif