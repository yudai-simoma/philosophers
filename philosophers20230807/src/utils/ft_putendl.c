/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 11:45:48 by yshimoma          #+#    #+#             */
/*   Updated: 2023/09/04 14:56:42 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdbool.h>
#include "config.h"
#include "utils.h"

void	ft_putendl(char *str, bool *is_error)
{
	ft_putstr(str, is_error);
	if (write(STDOUT_FILENO, NEWLINE_STR, 1) == -1)
		*is_error = true;
}
