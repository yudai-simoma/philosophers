/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 11:16:48 by yshimoma          #+#    #+#             */
/*   Updated: 2023/09/03 12:10:05 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stdlib.h>
#include "libft.h"
#include "ft_putstr_error.h"

/**
 * エラーの場合:true, エラー出ない場合:false
 */
bool	is_error(int argc, char **argv, bool *is_program_error)
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
