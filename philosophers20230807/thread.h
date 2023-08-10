/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 18:13:29 by yshimoma          #+#    #+#             */
/*   Updated: 2023/08/10 18:14:04 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef THREAD_H
# define THREAD_H

//thread.c
void	*ft_philo_thread(void *v_philo_group);
bool	ft_is_dead_all(t_philosophers *philosophers);
void	ft_create_thread(t_philosophers *philosophers);

#endif
