/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/24 20:23:40 by tmaluh            #+#    #+#             */
/*   Updated: 2020/04/27 15:52:14 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int main(int argc, char *argv[])
{
	char *restrict	line;
	int				ret;
	bool			stop;

	if (1 < argc)
		return run_args(argc - 1, argv + 1);
	stop = false;
	line = NULL;
	ret = 0;
	while (!stop)
	{
		ft_putstr_fd("$> ", STDERR_FILENO);
		if (!(ret = ft_gnl(STDIN_FILENO, &line)) || 0 > ret)
		{
			ft_putstr_fd("input error occured.\n", STDERR_FILENO);
			break ;
		}
		stop = procces_line(line);
		ft_strdel(&line);
	}
}
