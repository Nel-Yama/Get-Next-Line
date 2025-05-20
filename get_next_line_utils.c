/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-yama <nel-yama@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 23:37:18 by nel-yama          #+#    #+#             */
/*   Updated: 2025/05/14 23:37:18 by nel-yama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/**
 * @brief - Modified version of strlen, it counts until nul terminator
 *		 or line feed '\n' (ascii decimal 10).
 * @param - str: pointer to string
 * @return - count of characters of that string till '\0' or '\n'
 *		 is found ('\n' is included in the count)
 */
size_t	ft_strlen(const char *str, int flag)
{
	const char	*ptr;

	ptr = str;
	while (*ptr)
	{
		if (flag != 0 && *ptr == 10)
			return (ptr - str + 1);
		ptr++;
	}
	return (ptr - str);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s;
	size_t	i;
	size_t	lens1;
	size_t	lens2;

	if (!s1 || !s2)
		return (NULL);
	lens1 = ft_strlen(s1, 1);
	lens2 = ft_strlen(s2, 1);
	s = malloc(lens1 + lens2 + 1);
	if (!s)
		return (NULL);
	i = 0;
	while (i < (lens1 + lens2))
	{
		if (i < lens1)
			s[i] = s1[i];
		else
			s[i] = s2[i - lens1];
		i++;
	}
	s[i] = '\0';
	return (s);
}

char	*ft_strdup(const char *s1)
{
	char	*s2;
	int		i;
	int		l;

	i = 0;
	l = ft_strlen(s1, 1);
	s2 = (char *)malloc((l + 1) * sizeof(char));
	if (!s2)
		return (NULL);
	while (s1[i] && s1[i] != 10)
	{
		s2[i] = s1[i];
		i++;
	}
	if (s1[i] == 10)
	{
		s2[i] = 10;
		i++;
	}
	s2[i] = '\0';
	return (s2);
}

char	*ft_strchr(const char *s, int c)
{
	char	*p;
	char	cast_c;

	if (!s)
		return (NULL);
	p = (char *)s;
	cast_c = (char)c;
	while (*p)
	{
		if (*p == cast_c)
			return (p);
		p++;
	}
	if (*p == cast_c)
		return (p);
	return (NULL);
}
