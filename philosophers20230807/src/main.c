/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 20:10:30 by yshimoma          #+#    #+#             */
/*   Updated: 2023/08/20 18:49:51 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "philo.h"
#include "utils.h"
#include "libft/libft.h"

static bool	_is_error(int argc, char **argv, bool *is_program_error)
{
	int		i;
	size_t	j;
	bool	is_error;

	is_error = false;
	if (argc != 5 && argc != 6)
		is_error = true;
	i = 1;
	while (i < argc)
	{
		if (ft_strlen(argv[i]) > 9)
			is_error = true;
		j = 0;
		while (argv[i][j] != '\0')
		{
			if (!ft_isdigit(argv[i][j]))
				is_error = true;
			j++;
		}
		i++;
	}
	if (is_error)
		ft_putstr_error("Invalid arguments.", is_program_error);
	return (is_error);
}

static void	_free_main_thread(t_main_thread *main_thread)
{
	free(main_thread);
}

//TODO:コンパイルエラーの解消
int	main(void)
{
	int		argc = 5;
	char		*argv[] = {"./philosophers", "10", "410", "200", "200"};
	t_main_thread	main_thread;

	main_thread.is_error = false;
	if (_is_error(argc, argv, &main_thread.is_error)
		|| main_thread_init(
			argc, argv, &main_thread, &main_thread.is_error) != 0)
		// || create_thread(main_thread))
	{
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
