/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/25 11:02:51 by tmaluh            #+#    #+#             */
/*   Updated: 2020/04/25 13:05:16 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static inline bool
search_in_usrbin(DIR *restrict usrbin, char *restrict *restrict exe)
{
	struct dirent	*d;

	while ((d = readdir(usrbin)))
		if (!ft_strcmp(d->d_name, *exe))
			break ;
	if (d)
	{
		ft_strdel(&*exe);
		*exe = ft_strnew(sizeof(DFLT_EXE_PATH) + strlen(d->d_name));
		ft_strcpy(*exe, DFLT_EXE_PATH);
		ft_strcpy(*exe + (sizeof(DFLT_EXE_PATH) - 1), "/");
		ft_strcpy(*exe + sizeof(DFLT_EXE_PATH), d->d_name);
	}
	return !!d;
}

bool
get_executable_full_path(char *restrict *restrict exe)
{
	DIR	*restrict	usrbin;
	bool			ret;

	if (strchr(*exe, '/'))
		return (true);
	if (access(DFLT_EXE_PATH, F_OK | X_OK))
	{
		ft_dprintf(STDERR_FILENO,
			"You don't have permission to run '%s' from '" DFLT_EXE_PATH "'.\n",
			*exe);
		return (false);
	}
	if (!(usrbin = opendir(DFLT_EXE_PATH)))
	{
		ft_dprintf(STDERR_FILENO, "Can't open '" DFLT_EXE_PATH
			"' to get full path to executable.\n");
		return (false);
	}
	ret = search_in_usrbin(usrbin, exe);
	if (!ret)
		ft_dprintf(STDERR_FILENO, "Can't find '%s' in '" DFLT_EXE_PATH "'.\n",
			*exe);
	closedir(usrbin);
	return (ret);
}
