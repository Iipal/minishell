/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/25 11:02:51 by tmaluh            #+#    #+#             */
/*   Updated: 2020/04/27 21:38:18 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static inline bool	parse_dir_for_executable(char *restrict *restrict exe,
	const char *restrict dirpath)
{
	DIR *restrict			dir;
	struct dirent *restrict	d;

	if (access(dirpath, F_OK | X_OK))
		return (false);
	if (!(dir = opendir(dirpath)))
		return (false);
	while ((d = readdir(dir)))
		if (!ft_strcmp(d->d_name, *exe))
			break ;
	if (d)
	{
		ft_strdel(&*exe);
		*exe = ft_strnew(ft_strlen(dirpath) + ft_strlen(d->d_name) + 1);
		ft_strcpy(*exe, dirpath);
		ft_strcpy(*exe + ft_strlen(dirpath), "/");
		ft_strcpy(*exe + ft_strlen(dirpath) + 1, d->d_name);
	}
	closedir(dir);
	return (!!d);
}

static inline bool	parse_envpath(char *restrict *restrict exe,
	char *restrict envpath)
{
	char *restrict	currpath;
	char *restrict	sep;
	char *restrict	endptr;
	size_t			pathlen;
	bool			ret;

	ret = false;
	sep = ft_strchr(envpath, ':');
	while (sep)
	{
		if (!(endptr = ft_strchr(sep + 1, ':')))
			pathlen = ft_strlen(sep + 1);
		else
			pathlen = (endptr - (sep + 1));
		MSH_ASSERT(currpath = ft_strndup(sep + 1, pathlen));
		ret = parse_dir_for_executable(exe, currpath);
		ft_strdel(&currpath);
		if (ret)
			break ;
		sep = endptr;
	}
	return (ret);
}

void				get_executable_full_path(char *restrict *restrict exe)
{
	char *restrict	envpath;

	if (!strchr(*exe, '/') && (envpath = getenv("PATH")))
	{
		if (!ft_strchr(envpath, ':'))
			parse_dir_for_executable(exe, envpath);
		else
			parse_envpath(exe, envpath);
	}
}
