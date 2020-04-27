/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_assert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/24 20:31:22 by tmaluh            #+#    #+#             */
/*   Updated: 2020/04/27 20:25:00 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern __attribute__((noreturn)) void	msh_afail(const char *assertion,
	const char *file,
	const char *func,
	unsigned int line)
{
	ft_dprintf(STDERR_FILENO, "%s:%u: %s: Assertion failed `%s`\n",
		file, line, func, assertion);
	exit(EXIT_FAILURE);
}
