/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_thread_init.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 18:03:58 by yshimoma          #+#    #+#             */
/*   Updated: 2023/09/03 11:32:02 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_THREAD_INIT_H
# define MAIN_THREAD_INIT_H

# include <stdbool.h>
# include "types.h"

int	main_thread_init(
		int argc,
		char **argv,
		t_main_thread *main_thread,
		bool *is_error);

#endif
