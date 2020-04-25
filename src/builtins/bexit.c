/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bexit.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/25 20:54:36 by tmaluh            #+#    #+#             */
/*   Updated: 2020/04/25 21:33:19 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

enum e_builtin_status	bexit(const struct s_command *restrict cmd)
{
	(void)cmd;
	return (e_bstatus_exit);
}
