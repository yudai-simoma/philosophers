/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 18:51:38 by yshimoma          #+#    #+#             */
/*   Updated: 2023/08/20 18:52:53 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

/*
** 文字列を出力する
*/
void	ft_putstr_fd(char *s, int fd)
{
	size_t	i;

	if (s == NULL)
		return ;
	if (fd < 0)
		return ;
	i = 0;
	while (s[i] != '\0')
	{
		write(fd, s, ft_strlen(s));
		i++;
	}
}
