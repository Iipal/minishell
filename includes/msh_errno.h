/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_errno.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/24 20:12:39 by tmaluh            #+#    #+#             */
/*   Updated: 2020/04/24 20:32:05 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MSH_ERRNO_H
# define MSH_ERRNO_H

typedef enum	e_msh_errno
{
	MSH_ESUCCESS,
	MSH_EGNL,
} __attribute__((packed))				t_msh_errno;

#endif /* MSH_ERRNO_H */
