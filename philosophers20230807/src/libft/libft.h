/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 18:44:45 by yshimoma          #+#    #+#             */
/*   Updated: 2023/08/20 18:56:53 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>

//ft_atoi.c
int		ft_atoi(const char *str);
//ft_isdigit.c
int		ft_isdigit(int c);
//ft_strlen.c
size_t	ft_strlen(const char *s);
//ft_putchar_fd.c
void	ft_putchar_fd(char c, int fd);
//ft_putstr_fd.c
void	ft_putstr_fd(char *s, int fd);

#endif
