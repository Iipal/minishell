/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/24 20:23:40 by tmaluh            #+#    #+#             */
/*   Updated: 2020/04/26 13:08:17 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int main(void)
{
	char *restrict	line;
	int				ret;
	bool			stop;

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
