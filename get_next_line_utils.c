/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhristi <ikhristi@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 15:44:02 by ikhristi          #+#    #+#             */
/*   Updated: 2023/01/22 15:44:02 by ikhristi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	while ((*s != '\0') && (*s != c))
	{
		s++;
	}
	if (*s == c)
	{
		return ((char *)s);
	}
	return (NULL);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*dst;
	int		length1;
	int		length2;
	int		i;
	int		j;

	length1 = ft_strlen(s1);
	length2 = ft_strlen(s2);
	i = 0;
	j = 0;
	dst = (char *)malloc(sizeof(char) * (length1 + length2 + 1));
	if (!dst)
		return (NULL);
	while (s1[i] != 0)
		dst[j++] = s1[i++];
	i = 0;
	while (s2[i] != 0)
		dst[j++] = s2[i++];
	dst[j] = '\0';
	free(s1);
	free(s2);
	return (dst);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}
