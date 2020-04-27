/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spec_symbols.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/26 11:46:14 by tmaluh            #+#    #+#             */
/*   Updated: 2020/04/27 22:50:12 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static inline void		paste_str_at_pos(char *restrict *restrict arg,
	char *restrict value,
	char *restrict argpos,
	size_t argpos_len)
{
	const size_t	value_len = ft_strlen(value);
	char *restrict	newarg;
	size_t			newlen;

	newlen = ft_strlen(*arg) +
		(argpos_len >= value_len ? 0 : (value_len - argpos_len));
	MSH_ASSERT(newarg = ft_memalloc(sizeof(*newarg) * newlen));
	ft_strncpy(newarg, *arg, argpos - *arg);
	ft_strncpy(newarg + (argpos - *arg), value, value_len);
	ft_strcpy(newarg + (argpos - *arg) + value_len, argpos + argpos_len + 1);
	ft_strdel(&*arg);
	*arg = newarg;
}

static inline size_t	get_envvar_delimlen(char *restrict str)
{
	size_t	i;

	if (ft_strchr(str, ' '))
		return (ft_strlen(str));
	i = 0UL;
	while (str[i])
		if (ft_isalpha(str[i]))
			++i;
		else
			break ;
	return (i);
}

static inline void		process_envvar(char *restrict *restrict arg)
{
	char *restrict	spec;
	char *restrict	envvar;
	char *restrict	envvar_value;
	size_t			len;

	if (!(spec = ft_strchr(*arg, '$')))
		return ;
	len = get_envvar_delimlen(spec + 1);
	MSH_ASSERT(envvar = ft_strndup(spec + 1, len));
	if ((envvar_value = getenv(envvar)))
	{
		paste_str_at_pos(arg, envvar_value, spec, len);
		free(envvar);
		process_envvar(arg);
	}
	else
		free(envvar);
}

static inline void		process_tilde(char *restrict *restrict arg)
{
	char *restrict	spec;

	if (!(spec = ft_strchr(*arg, '~')))
		return ;
	paste_str_at_pos(arg, getpwuid(getuid())->pw_dir, spec, 0);
	process_tilde(arg);
}

void					process_special_symbols(struct s_command *restrict cmd)
{
	size_t	i;

	i = 0UL;
	while (cmd->argc > ++i)
	{
		process_envvar(&cmd->argv[i]);
		process_tilde(&cmd->argv[i]);
	}
}
