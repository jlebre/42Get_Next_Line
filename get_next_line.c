/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlebre <jlebre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 17:19:10 by jlebre            #+#    #+#             */
/*   Updated: 2022/04/25 18:31:09 by jlebre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char		buf[BUFFER_SIZE + 1];
	char			*line;
	int				rd;

	if (BUFFER_SIZE <= 0 || fd < 0 || (read(fd, 0, 0) == -1))
		return (0);
	line = 0;
	rd = 1;
	while (rd > 0)
	{
		if (!*buf)
			rd = read(fd, buf, BUFFER_SIZE);
		if (rd > 0)
			line = get_line(line, buf);
		if (check(buf))
			break ;
	}
	return (line);
}

/*
read(fd, buf. BUFFER_SIZE)
retorna o quanto ele conseguiu ler

vais sempre chamar a funcao get_line enquanto rd > 0
*/