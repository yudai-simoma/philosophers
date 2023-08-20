/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x_wrapper.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 21:49:46 by yshimoma          #+#    #+#             */
/*   Updated: 2023/08/20 18:57:35 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft/libft.h"

void	*ft_xmalloc(size_t size)
{
	void	*tmp;

	tmp = malloc (size);
	if (tmp == NULL)
		return (NULL);
	return (tmp);
}
