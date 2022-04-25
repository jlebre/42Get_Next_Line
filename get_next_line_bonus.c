/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlebre <jlebre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 17:19:10 by jlebre            #+#    #+#             */
/*   Updated: 2022/04/25 18:57:31 by jlebre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static char		buf[FOPEN_MAX][BUFFER_SIZE + 1];
	char			*line;
	int				rd;

	if (BUFFER_SIZE < 1 || fd < 0 || read(fd, 0, 0) == -1)
		return (0);
	line = NULL;
	rd = 1;
	while (rd > 0)
	{
		if (!buf[fd][0])
			rd = read(fd, buf[fd], BUFFER_SIZE);
		if (rd > 0)
			line = get_line(line, buf[fd]);
		if (check(buf[fd]))
			break ;
	}
	return (line);
}
/*
read(fd, buf. BUFFER_SIZE)
retorna o quanto ele conseguiu ler

vais sempre chamar a funcao get_line enquanto rd > 0
*/