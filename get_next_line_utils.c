/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efelaous <efelaous@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 19:59:22 by efelaous          #+#    #+#             */
/*   Updated: 2024/03/27 06:49:23 by efelaous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	int		len;
	char	*ss;

	ss = (char *) s;
	len = 0;
	while (ss[len])
		len++;
	return (len);
}

char	*ft_strchr(const char *str, int c)
{
	char	*string;
	char	x;

	x = c;
	string = (char *) str;
	while (*string != x)
	{
		if (!*string && x != 0)
			return (NULL);
		string++;
	}
	if (*string || (!*string && !x))
		return (string);
	return (NULL);
}


size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dst_len;
	size_t	src_len;
	size_t	i;

	src_len = ft_strlen(src);
	if (dstsize == 0)
		return (src_len);
	dst_len = ft_strlen(dst);
	if (dst_len >= dstsize)
		return (src_len + dstsize);
	if (dstsize > 0)
	{
		i = 0;
		while (src[i] && (dst_len + i + 1) < dstsize)
		{
			dst[dst_len + i] = src[i];
			i++;
		}
		dst[dst_len + i] = '\0';
	}
	return (dst_len + src_len);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
    size_t len_s1;
    size_t len_s2;
    char *str;
    size_t i = 0, j = 0;

	len_s1 = 0;
	len_s2 = 0;
    if (s1)
        len_s1 = ft_strlen(s1);
    if (s2)
        len_s2 = ft_strlen(s2);
    str = (char *)malloc((len_s1 + len_s2 + 1) * sizeof(char));
    if (!str)
        return (NULL);
    if(s1)
        while(s1[i])
		{
			str[i] = s1[i];
			i++;
		}	
    if(s2)
        while(s2[j])
            str[i++] = s2[j++];
    str[i] = '\0';
    return (str);
}
