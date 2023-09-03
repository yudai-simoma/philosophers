/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 20:10:30 by yshimoma          #+#    #+#             */
/*   Updated: 2023/09/03 12:28:47 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "is_error.h"
#include "main_thread_init.h"
#include "ft_putstr_error.h"

static void	_free_main_thread(t_main_thread *main_thread)
{
	free(main_thread->philo_thread);
}

int	main(void)
{
	int		argc = 5;
	char		*argv[] = {"./philosophers", "10", "410", "200", "200"};
	t_main_thread	main_thread;

	main_thread.is_error = false;
	if (is_error(argc, argv, &main_thread.is_error)
		|| main_thread_init(
			argc, argv, &main_thread, &main_thread.is_error) != 0
		|| create_thread(main_thread))
	{
		_free_main_thread(&main_thread);
		ft_putstr_error("Error", &main_thread.is_error);
		if (main_thread.is_error)
			return (1);
		else
			return (0);
	}
	_free_main_thread(&main_thread);
	if (main_thread.is_error)
		return (1);
	else
		return (0);
}
