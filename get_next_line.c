/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlebre <jlebre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 14:21:52 by jlebre            #+#    #+#             */
/*   Updated: 2022/04/20 19:02:30 by jlebre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*store(char **str, char **buf, size_t rd)
{
	char	*tmp;
	char	*ret;

	ret = NULL;
	if (rd <= 0)
	{
		if (rd == 0 && *str)
		{
			ret = (*str);
			*str = NULL;
		}
		return (ret);
	}
}
//Guardar no saved

char	*get_next_line(int fd)
{
	static char	*saved;
	char		*buf;
	char		*str;
	size_t		rd;

	if (BUFFER_SIZE <= 0 || fd < 0 || (read(fd, 0, 0) == -1))
		return (0);
	rd = 1;
	str = NULL;
	buf = ft_strchr(saved, '\n');
	if (!buf)
	{
		buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE +1));
		if (!buf)
			return (0);
		while (rd > 0 || str == NULL)
		{
			rd = read(fd, buf, BUFFER_SIZE);
			str = store(&saved, &buf, rd);
		}
	}
}

/*	
buf[rd] = '\0';
			str = ft_strjoin(save[fd], buf);
			free (save[fd]);
			save[fd] = str;
			if (ft_strchr(rd, '\n') == 1)
				break ;
*/

//static variables iniciam automaticamente para 0.
// read(int fd, void *buf, size_t nbytes)

/*

verify input senao nulo

if save has not a new line
	malloc buf
	while (r)
	{
		read  		0, -1
		if newline
			save + tmp
			por o que esta a mais no save
		else
			strjoin *tmp + buf
		free buf
	}

else if save tem cenas
	nao precia malloc
	pegas nas cenas que estao no save
	e separas onde houver \n
	
*/