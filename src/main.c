/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/24 20:23:40 by tmaluh            #+#    #+#             */
/*   Updated: 2020/04/24 21:00:51 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_msh_errno	g_msh_errno = MSH_ESUCCESS;

int main(void)
{
	char	*line;
	int		ret;
	bool	stop;

	stop = line;
	while (!stop) {
		ft_putstr_fd("$> ", STDERR_FILENO);
		ret = ft_gnl(STDIN_FILENO, &line);
		if (0 > ret)
			die("ft_gnl");
		ft_putendl(line);
		if (!ft_strcmp(line, "q"))
			stop = true;
		ft_strdel(&line);
	}
}
