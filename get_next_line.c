/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhristi <ikhristi@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 15:43:58 by ikhristi          #+#    #+#             */
/*   Updated: 2023/01/22 15:43:58 by ikhristi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*back_shift(char *save, size_t i)
{
	save += i;
	save += 2;
	return (save);
}

char	*get_line(char *save)
{
	char	*line;
	int		i;
	int 	count;

	count = 0;
	i = 0;
	while(save[count] && save[count] != '\n')
		count++;
	line = malloc(count + 1);
	if(!line)
		return (NULL);
	line[count] = 0;
	while(i < count)
		line[i++] = *(save++);
	return (line);
}

char	*read_line(int fd, char *save)
{
	int		read_bytes;
	char	*buffer;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return(NULL);
	read_bytes = 1;
	while(ft_strchr(save, '\n') && read_bytes != 0)
	{
		read_bytes = read(fd, buffer, BUFFER_SIZE);
		if(read_bytes == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[read_bytes] = '\0';
		ft_strjoin(save, buffer);
	}
	free(buffer);
	return (save);
}

char	*get_next_line(int fd)
{
	static char	*save;
	char		*line;

	if(fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (read(fd, 0, 0) < 0)
	{
		if (save)
			free(save);
		save = NULL;
		return (NULL);
	}
	save = read_line(fd, save);
	if(save)
		line = get_line(save);
	save = back_shift(save, ft_strlen(line));
	return (line);
}

int main()
{
	int	fd = 0;
	char *str = get_next_line(fd);

	printf("%s", str);
}