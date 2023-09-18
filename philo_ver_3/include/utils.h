/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 14:41:57 by yshimoma          #+#    #+#             */
/*   Updated: 2023/09/07 22:18:12 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <stdatomic.h>

void	ft_putendl(char *str, atomic_bool *is_error);
void	ft_putstr_error(char *str, atomic_bool *is_error);
void	ft_putstr(char *str, atomic_bool *is_error);

#endif
