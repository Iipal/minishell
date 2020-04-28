/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bcd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/25 20:54:36 by tmaluh            #+#    #+#             */
/*   Updated: 2020/04/28 19:55:38 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

enum e_builtin_status	bcd(const struct s_command *restrict cmd)
{
	const char *restrict	chdir_path = cmd->argv[1];

	if (!chdir_path && !(chdir_path = getenv("HOME")))
		chdir_path = getpwuid(getuid())->pw_dir;
	if (-1 == chdir(chdir_path))
	{
		ft_putstr_fd("cd: no such file or directory: ", STDERR_FILENO);
		ft_putendl_fd(chdir_path, STDERR_FILENO);
		return (e_bstatus_invalid);
	}
	return (e_bstatus_valid);
}
