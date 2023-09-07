/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 11:44:50 by yshimoma          #+#    #+#             */
/*   Updated: 2023/09/07 22:21:42 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdbool.h>
#include <stdatomic.h>
#include "libft.h"

void	ft_putstr(char *str, atomic_bool *is_error)
{
	if (write(STDOUT_FILENO, str, ft_strlen(str)) == -1)
		*is_error = true;
}
