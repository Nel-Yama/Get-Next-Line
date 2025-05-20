/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-yama <nel-yama@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 23:33:07 by nel-yama          #+#    #+#             */
/*   Updated: 2025/05/14 23:33:07 by nel-yama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# else
#  if BUFFER_SIZE > 100000
#   undef BUFFER_SIZE
#   define BUFFER_SIZE 1024
#  endif
# endif

# include <unistd.h>
# include <stdlib.h>
# include "get_next_line.h"

char	*ft_strchr(const char *s, int c);
size_t	ft_strlen(const char *str, int flag);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strdup(const char *s1);
void	*ft_memmove(void *dst, const void *src, size_t len);
char	*ft_strchr(const char *s, int c);
char	*get_next_line(int fd);

#endif
