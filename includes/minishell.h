/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/24 20:03:29 by tmaluh            #+#    #+#             */
/*   Updated: 2020/04/24 21:03:45 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft.h"
# include "libftprintf.h"
# include "msh_errno.h"
# include "msh_assert.h"

extern t_msh_errno	g_msh_errno;

/*
** In any invalid situation - just die
*/
void __attribute__((noreturn))	die(const char *restrict reason);

#endif /* MINISHELL_H */
