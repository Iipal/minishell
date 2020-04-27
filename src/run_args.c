/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_args.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/27 15:51:33 by tmaluh            #+#    #+#             */
/*   Updated: 2020/04/27 20:31:05 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	run_args(int argc, char *argv[])
{
	struct s_command		cmd;
	enum e_builtin_status	bst;

	ft_memset(&cmd, 0, sizeof(cmd));
	MSH_ASSERT(cmd.argv = ft_memalloc(sizeof(*cmd.argv) * argc));
	cmd.argc = ~0UL;
	while ((size_t)argc > ++cmd.argc)
		cmd.argv[cmd.argc] = ft_strdup(argv[cmd.argc]);
	process_special_symbols(&cmd);
	bst = command_tryrun_builtin(&cmd);
	if (e_bstatus_exit == bst)
		return (EXIT_SUCCESS);
	else if (e_bstatus_none == bst)
	{
		get_executable_full_path(&cmd.argv[0]);
		return (command_run(&cmd));
	}
	return (EXIT_FAILURE);
}
