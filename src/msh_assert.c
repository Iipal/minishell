/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_assert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/24 20:31:22 by tmaluh            #+#    #+#             */
/*   Updated: 2020/04/28 19:50:44 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern __attribute__((noreturn)) void	msh_afail(const char *assertion,
	const char *file,
	const char *func,
	unsigned int line)
{
	ft_putstr_fd(file, STDERR_FILENO);
	ft_putchar_fd(':', STDERR_FILENO);
	ft_putnbr_fd((long)line, STDERR_FILENO);
	ft_putstr_fd(": ", STDERR_FILENO);
	ft_putstr_fd(func, STDERR_FILENO);
	ft_putstr_fd(": Assertion failed '", STDERR_FILENO);
	ft_putstr_fd(assertion, STDERR_FILENO);
	ft_putstr_fd("'\n", STDERR_FILENO);
	exit(EXIT_FAILURE);
}
