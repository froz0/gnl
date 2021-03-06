/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatis <tmatis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 19:42:42 by tmatis            #+#    #+#             */
/*   Updated: 2021/01/02 16:49:32 by tmatis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H

# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# define BUFFER_SIZE 2048
typedef struct s_chunk
{
	char	*data;
	int		len;
	int		init;
}	t_chunk;
t_chunk			*ft_rallocat(t_chunk *chunk, char *data, int len);
t_chunk			*ft_rallocut(t_chunk *chunk, int start);
char			*ft_extractstr(t_chunk *chunk, int size);
void			ft_initchunk(t_chunk *chunk);
int				ft_getendl(t_chunk *chunk);
int				get_next_line(int fd, char **line);
#endif
