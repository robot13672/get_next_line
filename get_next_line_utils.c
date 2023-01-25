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

char	*ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	if (c == '\0')
		return ((char *)&s[ft_strlen(s)]);
	while (s[i] != '\0')
	{
		if (s[i] == c)
			return ((char *)&s[i]);
		i++;
	}
	return (0);
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
	return (dst);
}

char	*ft_strjoin_check(char *s1, char *s2)
{
	char	*res;

	if (!s1)
		res = ft_strjoin("", s2);
	else
	{
		res = ft_strjoin(s1, s2);
		free(s1);
	}
	return (res);
}

size_t	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}
