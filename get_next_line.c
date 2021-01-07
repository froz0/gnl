/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatis <tmatis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 21:38:49 by tmatis            #+#    #+#             */
/*   Updated: 2021/01/07 21:07:29 by tmatis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_empty(char **line)
{
	char	*dst;

	dst = malloc(sizeof(char));
	if (!dst)
		return (-1);
	dst[0] = '\0';
	*line = dst;
	return (0);
}

int	ft_uninitchunk(t_chunk *chunk, int returnval)
{
	chunk->init = 0;
	chunk->len = 0;
	free(chunk->data);
	return (returnval);
}

int	ft_nextline(t_chunk *chunk, char **line, int pos)
{
	*line = ft_extractstr(chunk, pos);
	ft_rallocut(chunk, pos + 1);
	return (1);
}

int	ft_compute(t_chunk *chunk, char **line, int pos)
{
	if (chunk->len > 0)
	{
		if (pos == -1)
		{
			if (chunk->len > 0)
				*line = ft_extractstr(chunk, chunk->len);
			return (ft_uninitchunk(chunk, 0));
		}
		else
			return (ft_nextline(chunk, line, pos));
	}
	else
		return (ft_empty(line));
}

int	get_next_line(int fd, char **line)
{
	static t_chunk	chunk[256];
	char			buffer[BUFFER_SIZE];
	int				readed;
	int				pos;

	if (BUFFER_SIZE <= 0 || !line || fd < 0)
		return (-1);
	if (!chunk[fd].init)
		ft_initchunk(&chunk[fd]);
	pos = ft_getendl(&chunk[fd]);
	if (pos == -1)
		readed = read(fd, buffer, BUFFER_SIZE);
	while (pos == -1 && readed != 0)
	{
		if (readed == -1)
			return (ft_uninitchunk(&chunk[fd], -1));
		ft_rallocat(&chunk[fd], buffer, readed);
		pos = ft_getendl(&chunk[fd]);
		if (pos == -1)
			readed = read(fd, buffer, BUFFER_SIZE);
		else
			break ;
	}
	return (ft_compute(&chunk[fd], line, pos));
}
