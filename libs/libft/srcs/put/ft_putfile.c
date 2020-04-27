/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putfile.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 12:21:35 by tmaluh            #+#    #+#             */
/*   Updated: 2020/04/27 21:50:33 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

bool	ft_putfile(const char *restrict filename)
{
	const int	fd = open(filename, O_RDONLY);
	char		*temp;

	if (0 > fd)
		return (false);
	temp = NULL;
	while (0 < ft_gnl(fd, &temp))
	{
		ft_putendl(temp);
		ft_strdel(&temp);
	}
	close(fd);
	return (true);
}
