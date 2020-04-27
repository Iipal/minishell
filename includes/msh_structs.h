/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_structs.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/24 22:48:38 by tmaluh            #+#    #+#             */
/*   Updated: 2020/04/27 20:15:14 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MSH_STRUCTS_H
# define MSH_STRUCTS_H

struct	s_command
{
	char	**argv;
	size_t	argc;
};

enum	e_builtin_status
{
	e_bstatus_none,
	e_bstatus_invalid,
	e_bstatus_valid,
	e_bstatus_exit,
} __attribute__((packed));

typedef enum e_builtin_status	(*t_fnptr_builtin)(const struct s_command*);

struct	s_builtin_dataset
{
	const char *restrict	bname;
	t_fnptr_builtin			bfnptr;
	size_t					max_argc;
};

#endif
