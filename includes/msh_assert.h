/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_assert.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/24 20:31:52 by tmaluh            #+#    #+#             */
/*   Updated: 2020/04/27 20:14:48 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MSH_ASSERT_H
# define MSH_ASSERT_H

extern void __attribute__((noreturn))	msh_afail(const char *assertion,
	const char *file,
	const char *func,
	unsigned int line);

# define MSH_ASSERT(e) ((e)?((void)0):msh_afail(#e,__FILE__,__func__,__LINE__))

#endif
