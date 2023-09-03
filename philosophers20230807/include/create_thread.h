/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_thread.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 13:58:24 by yshimoma          #+#    #+#             */
/*   Updated: 2023/09/03 14:17:49 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CREATE_THREAD_H
# define CREATE_THREAD_H

# include <stdbool.h>
# include "types.h"

bool	create_thread(t_main_thread *main_thread, bool *is_error);

#endif