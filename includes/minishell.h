/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/24 20:03:29 by tmaluh            #+#    #+#             */
/*   Updated: 2020/04/27 20:14:54 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# define _GNU_SOURCE

# include "libft.h"
# include "libftprintf.h"

# include "msh_structs.h"
# include "msh_assert.h"

# include <sys/types.h>
# include <sys/wait.h>
# include <dirent.h>
# include <pwd.h>

# ifdef __APPLE__
#  include <crt_externs.h>
#  define MSH_GET_ENVIRON *_NSGetEnviron()
# else
#  define MSH_GET_ENVIRON environ
# endif

extern char	**g_environ;

int
run_args(int argc, char *argv[]);

bool
procces_line(char *restrict line);
void
process_special_symbols(struct s_command *restrict cmd);
void
get_executable_full_path(char *restrict *restrict exe);

void
line_to_command(char *restrict line, struct s_command *restrict cmd);
void
command_free(struct s_command *restrict cmd);
enum e_builtin_status
command_tryrun_builtin(const struct s_command *restrict cmd);
int
command_run(const struct s_command *restrict cmd);

enum e_builtin_status
becho(const struct s_command *restrict cmd);
enum e_builtin_status
bcd(const struct s_command *restrict cmd);
enum e_builtin_status
benv(const struct s_command *restrict cmd);
enum e_builtin_status
bsetenv(const struct s_command *restrict cmd);
enum e_builtin_status
bunsetenv(const struct s_command *restrict cmd);
enum e_builtin_status
bexit(const struct s_command *restrict cmd);
enum e_builtin_status
bhelp(const struct s_command *restrict cmd);

#endif
