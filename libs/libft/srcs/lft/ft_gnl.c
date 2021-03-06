/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gnl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/03 12:31:02 by tmaluh            #+#    #+#             */
/*   Updated: 2020/04/24 21:20:32 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	catline_recursive(int fd, ssize_t nbytes,
						char *restrict *restrict data,
						char *restrict *restrict line)
{
	char	*temp_nl;
	size_t	to_nl;

	to_nl = ~0UL;
	while (data[fd][++to_nl] && '\n' != data[fd][to_nl])
		;
	if ('\n' == data[fd][to_nl])
	{
		*line = ft_strndup(data[fd], to_nl);
		temp_nl = ft_strdup(data[fd] + ++to_nl);
		free(data[fd]);
		data[fd] = temp_nl;
		if (!data[fd][0])
			ft_strdel(&data[fd]);
	}
	else if (!data[fd][to_nl])
	{
		if (BUFF_SIZE == nbytes)
			ft_gnl(fd, line);
		*line = ft_strdup(data[fd]);
		ft_strdel(&data[fd]);
	}
	return (1);
}

int			ft_gnl(int fd, char *restrict *restrict line)
{
	static char	*data[255];
	char		*temp;
	char		buff[BUFF_SIZE + 1];
	ssize_t		nbytes;

	if (0 > fd)
		return (-1);
	while (0 < (nbytes = read(fd, buff, BUFF_SIZE)))
	{
		buff[nbytes] = '\0';
		if (!data[fd])
			data[fd] = ft_strnew(0);
		temp = ft_strjoin(data[fd], buff);
		ft_strdel(&data[fd]);
		data[fd] = temp;
		if (ft_strchr(buff, '\n'))
			break ;
	}
	if (0 > nbytes)
		return (-1);
	if (!nbytes && (!data[fd] || !data[fd][0]))
		return (0);
	return (catline_recursive(fd, nbytes, data, line));
}
