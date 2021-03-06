/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_list.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 13:14:44 by tmaluh            #+#    #+#             */
/*   Updated: 2020/04/24 20:07:44 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_LIST_H
# define LIBFT_LIST_H

# include "libft_mem.h"

struct	s_list
{
	void *restrict			data;
	size_t					data_size;
	struct s_list *restrict	next;
};

typedef struct s_list	t_list;

t_list
*ft_lstnew(void const *restrict data, const size_t data_size);

void
ft_lstadd(t_list *restrict *restrict alist, t_list *restrict new);

void
ft_lstiter(t_list *list, void (*f)(t_list*));
t_list
*ft_lstmap(t_list *list, t_list *(*f)(t_list*));

void
ft_lstdelone(t_list *restrict *restrict alist, void (*del)(void*, size_t));
void
ft_lstdel(t_list *restrict *restrict alist, void (*del)(void*, size_t));

#endif
