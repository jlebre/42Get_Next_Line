/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlebre <jlebre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 14:21:52 by jlebre            #+#    #+#             */
/*   Updated: 2022/04/21 13:56:24 by jlebre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*check_buf( char **saved, char **buf, size_t size)
{
	char	*tmp;
	char	*str;
}

static char	*store(char **saved, char **buf, size_t rd)
{
	char	*tmp;
	char	*str;

	str = NULL;
	if (rd <= 0)
	{
		if (rd == 0 && *saved)
		{
			str = (*saved);
			*saved = NULL;
		}
		return (str);
	}
	(*buf)[rd] = '\0';
	tmp = ft_strchr(*buf, '\n');
	if (!tmp)
	{
		tmp = ft_strjoin(*saved, *buf);
		if (*saved)
			free (*saved);
		*saved = tmp;
	}
	else
		str = check_buf(saved, buf, (tmp - *buf) + 1);
	return (str);
}

/*
A função é usada para guardar na string que vai ser retornada a

Inicia str = NULL, porque pode ser preciso retornar sem fazer 
			alterações, logo a função tem de estar iniciada
*/

static char	*check(char **saved, size_t size)
{
	char	*tmp;
}

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
		buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (!buf)
			return (0);
		while (rd > 0 || str == NULL)
		{
			rd = read(fd, buf, BUFFER_SIZE);
			str = store(&saved, &buf, rd);
		}
		free (buf);
		return (str);
	}
	str = check(&saved, (buf - saved) + 1);
	return (str);
}

/*
Inicia as variáveis:
	saved - onde fica guardado o "resto" depois de fazer a quebra de linha
	buf - buffer
	str - a linha a retornar
	rd - int

Faz os checks de segurança:
	se o BUFFER_SIZE for menor ou igual a zero
	se o file descriptor for inferior a zero
	ou se read(fd, 0, 0) == -1; 
		fd - verifica se o arquivo existe e é válido
		0 - não tem nada para ler
		0 - nada deve ser lido (0 bytes)
		o retorno normal, caso funcionasse seria 0
	caso algum dos casos se verifique retorna 0

Define:
	rd = 1
	str = NULL, porque pode ser preciso retornar sem fazer alterações, 
			logo a função tem de estar iniciada
	buf = 

*/

////////////////////////////////////////////////////////////////////////////////

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

////////////////////////////////////////////////////////////////////////////////

/*
READ
-1 Error
0 Linha lida (final do arquivo)
1 Linha lida (ainda tem algo para ler)
*/