/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_error.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 11:45:25 by yshimoma          #+#    #+#             */
/*   Updated: 2023/09/03 17:03:29 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdbool.h>
#include "libft.h"

void	ft_putstr_error(char *str, bool *is_error)
{

	if (write(STDERR_FILENO, str, ft_strlen(str)) == -1)
		*is_error = true;
	if (write(STDERR_FILENO, NEWLINE_STR, 1) == -1)
		*is_error = true;
}
