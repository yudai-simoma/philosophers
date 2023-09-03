/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_error.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 12:02:18 by yshimoma          #+#    #+#             */
/*   Updated: 2023/09/03 12:03:16 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IS_ERROR_H
# define IS_ERROR_H

# include <stdbool.h>

bool	is_error(int argc, char **argv, bool *is_program_error);

#endif
