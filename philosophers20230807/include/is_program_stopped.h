/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_program_stopped.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 15:40:53 by yshimoma          #+#    #+#             */
/*   Updated: 2023/09/03 18:03:11 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IS_PROGRAM_STOPPED_H
# define IS_PROGRAM_STOPPED_H

# include <pthread.h>
# include "types.h"

bool	is_program_stopped(t_main_thread *main_thread, pthread_mutex_t *mutex);

#endif
