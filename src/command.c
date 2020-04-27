/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/25 11:04:26 by tmaluh            #+#    #+#             */
/*   Updated: 2020/04/27 20:11:21 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static const struct s_builtin_dataset	g_bds[] = {
	{"echo", becho, ~0UL},
	{"cd", bcd, 2},
	{"env", benv, ~0UL},
	{"setenv", bsetenv, 3},
	{"unsetenv", bunsetenv, 2},
	{"exit", bexit, 1},
	{"help", bhelp, 1},
	{NULL, NULL, 0}
};

void
command_free(struct s_command *restrict cmd)
{
	size_t	i;

	i = ~0UL;
	if (cmd->argc)
	{
		while (cmd->argc >= ++i)
			ft_strdel(&cmd->argv[i]);
		free(cmd->argv);
		cmd->argv = NULL;
	}
}

enum e_builtin_status
command_tryrun_builtin(const struct s_command *restrict cmd)
{
	size_t					i;
	enum e_builtin_status	bst;

	i = ~0UL;
	bst = e_bstatus_valid;
	while (g_bds[++i].bname)
		if (!ft_strcmp(g_bds[i].bname, cmd->argv[0]))
			break ;
	if (!g_bds[i].bname)
		bst = e_bstatus_none;
	else
	{
		if (g_bds[i].max_argc < cmd->argc)
		{
			ft_dprintf(STDERR_FILENO, "%s: too many arguments\n",
				g_bds[i].bname);
			bst = e_bstatus_invalid;
		}
		else
			bst = g_bds[i].bfnptr(cmd);
	}
	return (bst);
}

int
command_run(const struct s_command *restrict cmd)
{
	pid_t	child;

	child = fork();
	if (!child)
	{
		execve(cmd->argv[0], cmd->argv, g_environ);
		ft_dprintf(STDERR_FILENO, "minishell: command not found: %s\n", cmd->argv[0]);
		return (EXIT_FAILURE);
	}
	else
	{
		waitpid(child, NULL, WUNTRACED);
		return (EXIT_SUCCESS);
	}
}

void
line_to_command(char *restrict line, struct s_command *restrict cmd)
{
	const char	*delim = ft_strchr(line, ' ');
	char		*endptr;
	size_t		duplen;
	size_t		i;

	cmd->argc = 1;
	while (delim && ++cmd->argc)
		delim = ft_strchr(delim + 1, ' ');
	MSH_ASSERT(cmd->argv = ft_memalloc(sizeof(*(cmd->argv)) * (cmd->argc + 1)));
	if (1 == cmd->argc)
		MSH_ASSERT(cmd->argv[0] = ft_strdup(line));
	else
	{
		i = 0UL;
		delim = ft_strchr(line, ' ');
		cmd->argv[0] = ft_strndup(line, delim - line);
		while (delim && cmd->argc > ++i)
		{
			duplen = (!(endptr = ft_strchr(++delim, ' ')))
				? ft_strlen(delim) : (endptr - delim);
			MSH_ASSERT(cmd->argv[i] = ft_strndup(delim, duplen));
			delim = endptr;
		}
	}
}
