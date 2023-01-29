/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhristi <ikhristi@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 01:21:57 by ikhristi          #+#    #+#             */
/*   Updated: 2023/01/29 01:26:51 by ikhristi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <stdio.h>
# include <fcntl.h>

//get_next_line.c
char	*get_next_line(int fd);
char	*read_line(int fd, char *save);
char	*ft_get_line(char *save);
char	*ft_save(char *save);
//get_next_line_utils.c
size_t	ft_strlen(char *str);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strchr(char *s, int c);
char	*ft_strjoin_check(char *s1, char *s2);

#endif
