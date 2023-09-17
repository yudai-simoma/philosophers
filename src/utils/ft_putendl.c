/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 11:45:48 by yshimoma          #+#    #+#             */
/*   Updated: 2023/09/07 22:21:26 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdbool.h>
#include <stdatomic.h>
#include "config.h"
#include "utils.h"

void	ft_putendl(char *str, atomic_bool *is_error)
{
	ft_putstr(str, is_error);
	if (write(STDOUT_FILENO, NEWLINE_STR, 1) == -1)
		*is_error = true;
}
