/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_assert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/24 20:31:22 by tmaluh            #+#    #+#             */
/*   Updated: 2020/04/24 22:55:38 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern void __attribute__((noreturn))	msh_afail(const char *assertion,
	const char *file,
	const char *func,
	unsigned int line)
{
	ft_dprintf(STDERR_FILENO, "%s:%u: %s: Assertion failed `%s`\n",
		file, line, func, assertion);
	exit(EXIT_FAILURE);
}
