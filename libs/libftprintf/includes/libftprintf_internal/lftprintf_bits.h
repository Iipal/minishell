/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lftprintf_bits.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 13:20:38 by tmaluh            #+#    #+#             */
/*   Updated: 2020/03/19 21:18:11 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LFTPRINTF_BITS_MASKS_H
# define LFTPRINTF_BITS_MASKS_H

# ifndef LIBFTPRINTF_INTERNAL_H
#  error "include only libftprintf.h"
# endif


# define TO_N_BIT(n) (1 << (n))

# define SET_BIT(mask, bit) ((mask) |= (bit))
# define TOGGLE_BIT(mask, bit) ((mask) ^= (bit))
# define UNSET_BIT(mask, bit) ((mask) &= ~(bit))

# define IS_BIT(mask, bit) (((mask) & (bit)) == (bit))

/*
** g_flag_spec_mask bit masks.
*/
# define PF_BIT_SPEC_MINUS (1 << 0)
# define PF_BIT_SPEC_DOT   (1 << 1)

/*
** g_flag_type_mask bit masks.
*/
# define PF_BIT_TYPE_L     (1 << 0)
# define PF_BIT_TYPE_H     (1 << 1)
# define PF_BIT_TYPE_J     (1 << 2)
# define PF_BIT_TYPE_T     (1 << 3)
# define PF_BIT_TYPE_Z     (1 << 4)
# define PF_BIT_TYPE_HH    (1 << 5)
# define PF_BIT_TYPE_LL    (1 << 6)

#endif
