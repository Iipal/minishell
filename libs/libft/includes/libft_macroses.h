/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_macroses.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/15 16:59:23 by tmaluh            #+#    #+#             */
/*   Updated: 2019/11/22 13:24:17 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_MACROSES_H
# define LIBFT_MACROSES_H

/*
**	ft_gnl reading buffer size.
*/
# define BUFF_SIZE 2048

/*
**	Simple macroses for work with bits fields
*/
# include "libft_bits_macroses.h"

# define ARR_SIZE(arr) (sizeof((arr)) / sizeof(*(arr)))

# define ABS(var) ((var) < 0) ? -(var) : (var)
# define MAX(a, b) (((a) > (b)) ? (a) : (b))

#endif
