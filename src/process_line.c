/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/25 11:04:01 by tmaluh            #+#    #+#             */
/*   Updated: 2020/04/28 19:56:49 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static inline void	trimm_extra_whitespaces(char *restrict *restrict line)
{
	const size_t	start = ft_strnblank(*line);
	char *restrict	copy;
	size_t			end;
	size_t			i;
	size_t			n;

	end = ft_strlen(*line);
	while (start < end && ft_isblank((*line)[end]))
		--end;
	if (!(*line)[start] || start == end)
		return ;
	MSH_ASSERT(copy = ft_strndup(*line + start, end - start));
	n = 0;
	i = 0;
	while (copy[++i])
		if (!ft_isblank(copy[i]) || copy[i - 1])
			copy[++n] = copy[i];
	copy[++n] = '\0';
	ft_strdel(line);
	MSH_ASSERT(*line = ft_strndup(copy, n));
	ft_strdel(&copy);
}

bool				procces_line(char *restrict *restrict line)
{
	struct s_command		cmd;
	bool					ret;
	enum e_builtin_status	bst;

	trimm_extra_whitespaces(line);
	if (!ft_strlen(*line))
	{
		ft_putchar_fd('\n', STDERR_FILENO);
		return (false);
	}
	if ((ret = !ft_strcmp(*line, "q")))
		return (ret);
	ft_memset(&cmd, 0, sizeof(cmd));
	line_to_command(*line, &cmd);
	process_special_symbols(&cmd);
	bst = command_tryrun_builtin(&cmd);
	if (e_bstatus_exit == bst)
		ret = true;
	else if (e_bstatus_none == bst)
	{
		get_executable_full_path(&cmd.argv[0]);
		command_run(&cmd);
	}
	command_free(&cmd);
	return (ret);
}
