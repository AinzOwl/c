/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efelaous <efelaous@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 18:06:04 by efelaous          #+#    #+#             */
/*   Updated: 2024/03/27 17:48:11 by efelaous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int find_nl(char *str)
{
	int	i;

	if (str == NULL)
		return (-1);
	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}
char *read_all(int fd, char *buff)
{
	int		bytes_read;
	char	str[BUFFER_SIZE + 1];
	char 	*temp;

	if (buff && find_nl(buff) > 0)
		return (buff);
	if (!buff)
    {
    	if (!(buff = malloc(1)))
			return (NULL);
        *buff = '\0'; 
    }
	bytes_read = 1;
	while (bytes_read > 0)
    {
		bytes_read = read(fd, str, BUFFER_SIZE);
		if (bytes_read < 0 || (bytes_read == 0 && !*buff))
			return (free(buff), buff = NULL, 
				str[0] = '\0', NULL);
		str[bytes_read] = '\0';
       	temp = ft_strjoin(buff, str);
		if (!temp)
			return (free(buff), buff = NULL, NULL);
		if (buff)
			free(buff);
		buff = temp;
        if (find_nl(str) > 0) break;
    }
	return (buff);
}


char *read_bf(char *buff, int *i)
{
	char	*rtn;

	if (!buff)
		return (NULL);
	while (buff[*i] != '\n' && buff[*i])
		(*i)++;
	if (buff[*i] == '\n')
		(*i)++;
	rtn = malloc((*i + 1) * sizeof(char));
	if (!rtn)
		return (NULL);
	*i = 0;
	while(buff[*i] != '\n' && buff[*i])
	{
		rtn[*i] = buff[*i];
		(*i)++;
	}
	if (buff[*i] == '\n')
		rtn[(*i)++] = '\n';
	rtn[*i] = '\0';

	return (rtn);
}

char *read_af(char *buff, int *i)
{
    char	*rtn;
	int		j;

	if (!buff)
		return (NULL);
	j = 0;
	rtn = malloc((ft_strlen(buff) + 1) * sizeof(char));
	if (!rtn) {
		return NULL;
	}
	while (buff[(*i) + j]) {
		rtn[j] = buff[(*i) + j];
		j++;
	}
	rtn[j] = '\0';
    free(buff);
    buff = rtn;
    return (rtn);
}


char *get_next_line(int fd)
{
	static char	*buffer;
	char		*nl;
	int			i;
	char *x;
	i = 0;
	if (fd < 0 || fd > OPEN_MAX || read(fd, "", 0) || BUFFER_SIZE > SIZE_MAX || BUFFER_SIZE <= 0)
		return (free(buffer),buffer = NULL, NULL);
	buffer = read_all(fd, buffer);
	 if (buffer == NULL)
        return (free(buffer), buffer = NULL, NULL);
	nl = read_bf(buffer, &i);
	if (!nl || *nl == 0) {
		free(nl);
		free(buffer);
        buffer = NULL;
        return (NULL);
    }
	x = read_af(buffer, &i);
    if (!x) {
		free(buffer);
		buffer = NULL;
        return (NULL);
    }
	buffer = x;
	return (nl);
}

