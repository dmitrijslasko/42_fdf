/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmlasko <dmlasko@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 16:35:43 by dmlasko           #+#    #+#             */
/*   Updated: 2024/08/13 19:03:59 by dmlasko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

void	*func(void *s, int calloc, size_t count, int size)
{
	char	*ptr;
	void	*memory;

	if (!calloc)
	{
		ptr = (char *)s;
		while (count--)
			*ptr++ = 0;
		return (NULL);
	}
	else
	{
		memory = malloc(count * size);
		if (!memory)
			return (NULL);
		ptr = (char *)memory;
		while (count--)
			*ptr++ = 0;
		if (memory == NULL)
		{
			free(memory);
			return (NULL);
		}
		return (memory);
	}
}

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;

	if (size != 0 && dest) 
	{
		i = 0;
		while (i < (size - 1) && src[i]) 
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	return (ft_strlen(src));
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	strlen;

	if (!s)
		return (NULL);
	strlen = ft_strlen(s);
	if (start >= strlen)
	{
		substr = malloc(1);
		if (!substr)
			return (NULL);
		substr[0] = '\0';
		return (substr);
	}
	if (start + len > strlen)
		len = strlen - start;
	substr = (char *)malloc(sizeof(char) * (len + 1));
	if (substr == NULL)
		return (NULL);
	ft_strlcpy(substr, s + start, len + 1);
	substr[len] = '\0';
	return (substr);
}

char	*ft_strjoin(char *s1, char const *s2)
{
	char	*concat_str;
	char	*ptr;

	concat_str = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (concat_str == NULL)
		return (NULL);
	ptr = concat_str;
	while (*s1)
		*ptr++ = *s1++;
	while (*s2)
		*ptr++ = *s2++;
	*ptr = '\0';
	return (concat_str);
}
